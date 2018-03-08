#include <iostream>
#include <gtest/gtest.h>
using namespace std;

int main(int argc, char* argv[]) {
    //MAIN FOR TESTING
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
