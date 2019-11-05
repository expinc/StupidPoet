#include "NGram.hpp"


#include "ModelException.hpp"


namespace StupidPoet
{
    NGram::NGram(size_t n, NGramType type) :
        _content(n, u'\0'),
        _occurance(0),
        _type(type)
    {
        if (0 == n)
            throw ModelException(u"Invalid NGram parameter!");
    }


    bool NGram::IsValid() const
    {
        for (const auto& elem : _content)
        {
            if (u'\0' == elem)
                return false;
        }
        return true;
    }
}
