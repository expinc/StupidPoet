#pragma once


#include <map>
#include "NGram.hpp"
#include "Poetry.hpp"
#include "utility/Json.hpp"


namespace StupidPoet
{
    class Model
    {
    private:
        std::map<UStr, std::vector<NGram>> _inSentenceNGrams;      // prefix to NGram structs
        std::map<UStr, std::vector<NGram>> _crossSentenceNGrams;   // prefix to NGram structs

    public:
        void    InsertNGram(const NGram& nGram);
        void    LearnFromPoetry(const Poetry& poetry);
        JsonDoc    ToJson(){return JsonDoc();} // TODO
    };
}
