#include "gmock/gmock.h"

#include "Soundex.hpp"

using namespace testing;

class SoundexEncoding: public Test {
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
    auto encoded = soundex.encode("A");
    ASSERT_EQ(encoded, "A000");
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
    auto encoded = soundex.encode("I");
    ASSERT_EQ(encoded, "I000");
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
    auto encoded = soundex.encode("AB");
    ASSERT_EQ(encoded, "A100");
}

GTEST_API_ int main(int argc, char **argv) {
    printf("Running unit tests\n");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
