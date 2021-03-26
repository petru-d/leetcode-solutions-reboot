#pragma once
#include <iterator>

namespace p1265
{
    class ImmutableListNode
    {
      public:
        ImmutableListNode(int val, ImmutableListNode* next, std::vector<int>& accumulator)
            : _val(val), _next(next), _accumulator(accumulator)
        {
        }

        void printValue()
        {
            _accumulator.push_back(_val);
        }

        ImmutableListNode* getNext()
        {
            return _next;
        }

      private:
        int _val = 0;
        ImmutableListNode* _next = nullptr;
        std::vector<int>& _accumulator;
    };

    class Solution
    {
      public:
        void printLinkedListInReverse(ImmutableListNode* head)
        {
            if (!head)
                return;
            printLinkedListInReverse(head->getNext());
            head->printValue();
        }
    };
}
