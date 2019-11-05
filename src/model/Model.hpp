#pragma once


#include <unordered_map>
#include "NGram.hpp"


namespace StupidPoet
{
    class Model
    {
    private:
        std::unordered_map<UStr, std::vector<NGram>> _inSentenceNGrams;      // prefix to NGram structs
        std::unordered_map<UStr, std::vector<NGram>> _crossSentenceNGrams;   // prefix to NGram structs

    public:
        void    InsertNGram(const NGram& nGram);
    };
}
