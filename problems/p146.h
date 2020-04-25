#pragma once
#include <cassert>
#include <unordered_map>
namespace p146
{
    class LRUCache
    {
      public:
        LRUCache(int capacity) : _capacity(static_cast<size_t>(capacity))
        {
            _data.reserve(static_cast<size_t>(capacity));

            _queue_head->prev = nullptr;
            _queue_head->next = _queue_tail;
            _queue_tail->prev = _queue_head;
            _queue_tail->next = nullptr;
        }

        int get(int key)
        {
            auto pos = _data.find(key);
            if (pos == _data.end())
                return -1;

            Node* val = pos->second;
            if (nullptr == val)
            {
                assert(false);
                return -1;
            }

            // extract val from the queue
            Node* prevVal = val->prev;
            Node* nextVal = val->next;
            prevVal->next = nextVal;
            nextVal->prev = prevVal;

            // and put it in front
            Node* head_next = _queue_head->next;
            val->prev = _queue_head;
            _queue_head->next = val;
            val->next = head_next;
            head_next->prev = val;

            return val->val;
        }

        void put(int key, int value)
        {
            // If the key is alreayd in the queue, find it, update it and put it in front
            auto pos = _data.find(key);
            if (pos != _data.end())
            {
                Node* val = pos->second;
                val->val = value;

                // extract val from the queue
                Node* prevVal = val->prev;
                Node* nextVal = val->next;
                prevVal->next = nextVal;
                nextVal->prev = prevVal;

                // and put it in front
                Node* head_next = _queue_head->next;
                val->prev = _queue_head;
                _queue_head->next = val;
                val->next = head_next;
                head_next->prev = val;

                return;
            }

            // if full, evict least used
            if (_data.size() == _capacity)
            {
                Node* evict = _queue_tail->prev;
                Node* prev_evict = evict->prev;

                _data.erase(evict->key);
                delete evict;

                prev_evict->next = _queue_tail;
                _queue_tail->prev = prev_evict;
            }

            // make the new node
            Node* newNode = new Node{key, value, nullptr, nullptr};

            // put it in the map
            _data[key] = newNode;

            // and put it in front of the queue
            Node* head_next = _queue_head->next;
            newNode->prev = _queue_head;
            _queue_head->next = newNode;
            newNode->next = head_next;
            head_next->prev = newNode;
        }

      private:
        size_t _capacity = 0;

        struct Node

        {
            int key = -1;
            int val = -1;
            Node* prev = nullptr;
            Node* next = nullptr;
        };

        std::unordered_map<int, Node*> _data;

        // Nodes are stored between head and tail from most used to least
        Node* _queue_head = new Node{-1, -1, nullptr, nullptr};
        Node* _queue_tail = new Node{-1, -1, nullptr, nullptr};
    };
}