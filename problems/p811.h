#pragma once
#include <string>
#include <vector>

namespace p811
{
    class Solution
    {
      public:
        struct TrieNode
        {
            std::string Val;
            std::unordered_map<std::string, TrieNode*> Children;

            size_t Count = 0;
        };

        std::vector<std::string> subdomainVisits(std::vector<std::string>& cpdomains)
        {
            struct ParsedDomain
            {
                size_t Count = 0;
                std::vector<std::string> DomainFragments;
            };

            auto parse_domain = [](const std::string& full_domain) {
                ParsedDomain result;

                auto pos_space = full_domain.find(' ');
                result.Count = std::stoi(full_domain.substr(0, pos_space));

                auto pos_dot = pos_space;
                while (pos_dot != std::string::npos)
                {
                    auto new_pos_dot = full_domain.find('.', pos_dot + 1);
                    if (new_pos_dot == std::string::npos)
                        result.DomainFragments.push_back(full_domain.substr(pos_dot + 1));
                    else
                        result.DomainFragments.push_back(full_domain.substr(pos_dot + 1, new_pos_dot - pos_dot - 1));
                    pos_dot = new_pos_dot;
                }

                std::reverse(result.DomainFragments.begin(), result.DomainFragments.end());

                return result;
            };

            auto add_parsed_domain = [](TrieNode* root, const ParsedDomain& parsed_domain) {
                auto* curr = root;

                for (const auto& p : parsed_domain.DomainFragments)
                {
                    auto pos_p = curr->Children.find(p);
                    if (pos_p == curr->Children.end())
                    {
                        auto* new_curr = new TrieNode{p, {}, parsed_domain.Count};
                        curr->Children.insert({p, new_curr});
                        curr = new_curr;
                    }
                    else
                    {
                        curr = pos_p->second;
                        curr->Count += parsed_domain.Count;
                    }
                }
            };

            TrieNode root;
            for (const auto& cp : cpdomains)
            {
                add_parsed_domain(&root, parse_domain(cp));
            }

            std::vector<std::string> gathered_data;
            for (auto [key, child] : root.Children)
            {
                std::vector<const TrieNode*> partial_path;
                gather_data(child, partial_path, gathered_data);
            }

            return gathered_data;
        }

        void gather_data(const TrieNode* root, std::vector<const TrieNode*>& partial_path,
                         std::vector<std::string>& gathered_data)
        {
            auto remake_domain = [](const std::vector<const TrieNode*>& partial_path) {
                std::string result = std::to_string(partial_path.back()->Count);
                result.append(1, ' ');

                for (auto it = partial_path.rbegin(); it != partial_path.rend(); ++it)
                {
                    result += (*it)->Val;
                    result.append(1, '.');
                }
                result.pop_back();

                return result;
            };

            partial_path.push_back(root);

            gathered_data.push_back(remake_domain(partial_path));

            for (auto [key, child] : root->Children)
            {
                gather_data(child, partial_path, gathered_data);
            }

            partial_path.pop_back();
        }
    };
}
