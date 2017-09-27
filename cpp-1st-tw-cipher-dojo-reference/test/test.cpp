//
// Created by bence on 9/26/17.
//

#include <gtest/gtest.h>
#include "../src/decipher.h"

namespace tests {

    TEST(CipherTests, NullTests) {
        std::string message("hello");
        std::string key("KEY");
        ASSERT_EQ(message, decipher("", message));
        ASSERT_EQ("", decipher(key, ""));
        ASSERT_EQ("", decipher("", ""));
    }


    TEST(CipherTests, NoRotationTests) {
        std::string message("hello");
        ASSERT_EQ(message, decipher("A", message));
        ASSERT_EQ(message, decipher("AA", message));
        ASSERT_EQ(message, decipher("AAAAAAAAA", message));
    }


    TEST(CipherTests, RotateOnceTests) {
        ASSERT_EQ("BBB", decipher("B", "AAA"));
        ASSERT_EQ("B", decipher("BBB", "A"));
    }


    TEST(CipherTests, MultipleRotationTests) {
        ASSERT_EQ("abcde", decipher("ABCDE", "aaaaa"));
    }


    TEST(CipherTests, OverturnTests) {
        ASSERT_EQ("abcd", decipher("BCDE", "zzzz"));
    }


    TEST(CipherTests, NonAlphabetTests) {
        ASSERT_EQ("bb, bb", decipher("B", "aa, aa"));
        ASSERT_EQ("ab, ab", decipher("AB", "aa, aa"));
    }

    int main(int argc, char *argv[]){
        ::testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
    }
}