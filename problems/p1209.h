#pragma once
#include <stack>
#include <string>

namespace p1209
{
    class Solution2
    {
      public:
        struct Node
        {
            char Data = 0;
            Node* Next = nullptr;
            Node* Prev = nullptr;
        };

        std::string removeDuplicates(std::string s, int k)
        {
            if (k == 1)
                return "";
            auto S = s.size();
            if (k > int(S))
                return s;

            Node* head = nullptr;
            Node* tail = nullptr;
            auto to_list = [&](char c) {
                if (!head)
                    head = tail = new Node{c, nullptr, nullptr};
                else
                {
                    tail->Next = new Node{c, nullptr};
                    tail->Next->Prev = tail;
                    tail = tail->Next;
                }
            };

            auto remove_including = [&](Node* from, Node* to) {
                if (from == head && to == tail)
                {
                    head = tail = nullptr;
                    return;
                }

                if (from == head)
                {
                    head = to->Next;
                    head->Prev = nullptr;
                    return;
                }

                if (to == tail)
                {
                    tail = from->Prev;
                    tail->Next = nullptr;
                    return;
                }

                from->Prev->Next = to->Next;
                to->Next->Prev = from->Prev;
            };

            // make a linked list from the characters
            for (const auto c : s)
                to_list(c);

            // run removal on the list
            bool could_remove = true;
            while (could_remove)
            {
                if (!head)
                    return "";

                Node* start_region = head;
                while (start_region)
                {
                    Node* curr_region = start_region;
                    size_t region_size = 1;
                    while (region_size < k)
                    {
                        curr_region = curr_region->Next;
                        if (!curr_region || curr_region->Data != start_region->Data)
                            break;
                        ++region_size;
                    }
                    if (region_size == k)
                    {
                        could_remove = true;
                        remove_including(start_region, curr_region);
                        break;
                    }
                    if (!curr_region)
                    {
                        could_remove = false;
                        break;
                    }
                    start_region = curr_region;
                }
            }

            // make back a string from the list
            if (!head)
                return "";
            std::string result;
            auto* curr = head;
            while (curr)
            {
                result.append(1, curr->Data);
                curr = curr->Next;
            }
            return result;
        }
    };

    class Solution
    {
      public:
        std::string removeDuplicates(std::string s, int k)
        {
            if (k == 1)
                return "";
            auto S = s.size();
            if (k > int(S))
                return s;

            std::stack<std::pair<char, size_t>> data;
            size_t result_count = 0;
            for (const auto c : s)
            {
                if (!data.empty() && data.top().first == c)
                    ++data.top().second;
                else
                    data.push({c, 1});
                ++result_count;

                if (data.top().second == k)
                {
                    data.pop();
                    result_count -= k;
                }
            }

            std::string result(result_count, 0);
            size_t added = 0;
            while (!data.empty())
            {
                auto [c, count] = data.top();
                data.pop();

                for (size_t i = result_count - added - count; i < result_count - added; ++i)
                    result[i] = c;
                added += count;
            }
            return result;
        }
    };
}
