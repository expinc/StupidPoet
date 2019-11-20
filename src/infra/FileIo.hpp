#pragma once


#include "UStr.hpp"
#include <list>
#include <memory>


namespace StupidPoet
{
    bool ReadTextFromFile(const UChar* path, UStr& dst);
    bool WriteTextToFile(const UChar* path, const UChar* content);
    std::shared_ptr<std::list<UStr>> GetFileList(const UChar* path);
}
