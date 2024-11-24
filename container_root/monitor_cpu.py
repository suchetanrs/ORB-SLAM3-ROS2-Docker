import psutil
import time
import argparse
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

def get_process_by_name(name):
    """Retrieve the first process matching the given name."""
    for proc in psutil.process_iter(['name']):
        if proc.info['name'] == name:
            return proc
    raise ValueError(f"No process found with name: {name}")

def get_process_by_pid(pid):
    """Retrieve a process by PID."""
    try:
        return psutil.Process(pid)
    except psutil.NoSuchProcess:
        raise ValueError(f"No process found with PID: {pid}")

def monitor_cpu_usage(process):
    """Generator yielding CPU usage of a process."""
    while True:
        try:
            yield process.cpu_percent(interval=0.5) / psutil.cpu_count()
        except (psutil.NoSuchProcess, psutil.AccessDenied):
            print("Process terminated or access denied.")
            break

def live_plot(process_name=None, pid=None):
    """Live plot the CPU usage of a given process."""
    if process_name:
        process = get_process_by_name(process_name)
    elif pid:
        process = get_process_by_pid(pid)
    else:
        raise ValueError("Either process name or PID must be provided.")

    fig, ax = plt.subplots()
    ax.set_title(f"CPU Usage for Process: {process_name or pid}")
    ax.set_xlabel("Time (seconds)")
    ax.set_ylabel("CPU Usage (%)")
    ax.set_ylim(0, 100)
    times, cpu_loads = [], []

    def update(frame):
        """Update the live plot."""
        try:
            cpu_load = next(monitor)
            times.append(time.time() - start_time)
            cpu_loads.append(cpu_load)
            ax.clear()
            ax.plot(times, cpu_loads, label="CPU Usage (%)")
            ax.set_title(f"CPU Usage for Process: {process_name or pid}")
            ax.set_xlabel("Time (seconds)")
            ax.set_ylabel("CPU Usage (%)")
            ax.set_ylim(0, 100)
            ax.legend()
        except StopIteration:
            return

    monitor = monitor_cpu_usage(process)
    start_time = time.time()
    ani = FuncAnimation(fig, update, interval=500)
    plt.show()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Monitor CPU usage of a process.")
    parser.add_argument("-n", "--name", help="Process name to monitor.")
    parser.add_argument("-p", "--pid", type=int, help="Process PID to monitor.")
    args = parser.parse_args()

    if not args.name and not args.pid:
        parser.error("You must provide either a process name (-n) or a PID (-p).")

    try:
        live_plot(process_name=args.name, pid=args.pid)
    except ValueError as e:
        print(f"Error: {e}")
