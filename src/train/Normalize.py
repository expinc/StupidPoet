import os


trainRawDataPath = 'data/train/raw/'
logFileName = 'log.txt'


def log(msg):
    file = open(logFileName, 'a')
    file.write(msg)
    file.close()


def is_chinese(uchar):
    if uchar >= u'\u4e00' and uchar <= u'\u9fa5':
        return True
    else:
        return False


def normalizePoetry(poetryFileName):
    log('Normalizing ' + poetryFileName[:-4] + '...\n')
    poetryFile = open(trainRawDataPath + poetryFileName, 'r', encoding='utf-8')
    raw = poetryFile.read()
    poetryFile.close()

    trainNormalizedDataPath = 'data/train/normalized/'
    normalizedFile = open(trainNormalizedDataPath + poetryFileName, 'w', encoding='utf-8')
    inRemark = False
    for char in raw:
        if inRemark:
            if ')' == char or '）' == char or '】' == char:
                inRemark = False
            continue

        if is_chinese(char):
            normalizedFile.write(char)
        elif '(' == char or '（' == char or '【' == char:
            inRemark = True
        else:
            normalizedFile.write('\n')
    normalizedFile.close()


try:
    os.remove(logFileName)
except OSError:
    pass

allRawPoetries = os.listdir(trainRawDataPath)
for rawPoetry in allRawPoetries:
    normalizePoetry(rawPoetry)
