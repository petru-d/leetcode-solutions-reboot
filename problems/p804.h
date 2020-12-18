#pragma once

#include <vector>
#include <string>
#include <array>

namespace p804
{
    class Solution
    {
      public:
        struct Node
        {
            bool IsLeaf = false;
            Node* Zero = nullptr;
            Node* One = nullptr;
        };

        int uniqueMorseRepresentations(std::vector<std::string>& words)
        {
            auto* root = new Node{};
            int leaves = 0;

            auto get_morse = [](char l) {
                static const std::array<std::vector<bool>, 26> morse = {
                    std::vector<bool>{false, true},                //".-"
                    std::vector<bool>{true, false, false, false},  //"-..."
                    std::vector<bool>{true, false, true, false},   //"-.-."
                    std::vector<bool>{true, false, false},         //"-.."
                    std::vector<bool>{false},                      //"."
                    std::vector<bool>{false, false, true, false},  //"..-."
                    std::vector<bool>{true, true, false},          //"--."
                    std::vector<bool>{false, false, false, false}, //"...."
                    std::vector<bool>{false, false},               //".."
                    std::vector<bool>{false, true, true, true},    //".---"
                    std::vector<bool>{true, false, true},          //"-.-"
                    std::vector<bool>{false, true, false, false},  //".-.."
                    std::vector<bool>{true, true},                 //"--"
                    std::vector<bool>{true, false},                //"-."
                    std::vector<bool>{true, true, true},           //"---"
                    std::vector<bool>{false, true, true, false},   //".--."
                    std::vector<bool>{true, true, false, true},    //"--.-"
                    std::vector<bool>{false, true, false},         //".-."
                    std::vector<bool>{false, false, false},        //"..."
                    std::vector<bool>{true},                       //"-"
                    std::vector<bool>{false, false, true},         //"..-"
                    std::vector<bool>{false, false, false, true},  //"...-"
                    std::vector<bool>{false, true, true},          //".--"
                    std::vector<bool>{true, false, false, true},   //"-..-"
                    std::vector<bool>{true, false, true, true},    //"-.--"
                    std::vector<bool>{true, true, false, false}    //"--.."
                };

                return morse[l - 'a'];
            };

            auto add = [](Node* root, bool lr) {
                if (!lr)
                {
                    if (!root->Zero)
                    {
                        root->Zero = new Node{};
                    }
                    return root->Zero;
                }

                if (!root->One)
                {
                    root->One = new Node{};
                }
                return root->One;
            };

            for (const auto& w : words)
            {
                auto* curr = root;
                for (const auto l : w)
                {
                    auto morse = get_morse(l);
                    for (const auto m : morse)
                        curr = add(curr, m);
                }

                if (!curr->IsLeaf)
                {
                    curr->IsLeaf = true;
                    ++leaves;
                }
            }

            return leaves;
        }
    };
}
