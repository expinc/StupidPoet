#include "NGram.hpp"


#include "InfraException.hpp"


namespace StupidPoet
{
    NGram::NGram(size_t n, NGramType type) :
        _prefix(n - 1, u'\0'),
        _postfix(u'\0'),
        _occurance(0),
        _type(type)
    {
        if (0 == n)
            throw InfraException(u"Invalid NGram parameter!");
    }


    bool NGram::IsValid() const
    {
        for (const auto& elem : _prefix)
        {
            if (u'\0' == elem)
                return false;
        }
        return u'\0' != _postfix;
    }
}
