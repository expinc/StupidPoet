#include "FileIo.hpp"
#include <filesystem>


namespace StupidPoet
{
    bool ReadTextFromFile(const UChar* path, UStr& dst)
    {
        if (nullptr == path)
            return false;

        // Open file
        std::string pathUtf8 = UStr::toUtf8(path);
        FILE*   file = fopen(pathUtf8.c_str(), "rb");
        if (nullptr == path)
            return false;

        // Read file
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        char*   utf8Content = new char[length + 1];
        fread(utf8Content, sizeof(char), length, file);
        utf8Content[length] = '\0';
        fclose(file);
        file = nullptr;

        // Convert content
        if (utf8Content)
        {
            dst = UStr::fromUtf8(utf8Content);
            delete[] utf8Content;
            utf8Content = nullptr;
        }
        return true;
    }


    bool WriteTextToFile(const UChar* path, UStr& src)
    {
        // TODO
        return false;
    }


    std::shared_ptr<std::list<UStr>> GetFileList(const UChar* path)
    {
        auto    result = std::make_shared<std::list<UStr>>();
        for (const auto& entry : std::filesystem::directory_iterator(path))
        {
            result->push_back(entry.path().u16string());
        }
        return result;
    }
}
