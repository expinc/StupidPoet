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
        if (nullptr == file)
            return false;

        // Read file
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        char*   utf8Content = new char[length + 1];
        size_t  readCount = fread(utf8Content, sizeof(char), length, file);
        utf8Content[length] = '\0';
        fclose(file);
        file = nullptr;

        // Convert content
        if (utf8Content && readCount == length)
        {
            dst = UStr::fromUtf8(utf8Content);
            delete[] utf8Content;
            utf8Content = nullptr;
            return true;
        }
        return false;
    }


    bool WriteTextToFile(const UChar* path, const UChar* content)
    {
        if (nullptr == path || nullptr == content)
            return false;

        std::string pathUtf8 = UStr::toUtf8(path);
        std::string contentUtf8 = UStr::toUtf8(content);
        FILE*   file = fopen(pathUtf8.c_str(), "wb");
        if (nullptr != file)
        {
            int error = fputs(contentUtf8.c_str(), file);
            fclose(file);
            file = nullptr;
            if (EOF == error)
                return false;
        }
        return true;
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
