#include <gtest/gtest.h>
#include <memory>
#include "model/Sentence.hpp"


using namespace testing;


namespace StupidPoet
{
    class TestSentence : public Test
    {
    protected:
        std::unique_ptr<Sentence>    _empty;
        std::unique_ptr<Sentence>    _one;
        std::unique_ptr<Sentence>    _ordinary;
        std::unique_ptr<const Sentence>  _const;

        void SetUp() override
        {
            _empty = std::make_unique<Sentence>();
            _one = std::make_unique<Sentence>(u"嗯");
            _ordinary = std::make_unique<Sentence>(u"渐闻水声潺潺而泻出于两峰之间者");
            _const = std::make_unique<Sentence>(u"仙人占斗客槎轻");
        }

        void TearDown() override
        {
            _empty.reset();
            _one.reset();
            _ordinary.reset();
            _const.reset();
        }
    };


    TEST_F(TestSentence, Size)
    {
        EXPECT_EQ(0u, _empty->Size());
        EXPECT_EQ(1u, _one->Size());
        EXPECT_EQ(15u, _ordinary->Size());
    }


    TEST_F(TestSentence, operatorSubscript)
    {
        EXPECT_EQ(u'嗯', _one->At(0));
        EXPECT_EQ(u'而', _ordinary->At(6));
        EXPECT_EQ(u'者', _ordinary->At(_ordinary->Size() - 1));

        (*_ordinary)[6] = u'尼';
        EXPECT_EQ(u'尼', (*_ordinary)[6]);
        EXPECT_EQ(u'占', (*_const)[2]);
    }


    TEST_F(TestSentence, Assign)
    {
        _empty->Assign(u"哈利");
        EXPECT_EQ(u'哈', _empty->At(0));
        EXPECT_EQ(u'利', _empty->At(1));

        _ordinary->Assign(u"");
        EXPECT_EQ(0u, _ordinary->Size());
    }


    TEST_F(TestSentence, Append)
    {
        _empty->Append(u'一');
        EXPECT_EQ(u'一', _empty->At(0));

        _one->Append(u'二');
        EXPECT_EQ(u'二', _one->At(1));

        size_t originLength = _ordinary->Size();
        _ordinary->Append(u'三');
        EXPECT_EQ(u'三', _ordinary->At(originLength));
    }
}
