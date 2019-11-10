#include <clocale>
#include <cstdlib>
#include <filesystem>
#include <list>
#include <memory>
#include "infra/Env.hpp"
#include "infra/UStr.hpp"
#include "model/Poetry.hpp"


using namespace StupidPoet;

#ifdef _WIN32
static UStr s_trainDataPath(u"data\\train\\normalized\\");
#endif


std::shared_ptr<std::list<UStr>> GetFileList(const UChar* path)
{
    auto    result = std::make_shared<std::list<UStr>>();
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        result->push_back(entry.path().u16string());
    }
    return result;
}


bool ReadFromFile(const UChar* path, UStr& dest)
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
        dest = UStr::fromUtf8(utf8Content);
        delete[] utf8Content;
        utf8Content = nullptr;
    }
    return true;
}


int main(int argc, const char* argv[])
{
    int error = putenv("STUPID_POETRY_PATH=E:\\dev\\StupidPoet\\"); // TODO: remove
    setlocale(LC_ALL, g_locale);

    UStr    workPath = UStr::fromUtf8(getenv("STUPID_POETRY_PATH"));
    UStr    trainFilePath = workPath + s_trainDataPath;
    auto    fileList = GetFileList(trainFilePath.c_str());
    std::list<std::shared_ptr<Poetry>>   poetries;
    for (const auto& file : *fileList)
    {
        UStr fileContent;
        if ( ReadFromFile(file.c_str(), fileContent) )
            ;
        // TODO: fileContent to Poetry
    }

    // TODO: build model
    return EXIT_SUCCESS;
}
