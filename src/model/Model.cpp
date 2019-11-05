#include "Model.hpp"


namespace StupidPoet
{
    void Model::InsertNGram(const NGram& nGram)
    {
        std::unordered_map<UStr, std::vector<NGram>>&    nGramMap = _inSentenceNGrams;
        if (NGramType::CrossSentence == nGram._type)
            nGramMap = _crossSentenceNGrams;

        UStr    prefix = nGram.GetPrefix();
        auto tuple = nGramMap.find(prefix);
        if (nGramMap.end() == tuple)
        {
            std::vector<NGram>  nGramList;
            nGramList.push_back(nGram);
            nGramMap.insert( std::make_pair<UStr, std::vector<NGram>>(std::move(prefix), std::move(nGramList)) );
        }
        else
        {
            std::vector<NGram>&  nGramList = tuple->second;
            auto iter = nGramList.begin();
            for (; iter != nGramList.end(); ++iter)
            {
                if (iter->_content.back() == nGram._content.back())
                    break;
            }

            if (nGramList.end() != iter)
                iter->_occurance += nGram._occurance;
            else
                nGramList.push_back(nGram);
        }
    }
}
