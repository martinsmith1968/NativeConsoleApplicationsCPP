//
// Created by marti on 27/09/2023.
//

#include <gtest/gtest.h>

#include "src/Strings.h"

using namespace DNX::Utilities;

TEST(IsNullOrEmpty, BasicAssertions)
{
    const std::string text1 = "";
    EXPECT_TRUE(Strings::IsNullOrEmpty(&text1));

    const std::string* text2 = nullptr;
    EXPECT_TRUE(Strings::IsNullOrEmpty(text2));

    const std::string text3 = "a";
    EXPECT_FALSE(Strings::IsNullOrEmpty(&text3));
}

TEST(IsNullOrWhiteSpace, BasicAssertions)
{
    const std::string text1 = "";
    EXPECT_TRUE(Strings::IsNullOrWhiteSpace(&text1));

    const std::string* text2 = nullptr;
    EXPECT_TRUE(Strings::IsNullOrWhiteSpace(text2));

    const std::string text3 = " ";
    EXPECT_TRUE(Strings::IsNullOrWhiteSpace(&text1));

    const std::string text4 = "a";
    EXPECT_FALSE(Strings::IsNullOrWhiteSpace(&text4));
}



TEST(Strings_LTrim, BasicAssertions)
{
    EXPECT_STRNE("hello", "world");

    EXPECT_EQ(7 * 6, 42);
}
