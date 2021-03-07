#pragma once
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

namespace p895
{
    struct Element
    {
        int Val = 0;
        std::vector<size_t> Occurences;
    };

    bool operator<(const Element& l, const Element& r)
    {
        if (l.Occurences.size() != r.Occurences.size())
            return l.Occurences.size() < r.Occurences.size();

        return l.Occurences.back() < r.Occurences.back();
    }

    struct cmp
    {
        bool operator()(const Element* l, const Element* r) const
        {
            return *l < *r;
        }
    };

    class FreqStackMine
    {
      public:
        FreqStackMine()
        {
        }

        void push(int x)
        {
            auto pos = v_to_e.find(x);
            if (pos == v_to_e.end())
            {
                auto* n = new Element{x, {++_count}};
                v_to_e.emplace(x, n);
                e.insert(n);
            }
            else
            {
                Element* to_update = pos->second;
                e.erase(to_update);
                to_update->Occurences.push_back(++_count);
                e.insert(to_update);
            }
        }

        int pop()
        {
            Element* to_update = *e.rbegin();
            int result = to_update->Val;

            e.erase(to_update);

            if (to_update->Occurences.size() == 1)
                v_to_e.erase(result);
            else
            {
                to_update->Occurences.pop_back();
                e.insert(to_update);
            }

            return result;
        }

        size_t _count = 0;

        std::unordered_map<int, Element*> v_to_e;
        std::set<Element*, cmp> e;
    };

    class FreqStackOana
    {
      public:
        FreqStackOana()
        {
        }

        void push(int x)
        {
            size_t add_here = 0;
            auto pos_x = last_added.find(x);
            if (pos_x != last_added.end())
            {
                add_here = 1 + pos_x->second;
            }

            if (add_here >= appearances.size())
            {
                std::stack<int> s;
                s.push(x);
                appearances.push_back(s);
            }
            else
                appearances[add_here].push(x);

            last_added[x] = add_here;
        }

        int pop()
        {
            int result = appearances.back().top();

            --last_added[result];

            appearances.back().pop();
            if (appearances.back().empty())
                appearances.pop_back();

            return result;
        }

        std::vector<std::stack<int>> appearances;
        std::unordered_map<int, size_t> last_added;
    };
}
