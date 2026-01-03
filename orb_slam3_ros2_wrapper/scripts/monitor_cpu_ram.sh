#!/usr/bin/env bash
set -euo pipefail

usage() {
  cat <<'EOF'
Usage:
  ./script.sh --name <process_name> [--hz <rate>] [--interval <seconds>]

Output (single line, refreshed):
  Cpu(%) <number>, Ram(MB) <number>

Examples:
  ./script.sh --name rgbd --hz 2
  ./script.sh --name rgbd --interval 0.5
EOF
}

NAME=""
HZ=""
INTERVAL=""

while [[ $# -gt 0 ]]; do
  case "$1" in
    --name)     NAME="${2:-}"; shift 2;;
    --hz)       HZ="${2:-}"; shift 2;;
    --interval) INTERVAL="${2:-}"; shift 2;;
    -h|--help)  usage; exit 0;;
    *) echo "Error: Unknown argument: $1"; usage; exit 2;;
  esac
done

[[ -n "$NAME" ]] || { echo "Error: --name is required"; usage; exit 2; }
command -v ps >/dev/null 2>&1 || { echo "Error: 'ps' not found"; exit 1; }

# Determine sleep seconds (supports fractional)
sleep_s="1"
if [[ -n "$INTERVAL" ]]; then
  sleep_s="$INTERVAL"
elif [[ -n "$HZ" ]]; then
  sleep_s="$(awk -v hz="$HZ" 'BEGIN{ if(hz<=0) exit 1; printf "%.6f", 1.0/hz }')" \
    || { echo "Error: --hz must be > 0"; exit 2; }
fi

# Validate sleep_s
awk -v s="$sleep_s" 'BEGIN{ exit !(s ~ /^[0-9]+(\.[0-9]+)?$/ && s > 0) }' \
  || { echo "Error: interval must be a positive number (got: $sleep_s)"; exit 2; }

while true; do
  # Sum %CPU and RSS(KB) across all matching processes
  # ps -C matches the "comm" (process name) exactly.
  read -r cpu_sum rss_kb_sum < <(
    ps -C "$NAME" -o pcpu=,rss= 2>/dev/null \
    | awk '{cpu+=$1; rss+=$2} END{printf "%.2f %d", (cpu+0), (rss+0)}'
  ) || true

  ram_mb="$(awk -v kb="${rss_kb_sum:-0}" 'BEGIN{printf "%.2f", kb/1024}')"

  printf "Process name: %s Cpu(%%) %.2f, Ram(MB) %s\n" "$NAME" "${cpu_sum:-0}" "$ram_mb"
  sleep "$sleep_s"
done
