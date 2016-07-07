
// prabindh@yahoo.com
//
//invoke as 
//g++ -o test -I../googletest/include/ test.cpp ../googletest/src/gtest_main.cc libgtest.a libgtest_main.a -lpthread

#include "math.h"
#include "gtest/gtest.h"

double squareroot (const double in)
{
	return sqrt(in);
}

class myTester: public ::testing::Test {
  
public:
   double (*sqr)(const double);
   myTester( ) {
       // initialization code here
	   sqr = squareroot;
   }
 
   void SetUp( ) {
       // code here will execute just before the test ensues
   }
 
   void TearDown( ) {
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
   }
 
   ~myTester( )  {
       // cleanup any pending stuff, but no exceptions allowed
   }
};


 
TEST_F (myTester, PositiveNos) {
    EXPECT_EQ (18.0, sqr (324.0));
    EXPECT_EQ (25.4, sqr (645.16));
    EXPECT_EQ (50.3321, sqr (2533.310224));
}
 
TEST_F (myTester, ZeroAndNegativeNos) {
    ASSERT_EQ (0.0, sqr (0.0));
    ASSERT_EQ (-1, sqr (-22.0));
}

