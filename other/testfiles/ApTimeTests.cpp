#include "ApTimeTests.h"
#include <iostream>
using namespace std;

TEST_F(ApTimeTests, ApTimeConstructorTest){

    //Normal input tests:
    ApTime time(5,5);
    EXPECT_TRUE(time.getHour() == 5);
    EXPECT_TRUE(time.getMinutes() == 5);
    ApTime time2(23,59);
    EXPECT_TRUE(time2.getHour() == 23);
    EXPECT_TRUE(time2.getMinutes() == 59);

    //Incorrect input tests:
    //Negative inputs
    ApTime time3(-10, 12);
    EXPECT_TRUE(time3.getHour() == 0);
    EXPECT_FALSE(time3.getHour() == -10);
    EXPECT_TRUE(time3.getMinutes() == 12);

    ApTime time4(12, -20);
    EXPECT_TRUE(time4.getMinutes() == 0);
    EXPECT_FALSE(time4.getMinutes() == -20);
    EXPECT_TRUE(time4.getHour() == 12);

    ApTime time5(-10, -20);
    EXPECT_TRUE(time5.getMinutes() == 0);
    EXPECT_TRUE(time5.getHour() == 0);
    EXPECT_FALSE(time5.getHour() == -10);
    EXPECT_FALSE(time5.getMinutes() == -20);

    //Inputs greater than possible inputs
    ApTime time6(25, 10);
    EXPECT_TRUE(time6.getHour() == 0);
    EXPECT_FALSE(time6.getHour() == 25);
    EXPECT_TRUE(time6.getMinutes() == 10);

    ApTime time7(12, 61);
    EXPECT_TRUE(time7.getMinutes() == 0);
    EXPECT_FALSE(time7.getMinutes() == 61);
    EXPECT_TRUE(time7.getHour() == 12);

    ApTime time8(25, 61);
    EXPECT_TRUE(time8.getMinutes() == 0);
    EXPECT_FALSE(time8.getMinutes() == 61);
    EXPECT_TRUE(time8.getHour() == 0);
    EXPECT_FALSE(time8.getHour() == 25);

}

TEST_F(ApTimeTests, ApTimeGetterTests){
    ApTime time(12, 20);

    EXPECT_TRUE(time.getHour() == 12);
    EXPECT_FALSE(time.getHour() == 0);

    EXPECT_TRUE(time.getMinutes() == 20);
    EXPECT_FALSE(time.getMinutes() == 0);

    ApTime time2(1,2);

    EXPECT_TRUE(time2.getMinutes() == 2);
    EXPECT_FALSE(time2.getMinutes() == 1);

    EXPECT_FALSE(time2.getHour() == 2);
    EXPECT_TRUE(time2.getHour() == 1);

}

TEST_F(ApTimeTests, ApTimeSetterTests){
    ApTime time(12, 20);

    EXPECT_TRUE(time.getHour() == 12);
    EXPECT_TRUE(time.getMinutes() == 20);

    time.setHour(22);
    EXPECT_TRUE(time.getHour() == 22);
    EXPECT_FALSE(time.getHour() == 12);

    time.setHour(-10);
    EXPECT_FALSE(time.getHour() == -10);
    EXPECT_FALSE(time.getHour() == 12);
    EXPECT_TRUE(time.getHour() == 0);

    time.setHour(25);
    EXPECT_FALSE(time.getHour() == 25);
    EXPECT_FALSE(time.getHour() == 12);
    EXPECT_TRUE(time.getHour() == 0);

    time.setMinutes(31);
    EXPECT_FALSE(time.getMinutes() == 20);
    EXPECT_TRUE(time.getMinutes() == 31);

    time.setMinutes(-20);
    EXPECT_FALSE(time.getMinutes() == -20);
    EXPECT_FALSE(time.getMinutes() == 20);
    EXPECT_TRUE(time.getMinutes() == 0);

    time.setMinutes(61);
    EXPECT_FALSE(time.getMinutes() == 61);
    EXPECT_FALSE(time.getMinutes() == 20);
    EXPECT_TRUE(time.getMinutes() == 0);
}

TEST_F(ApTimeTests, ApTimeRaiseTimeTest){
    ApTime time(17, 12);

    //current time: 17:12
    time.raiseTime(5);
    EXPECT_FALSE(time.getMinutes() == 12);
    EXPECT_TRUE(time.getMinutes() == 17);
    EXPECT_TRUE(time.getHour() == 17);

    //current time: 17:17
    time.raiseTime(60);
    EXPECT_FALSE(time.getHour() == 17);
    EXPECT_TRUE(time.getHour() == 18);
    EXPECT_TRUE(time.getMinutes() == 17);

    //current time: 18:17
    time.raiseTime(184);
    EXPECT_FALSE(time.getHour() == 18);
    EXPECT_TRUE(time.getHour() == 21);
    EXPECT_FALSE(time.getMinutes() == 17);
    EXPECT_TRUE(time.getMinutes() == 21);

    //current time: 21:21
}

TEST_F(ApTimeTests, ApTimeToStringTest){
    ApTime time(15,10);
    EXPECT_TRUE(time.toString() == "15:10");

    time.setMinutes(5);
    time.setHour(3);

    EXPECT_TRUE(time.toString() == "03:05");
    EXPECT_FALSE(time.toString() == "3:5");

    time.setHour(0);
    time.setMinutes(0);

    EXPECT_TRUE(time.toString() == "00:00");
    EXPECT_FALSE(time.toString() == "0:0");

}

TEST_F(ApTimeTests, ApTimeOperatorTests){

    ApTime time(12,0);

    //ApTime++ operator:
    //current time: 12:00
    time++;
    EXPECT_FALSE(time.getMinutes() == 0);
    EXPECT_TRUE(time.getMinutes() == 1);
    EXPECT_TRUE(time.getHour() == 12);

    time.setMinutes(59);
    time++;
    EXPECT_FALSE(time.getMinutes() == 59);
    EXPECT_TRUE(time.getMinutes() == 0);
    EXPECT_FALSE(time.getHour() == 12);
    EXPECT_TRUE(time.getHour() == 13);

    //ApTime += operator
    //current time: 13:00
    time+=10;
    EXPECT_FALSE(time.getMinutes() == 0);
    EXPECT_TRUE(time.getMinutes() == 10);
    EXPECT_TRUE(time.getHour() == 13);

    time+= 50;
    EXPECT_FALSE(time.getMinutes() == 10);
    EXPECT_TRUE(time.getMinutes() == 0);
    EXPECT_FALSE(time.getHour() == 13);
    EXPECT_TRUE(time.getHour() == 14);

    //ApTime1 == ApTime2 operation
    //current time: 14:00
    ApTime time2(14,0);
    ApTime time3(0,14);

    EXPECT_TRUE(time == time2);
    EXPECT_FALSE(time == time3);

    //ApTime1 != ApTime2 operation
    EXPECT_TRUE(time != time2);
    EXPECT_FALSE(time != time3);

    //= operator
    ApTime time4 = time;
    EXPECT_TRUE(time4.getHour() == time.getHour());
    EXPECT_TRUE(time4.getMinutes() == time.getMinutes());
}