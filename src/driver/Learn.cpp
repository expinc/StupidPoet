#include <clocale>
#include <cstdlib>
#include <list>
#include <memory>
#include "infra/Env.hpp"
#include "infra/FileIo.hpp"
#include "infra/UStr.hpp"
#include "model/Model.hpp"
#include "model/Poetry.hpp"


using namespace StupidPoet;

#ifdef _WIN32
static UStr s_trainDataPath(u"data\\train\\normalized\\");
static UStr s_modelPath(u"data\\model.json");
#endif


int main(int argc, const char* argv[])
{
    int error = putenv("STUPID_POETRY_PATH=E:\\dev\\StupidPoet\\"); // TODO: remove
    setlocale(LC_ALL, g_locale);

    // Load train data
    UStr    workPath = UStr::fromUtf8(getenv("STUPID_POETRY_PATH"));
    UStr    trainFilePath = workPath + s_trainDataPath;
    auto    fileList = GetFileList(trainFilePath.c_str());
    if (fileList->empty())
        return EXIT_FAILURE;
    std::list<std::shared_ptr<Poetry>>   poetries;
    for (const auto& file : *fileList)
    {
        UStr fileContent;
        if ( ReadTextFromFile(file.c_str(), fileContent) )
            poetries.push_back(std::make_shared<Poetry>(fileContent));
    }

    // Build model and save it to json
    Model   model;
    for (const auto& poetry : poetries)
    {
        model.LearnFromPoetry(*poetry);
    }
    JsonDoc    modelJson = model.ToJson();
    UStr    modelFilePath = workPath + s_modelPath;
    if ( WriteTextToFile(modelFilePath.c_str(), modelJson.toString().c_str()) )
        return EXIT_SUCCESS;
    else
        return EXIT_FAILURE;
}
