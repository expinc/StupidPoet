#pragma once


#include <map>
#include "NGram.hpp"
#include "Poetry.hpp"
#include "utility/json/JsonDoc.hpp"


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
        std::shared_ptr<JsonDoc>    ToJson();

    private:
        void    nGramMapIntoJsonArray(const std::map<UStr, std::vector<NGram>>& nGramMap, JsonArray& jsonArray);
    };
}
