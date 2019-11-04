#include <gtest/gtest.h>
#include <memory>
#include "model/Poetry.hpp"


using namespace testing;


namespace StupidPoet
{
    class TestPoetry : public Test
    {
    protected:
        std::unique_ptr<Poetry>    _empty;
        std::unique_ptr<Poetry>    _one;
        std::unique_ptr<Poetry>    _ordinary;
        std::unique_ptr<const Poetry>  _const;

        void SetUp() override
        {
            _empty = std::make_unique<Poetry>();

            _one = std::make_unique<Poetry>();
            _one->Append(Sentence(u"甲老子给你龟儿一锤子"));

            _ordinary = std::make_unique<Poetry>();
            _ordinary->Append(Sentence(u"乙莫挨老子"));
            _ordinary->Append(Sentence(u"丙我去年买了个表"));
            _ordinary->Append(Sentence(u"丁我有一句妈卖批不知当讲不当讲"));

            Poetry* constPoetry = new Poetry();
            constPoetry->Append(Sentence(u"戊我儿豁你"));
            constPoetry->Append(Sentence(u"己一二三四五六七"));
            _const.reset(constPoetry);
        }

        void TearDown() override
        {
            _empty.reset();
            _one.reset();
            _ordinary.reset();
            _const.reset();
        }
    };


    TEST_F(TestPoetry, Size)
    {
        EXPECT_EQ(0u, _empty->Size());
        EXPECT_EQ(1u, _one->Size());
        EXPECT_EQ(3u, _ordinary->Size());
        EXPECT_EQ(2u, _const->Size());
    }


    TEST_F(TestPoetry, At)
    {
        EXPECT_EQ(u'甲', _one->At(0).At(0));
        EXPECT_EQ(u'丙', _ordinary->At(1).At(0));
        EXPECT_EQ(u'丁', _ordinary->At(2).At(0));
    }


    TEST_F(TestPoetry, operatorSubscript)
    {
        EXPECT_EQ(u'甲', (*_one)[0].At(0));

        (*_ordinary)[0] = Sentence(u"嗯");
        EXPECT_EQ(u'嗯', _ordinary->At(0).At(0));

        EXPECT_EQ(u'己', (*_const)[1].At(0));
    }


    TEST_F(TestPoetry, Append)
    {
        const Sentence sentence(u"米饭");
        _empty->Append(sentence);
        EXPECT_EQ(u'米', _empty->At(0).At(0));

        _one->Append(Sentence(u"阿瓦达啃大瓜"));
        EXPECT_EQ(u'阿', _one->At(1).At(0));
    }
}
