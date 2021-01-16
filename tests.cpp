#include <iostream>
#include "gtest/gtest.h"
#include "methods.h"


TEST(b64, t1) {
    const char * line;
    const char * expected;
    line = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which is "
           "a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation "
           "of knowledge, exceeds the short vehemence of any carnal pleasure.";
    expected = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZ"
               "nJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZG"
               "VsaWdodCBpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHR"
               "oZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
    EXPECT_STREQ(expected, to_b64(line));
}


TEST(b64, t2) {
    const char * line;
    const char * expected;
    line = "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlzIHNpbmd1bGFyIHBhc3Npb24gZnJvb"
           "SBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2YgdGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodC"
           "BpbiB0aGUgY29udGludWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRoZSBzaG9ydCB"
           "2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";
    expected = "Man is distinguished, not only by his reason, but by this singular passion from other animals, which "
               "is a lust of the mind, that by a perseverance of delight in the continued and indefatigable generation "
               "of knowledge, exceeds the short vehemence of any carnal pleasure.";
    EXPECT_STREQ(expected, from_b64(line));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}