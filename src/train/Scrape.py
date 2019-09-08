import Common
import Meta
import os
import random
import requests
from bs4 import BeautifulSoup


Meta.trainRawPath = 'data/train/raw/'


def remainChinese(str):
    result = u''
    for char in str:
        if (Common.isChinese(char)):
            result += char
    return result


def getAllPoetries(url):
    response = requests.get(url)
    content = BeautifulSoup(response.text)
    poetryPane = content.select('body > div.main3 > div.left')[0]
    poetries = poetryPane.select('.cont')
    if not poetries:
        return
    for poetry in poetries:
        titleStr = poetry.select('p:nth-child(2) > a > b')[0].text
        titleStr = remainChinese(titleStr)
        Common.log('extracting poetry ' + titleStr + '...\n')
        body = poetry.select('.contson')[0]
        bodyStr = ''

        # body style 1
        for sentence in body.select('p'):
            bodyStr += sentence.text + '\n'
        bodyStr = bodyStr.replace(u'\u3000', u'')

        # body style 2
        if '' == bodyStr:
            bodyStr = body.text

        file = open(Meta.trainRawPath + titleStr + '.txt', 'w', encoding = 'utf-8')
        file.write(bodyStr)
        file.close()
    
    next = content.select('.amore')[0]
    if next is not None:
        nextUrl = next.get('href')
        if nextUrl is not None:
            getAllPoetries(serverUrl + nextUrl)


# 古诗文网
Common.cleanLog()
serverUrl = 'https://so.gushiwen.org'
poetryPath = '/shiwen/'
mainPageUrl = serverUrl + poetryPath
response = requests.get(mainPageUrl)
content = BeautifulSoup(response.text)

# 古诗文网 > 诗文 > 类型
types = content.select('#type1 > div.sright > a')
for typ in types:
    Common.log('extracting type ' + typ.text + '...\n')
    typeUrl = serverUrl + typ.get('href')
    getAllPoetries(typeUrl)
