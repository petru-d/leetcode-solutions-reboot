#pragma once

#include <algorithm>
#include <iterator>
#include <vector>

namespace p74
{
    class MatIterator
    {
      public:
        using iterator_category = std::random_access_iterator_tag;
        using value_type = int;
        using difference_type = size_t;
        using pointer = int*;
        using reference = int&;

        MatIterator(std::vector<std::vector<int>>& mat, size_t pos) : _mat(&mat), _pos(pos)
        {
        }

        reference operator[](size_t i)
        {
            auto [q, r] = std::div(int(i), int(_mat->front().size()));
            return (*_mat)[size_t(q)][size_t(r)];
        }

        MatIterator operator-(difference_type n) const
        {
            return MatIterator(*_mat, (_pos - n));
        }

        MatIterator& operator-=(difference_type n)
        {
            _pos -= n;
            return *this;
        }

        MatIterator operator--(int)
        {
            return MatIterator(*_mat, _pos--);
        }

        MatIterator& operator--()
        {
            --_pos;
            return *this;
        }

        difference_type operator-(const MatIterator& other) const
        {
            return _pos - other._pos;
        }
        difference_type operator+(const MatIterator& other) const
        {
            return _pos + other._pos;
        }

        MatIterator operator+(difference_type n) const
        {
            return MatIterator(*_mat, (_pos + n));
        }

        MatIterator& operator+=(difference_type n)
        {
            _pos += n;
            return *this;
        }

        MatIterator operator++(int)
        {
            return MatIterator(*_mat, _pos++);
        }

        MatIterator& operator++()
        {
            ++_pos;
            return *this;
        }

        reference operator*() const
        {
            auto [q, r] = std::div(int(_pos), int(_mat->front().size()));
            return (*_mat)[size_t(q)][size_t(r)];
        }

        pointer operator->()
        {
            auto [q, r] = std::div(int(_pos), int(_mat->front().size()));
            return &(*_mat)[size_t(q)][size_t(r)];
        }

        bool operator==(const MatIterator& rhs)
        {
            return _mat == rhs._mat && _pos == rhs._pos;
        }

        bool operator!=(const MatIterator& rhs)
        {
            return !(this->operator==(rhs));
        }

      private:
        std::vector<std::vector<int>>* _mat = nullptr;
        size_t _pos = -1;
    };

    MatIterator begin(std::vector<std::vector<int>>& mat)
    {
        return MatIterator(mat, 0);
    }

    MatIterator end(std::vector<std::vector<int>>& mat)
    {
        return MatIterator(mat, mat.size() * (mat.empty() ? 0 : mat.front().size()));
    }

    class Solution
    {
      public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
        {
            return std::binary_search(begin(matrix), end(matrix), target);
        }
    };
}
