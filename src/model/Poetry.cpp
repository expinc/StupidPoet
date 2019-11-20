#include "Poetry.hpp"


namespace StupidPoet
{
    Poetry::Poetry(const UStr& str)
    {
        Sentence    sentence;
        for (const UChar& ch : str)
        {
            if (u'\r' == ch || u'\n' == ch)
            {
                if (0 != sentence.Size())
                {
                    Append(sentence);
                    sentence.Assign(u"");
                }
            }
            else
                sentence.Append(ch);
        }

        if (0 != sentence.Size())
            Append(sentence);
    }
}
