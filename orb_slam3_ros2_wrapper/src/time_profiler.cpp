#include <orb_slam3_ros2_wrapper/time_profiler.hpp>

namespace ORB_SLAM3_Wrapper
{
    TimeProfiler *TimeProfiler::instancePtr = nullptr;
    
    TimeProfiler::TimeProfiler()
    {
        auto now = std::chrono::system_clock::now();
        auto nowTime = std::chrono::system_clock::to_time_t(now);
        auto nowMs = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) % 1000;
    }

    void TimeProfiler::startEvent(const std::string &key)
    {
        std::lock_guard<std::mutex> lock(mapMutex);
        auto startTime = std::chrono::high_resolution_clock::now();
        startTimes[key] = startTime;
    }

    double TimeProfiler::endEvent(const std::string &key)
    {
        auto endTime = std::chrono::high_resolution_clock::now();
        std::lock_guard<std::mutex> lock(mapMutex);
        if (startTimes.find(key) != startTimes.end())
        {
            auto startTime = startTimes[key];
            std::chrono::duration<double> duration = endTime - startTime;
            std::cout << key << ": " << duration.count() << " seconds." << std::endl;

            startTimes.erase(key);
            return duration.count();
        }
        else
        {
            std::cout << "Event \"" << key << "\" was not started." << std::endl;
        }
        return -1.0;
    }

    bool TimeProfiler::hasEventStarted(const std::string &key)
    {
        std::lock_guard<std::mutex> lock(mapMutex);
        return startTimes.find(key) != startTimes.end();
    }

} // namespace isds_manager
