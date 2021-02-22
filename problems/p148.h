#pragma once

#include "util_linked_list.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>

class LLIterator
{
  public:
    using iterator_category = std::forward_iterator_tag;
    using value_type = int;
    using difference_type = size_t;
    using pointer = int*;
    using reference = int&;

    LLIterator(ListNode* n) : _currNode(n), _isEnd(n == nullptr)
    {
    }

    LLIterator operator++()
    {
        if (_isEnd)
            return *this;

        _currNode = _currNode->next;
        if (_currNode == nullptr)
            _isEnd = true;

        return *this;
    }

    reference operator*()
    {
        return _currNode->val;
    }

    pointer operator->()
    {
        return &_currNode->val;
    }

    bool operator==(const LLIterator& rhs)
    {
        return _currNode == rhs._currNode && _isEnd == rhs._isEnd;
    }

    bool operator!=(const LLIterator& rhs)
    {
        return !(this->operator==(rhs));
    }

  private:
    ListNode* _currNode = nullptr;
    bool _isEnd = true;
};

LLIterator begin(ListNode* head)
{
    return LLIterator(head);
}

LLIterator end(ListNode* head)
{
    return LLIterator(nullptr);
}

namespace p148
{
    class Solution
    {
      public:
        ListNode* sortList(ListNode* head)
        {
            qsort(begin(head), end(head));

            return head;
        }

      private:
        void qsort(LLIterator s, LLIterator e)
        {
            if (s.operator==(e))
                return;
            auto pivot = *s;
            LLIterator middle1 = std::partition(s, e, [pivot](const auto& em) { return em < pivot; });
            auto middle2 = std::partition(middle1, e, [pivot](const auto& em) { return !(pivot < em); });
            qsort(s, middle1);
            qsort(middle2, e);
        }
    };
}
