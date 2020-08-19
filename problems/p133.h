#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace p133

{

    // Definition for a Node.
    class Node
    {
      public:
        int val;
        std::vector<Node*> neighbors;

        Node()
        {
            val = 0;
            neighbors = std::vector<Node*>();
        }

        Node(int _val)
        {
            val = _val;
            neighbors = std::vector<Node*>();
        }

        Node(int _val, std::vector<Node*> _neighbors)
        {
            val = _val;
            neighbors = _neighbors;
        }
    };

    class Solution
    {
      public:
        Node* cloneGraph(Node* node)
        {
            if (node == nullptr)
                return nullptr;

            std::unordered_set<const Node*> visited;
            std::unordered_map<const Node*, Node*> clones;

            std::vector<const Node*> queue = {node};

            while (!queue.empty())
            {
                std::vector<const Node*> new_queue;

                for (const auto* n : queue)
                {
                    if (visited.find(n) != visited.end())
                        continue;
                    visited.insert(n);

                    Node* nclone = nullptr;
                    auto npos = clones.find(n);
                    if (npos == clones.end())
                    {
                        nclone = new Node(n->val);
                        clones.emplace(n, nclone);
                    }
                    else
                        nclone = npos->second;

                    for (const auto* nn : n->neighbors)
                    {
                        Node* nnclone = nullptr;
                        auto nnpos = clones.find(nn);
                        if (nnpos == clones.end())
                        {
                            nnclone = new Node(nn->val);
                            clones.emplace(nn, nnclone);
                        }
                        else
                            nnclone = nnpos->second;

                        nclone->neighbors.push_back(nnclone);

                        if (visited.find(nn) == visited.end())
                            new_queue.push_back(nn);
                    }
                }
                queue = std::move(new_queue);
            }

            return clones[node];
        }
    };
}
