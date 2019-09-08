import os


logFile = 'log.txt'


def cleanLog():
    try:
        os.remove(logFile)
    except OSError:
        pass


def log(msg):
    file = open(logFile, 'a')
    file.write(msg)
    file.close()


def isChinese(uchar):
    if uchar is not None and uchar >= u'\u4e00' and uchar <= u'\u9fa5':
        return True
    else:
        return False
