#pragma once

#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace challenge_28apr2020
{
    class FirstUnique
    {
      public:
        FirstUnique(std::vector<int>& nums)
        {
            _head->_prev = nullptr;
            _head->_next = _tail;
            _tail->_prev = _head;
            _tail->_next = nullptr;

            for (auto n : nums)
                add(n);
        }

        int showFirstUnique()
        {
            // check if the list of uniques is empty
            if (_head->_next->_next == nullptr)
                return -1;

            return _head->_next->val;
        }

        void add(int value)
        {
            // test if already inserted previously
            auto pos_uniques = _inserted.find(value);
            if (pos_uniques != _inserted.end())
            {
                UniqueNode* node = pos_uniques->second;

                // still valid in the list
                if (node != nullptr)
                {
                    UniqueNode* prev = node->_prev;
                    UniqueNode* next = node->_next;

                    prev->_next = next;
                    next->_prev = prev;

                    pos_uniques->second = nullptr;

                    delete node;
                }
            }
            else
            {

                // it's not anywhere - add it to the back of the uniques list and in the uniques map
                auto* node = new UniqueNode{value, nullptr, nullptr};

                _inserted.insert({value, node});

                UniqueNode* tail_prev = _tail->_prev;

                tail_prev->_next = node;
                node->_next = _tail;
                _tail->_prev = node;
                node->_prev = tail_prev;
            }
        }

      private:
        struct UniqueNode
        {
            int val;
            UniqueNode* _prev;
            UniqueNode* _next;
        };
        UniqueNode* _head = new UniqueNode{0, nullptr, nullptr};
        UniqueNode* _tail = new UniqueNode{0, nullptr, nullptr};

        std::unordered_map<int, UniqueNode*> _inserted;
    };
}