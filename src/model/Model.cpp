#include "Model.hpp"


namespace StupidPoet
{
    void Model::InsertNGram(const NGram& nGram)
    {
        std::map<UStr, std::vector<NGram>>&    nGramMap = _inSentenceNGrams;
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


    void Model::LearnFromPoetry(const Poetry& poetry)
    {
        for (size_t i = 0; i < poetry.Size(); ++i)
        {
            for (size_t j = 0; j < poetry[i].Size(); ++j)
            {
                // In-sentence 2-gram
                if (j > 0)
                {
                    NGram   twoGram(2, NGramType::InSentence);
                    twoGram._content[0] = poetry[i][j - 1];
                    twoGram._content[1] = poetry[i][j];
                    twoGram._occurance = 1;
                    InsertNGram(twoGram);
                }

                // In-sentence 3-gram
                if (j > 1)
                {
                    NGram   triGram(3, NGramType::InSentence);
                    triGram._content[0] = poetry[i][j - 2];
                    triGram._content[1] = poetry[i][j - 1];
                    triGram._content[2] = poetry[i][j];
                    triGram._occurance = 1;
                    InsertNGram(triGram);
                }

                // CrossSentence 2-gram
                if (i > 0)
                {
                    NGram   crossTwoGram(2, NGramType::CrossSentence);
                    crossTwoGram._content[0] = poetry[i - 1][j];
                    crossTwoGram._content[1] = poetry[i][j];
                    crossTwoGram._occurance = 1;
                    InsertNGram(crossTwoGram);
                }
            }
        }
    }
}
