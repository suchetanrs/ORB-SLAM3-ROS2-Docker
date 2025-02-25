#pragma once

#include <iostream>
#include <unordered_map>
#include <chrono>
#include <string>
#include <fstream>
#include <thread>
#include <mutex>
#include <random>
#include <ctime>

#include <iomanip>
#include <sstream>
#include <ctime>

namespace ORB_SLAM3_Wrapper
{
    class TimeProfiler
    {
    public:
        TimeProfiler(const TimeProfiler &obj) = delete;

        void startEvent(const std::string &key);

        double endEvent(const std::string &key);

        bool hasEventStarted(const std::string &key);

        // Static method to get the Singleton instance
        // TODO: this baseFileName has to be a const global variable and should not be a part of getInstance()
        static TimeProfiler *getInstance()
        {
            if (instancePtr == nullptr)
            {
                instancePtr = new TimeProfiler();
            }
            return instancePtr;
        }

    private:
        std::unordered_map<std::string, std::chrono::high_resolution_clock::time_point> startTimes;
        std::mutex mapMutex;

        static TimeProfiler *instancePtr;
        TimeProfiler();
    };

    class ScopedEvent
    {
    public:
        ScopedEvent(const std::string &key, TimeProfiler *event_logger_) : key_(key), event_logger_(event_logger_)
        {
            event_logger_->startEvent(key_);
        }

        ~ScopedEvent()
        {
            if (event_logger_->hasEventStarted(key_))
                event_logger_->endEvent(key_);
        }

    private:
        std::string key_;
        TimeProfiler *event_logger_;
    };

} // namespace isds_manager
