#pragma once

#include <optional>
#include <string>
#include <unordered_map>
#include <unordered_set>

namespace p432
{
    class AllOne
    {
      public:
        /** Initialize your data structure here. */
        AllOne()
        {
            _headVals->next = _tailVals;
            _tailVals->prev = _headVals;
        }

        /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
        void inc(std::string key)
        {
            auto pos = _keys.find(key);
            if (pos == _keys.end())
            {
                // add this key
                if (_headVals->next->val == 1)
                {
                    // .. along the other nodes with value 1, if any
                    _headVals->next->children.insert(key);

                    _keys[key] = _headVals->next;
                }
                else
                {
                    // inside a new node with value 1, if none
                    Node* newN = new Node();
                    newN->val = 1;
                    newN->children = {key};

                    InjectNode(newN, _headVals);

                    _keys[key] = newN;
                }
            }
            else
            {
                // this key is already present
                auto* n = _keys[key];

                n->children.erase(key);

                if (n->next->val == n->val + 1)
                {
                    // add it to the next node - the value matches
                    n->next->children.insert(key);
                    _keys[key] = n->next;
                }
                else
                {
                    // add it to a new next node - the value doesn't match
                    Node* newN = new Node();
                    newN->val = n->val + 1;
                    newN->children = {key};

                    InjectNode(newN, n);

                    _keys[key] = newN;
                }

                // remove the origin node if it is empty
                if (n->children.empty())
                    delete n;
            }
        }

        /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
        void dec(std::string key)
        {
            auto pos = _keys.find(key);
            if (pos == _keys.end())
                return;

            auto* n = _keys[key];
            n->children.erase(key);

            if (n->val == 1)
            {
                _keys.erase(key);
            }
            else
            {
                if (n->prev->val == n->val - 1)
                {
                    // add it to the prev node - the value matches
                    n->prev->children.insert(key);

                    _keys[key] = n->prev;
                }
                else
                {
                    // add it to a new prev node - the value does not match
                    Node* newN = new Node();
                    newN->val = n->val - 1;
                    newN->children = {key};

                    InjectNode(newN, n->prev);

                    _keys[key] = newN;
                }
            }
            

            // remove the origin node if it is empty
            if (n->children.empty())
                delete n;
        }

        /** Returns one of the keys with maximal value. */
        std::string getMaxKey()
        {
            return _keys.empty() ? "" : (*_tailVals->prev->children.begin());
        }

        /** Returns one of the keys with Minimal value. */
        std::string getMinKey()
        {
            return _keys.empty() ? "" : (*_headVals->next->children.begin());
        }

      private:
        // all keys with a certain value
        struct Node
        {
            int val = -1;
            Node* prev = nullptr;
            Node* next = nullptr;
            std::unordered_set<std::string> children;

            ~Node()
            {
                prev->next = next;
                next->prev = prev;
            }
        };

        void InjectNode(Node* n, Node* where)
        {
            auto where_next = where->next;

            where->next = n;
            n->next = where_next;
            where_next->prev = n;
            n->prev = where;
        }

        std::unordered_map<std::string, Node*> _keys;
        Node* _headVals = new Node{std::numeric_limits<int>::min(), nullptr, nullptr};
        Node* _tailVals = new Node{std::numeric_limits<int>::max(), nullptr, nullptr};
    };
}
