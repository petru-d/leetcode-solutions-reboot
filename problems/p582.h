#pragma once
#include <queue>
#include <unordered_map>
#include <vector>

namespace p582
{
    class Solution
    {
      public:
        std::vector<int> killProcess(std::vector<int>& pid, std::vector<int>& ppid, int kill)
        {
            std::unordered_map<int, std::vector<int>> graph;
            for (size_t i = 0; i < pid.size(); ++i)
            {
                if (ppid[i] == 0)
                    continue;
                graph[ppid[i]].push_back(pid[i]);
            }

            std::vector<int> result;
            std::queue<int> q;
            q.push(kill);
            while (!q.empty())
            {
                auto sz = q.size();
                for (size_t i = 0; i < sz; ++i)
                {
                    auto k = q.front();
                    result.push_back(k);
                    q.pop();
                    const auto& children_k = graph[k];
                    for (auto c : children_k)
                        q.push(c);
                }
            }

            return result;
        }
    };
}
