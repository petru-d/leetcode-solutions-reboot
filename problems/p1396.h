#pragma once
#include <string>
#include <unordered_map>

namespace p1396
{
    struct pair_hash
    {
        template <class T1, class T2> std::size_t operator()(const std::pair<T1, T2>& pair) const
        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    class UndergroundSystem
    {
      public:
        UndergroundSystem()
        {
        }

        void checkIn(int id, std::string stationName, int t)
        {
            _startedTrips[id] = {stationName, t};
        }

        void checkOut(int id, std::string stationName, int t)
        {
            auto startPos = _startedTrips.find(id);

            const auto& startStation = startPos->second.first;
            auto startTime = startPos->second.second;

            auto averagePos = _tripAverages.find({startStation, stationName});
            if (averagePos == _tripAverages.end())
            {
                _tripAverages[{startStation, stationName}] = {t - startTime, 1};
            }
            else
            {
                auto oldAvg = averagePos->second.first;
                auto oldCount = averagePos->second.second;

                auto newAvg = ((oldAvg * oldCount) + (t - startTime)) / (oldCount + 1);
                averagePos->second = {newAvg, oldCount + 1};
            }

            _startedTrips.erase(startPos);
        }

        double getAverageTime(std::string startStation, std::string endStation)
        {
            return _tripAverages[{startStation, endStation}].first;
        }

      private:
        std::unordered_map<int, std::pair<std::string, int>> _startedTrips;

        // from trip = {startStation, endStation} to average = {time, trip_count}
        std::unordered_map<std::pair<std::string, std::string>, std::pair<double, size_t>, pair_hash> _tripAverages;
    };
}
