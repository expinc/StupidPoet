#pragma once


#include "UStr.hpp"


namespace StupidPoet
{
    enum NGramType
    {
        InSentence,
        CrossSentence
    };


    struct NGram
    {
        UStr            _prefix;
        UChar           _postfix;
        unsigned int    _occurance;
        NGramType       _type;

        NGram(const size_t n, const NGramType type);
        bool IsValid() const;
    };
}
