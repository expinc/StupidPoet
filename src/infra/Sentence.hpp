#pragma once


#include "UStr.hpp"


namespace StupidPoet
{
    class Sentence
    {
    private:
        UStr    _content;

    public:
        Sentence() = default;
        inline Sentence(const UChar* content) { _content.assign(content); }

        inline size_t   Size() const { return _content.size(); }
        inline const UChar& operator [](const size_t index) const { return _content[index]; }
        inline UChar&       operator [](const size_t index) { return _content[index]; }
    };
}
