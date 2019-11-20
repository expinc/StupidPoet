#pragma once


#include <vector>
#include "Sentence.hpp"


namespace StupidPoet
{
    class Poetry
    {
    private:
        std::vector<Sentence> _sentences;

    public:
        Poetry() = default;
        Poetry(const UStr& str);

        inline size_t  Size() const  { return _sentences.size(); }
        inline Sentence&    At(const size_t index) { return _sentences[index]; }
        inline Sentence&        operator [](size_t index) { return _sentences[index]; }
        inline const Sentence&  operator [](size_t index) const { return _sentences[index]; }
        inline void Append(const Sentence& sentence) { _sentences.push_back(sentence); }
        inline void Append(Sentence&& sentence) { _sentences.push_back(sentence); }
    };
}
