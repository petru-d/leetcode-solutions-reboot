#pragma once

namespace p362
{
    class HitCounter
    {
      public:
        /** Initialize your data structure here. */
        HitCounter()
        {
        }

        /** Record a hit.
            @param timestamp - The current timestamp (in seconds granularity). */
        void hit(int timestamp)
        {
            while (_hitsHead != nullptr && _hitsHead->time + 299 < timestamp)
            {
                auto* curr = _hitsHead;
                _hitCount -= curr->hits;
                _hitsHead = curr->next;
                delete curr;
            }

            if (!_hitsHead)
            {
                _hitsTail = _hitsHead = new Node{timestamp, 1, nullptr};
                _hitCount = 1;
                return;
            }

            if (_hitsTail->time == timestamp)
            {
                ++_hitsTail->hits;
            }
            else
            {
                _hitsTail->next = new Node{timestamp, 1, nullptr};
                _hitsTail = _hitsTail->next;
            }

            ++_hitCount;
        }

        /** Return the number of hits in the past 5 minutes.
            @param timestamp - The current timestamp (in seconds granularity). */
        int getHits(int timestamp)
        {
            while (_hitsHead != nullptr && _hitsHead->time + 299 < timestamp)
            {
                auto* curr = _hitsHead;
                _hitCount -= curr->hits;
                _hitsHead = curr->next;
                delete curr;
            }

            return _hitCount;
        }

        struct Node
        {
            int time = -1;
            int hits = -1;
            Node* next = nullptr;
        };

        Node* _hitsHead = nullptr;
        Node* _hitsTail = nullptr;
        int _hitCount = 0;
    };
}