import Common
import Meta
import os


def normalizePoetry(poetryFileName):
    Common.log('Normalizing ' + poetryFileName[:-4] + '...\n')
    poetryFile = open(Meta.trainRawPath + poetryFileName, 'r', encoding='utf-8')
    raw = poetryFile.read()
    poetryFile.close()

    normalizedFile = open(Meta.trainNormalizedPath + poetryFileName, 'w', encoding='utf-8')
    inRemark = False
    lastChar = None
    for char in raw:
        if inRemark:
            if ')' == char or '）' == char or '】' == char:
                inRemark = False
            continue

        if Common.isChinese(char):
            normalizedFile.write(char)
        elif '(' == char or '（' == char or '【' == char:
            inRemark = True
        else:
            if Common.isChinese(lastChar):
                normalizedFile.write('\n')
        
        lastChar = char
    normalizedFile.close()


def cleanOldData():
    allFiles = os.listdir(Meta.trainNormalizedPath)
    for file in allFiles:
        os.remove(Meta.trainNormalizedPath + file)


Common.cleanLog()
cleanOldData()
allRawPoetries = os.listdir(Meta.trainRawPath)
for rawPoetry in allRawPoetries:
    normalizePoetry(rawPoetry)
