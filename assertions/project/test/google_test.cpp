#include <iostream>

/* The google test lib */
#include <gtest/gtest.h>

/* Now include my lib */
extern "C" {
    #include "../include/stats.h"
}




    /* Here we add our tests */
namespace {

    static const int arrays[3][5] = {{1, 2, 3, 4, 5}, {1, 2, 3}, {1, 2}};
    static const unsigned length_arrays[3] = {5, 3, 2};
    static const int results[3] = {2, 2, 1};

    
    /* the first argument is the name of the group of tests that this test will belongs
       the second argument is the name of this test */
    TEST(IntegerMean, Test1)
    {
        /* Inside of here we run our assert or except */
        


        /* we expect the mean works */
        EXPECT_EQ(results[0], mean(arrays[0], length_arrays[0]));

        
    }

    TEST(IntegerMean, Test2)
    {
        EXPECT_EQ(results[1], mean(arrays[1], length_arrays[1]));
    }

    TEST(IntegerMean, Test3)
    {
        EXPECT_EQ(results[2], mean(arrays[2], length_arrays[2]));
    }
}


/* We need to have all this things to run all the tests */
int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
