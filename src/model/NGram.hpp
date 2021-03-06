#pragma once


#include "infra/UStr.hpp"


namespace StupidPoet
{
    enum NGramType
    {
        InSentence,
        CrossSentence
    };


    struct NGram
    {
        UStr            _content;
        unsigned int    _occurance;
        NGramType       _type;

        NGram(const size_t n, const NGramType type);
        bool    IsValid() const;
        inline UStr    GetPrefix() const { return _content.substr(0, _content.size() - 1); }
    };
}
