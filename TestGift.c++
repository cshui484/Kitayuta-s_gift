// --------------------------------
// projects/gift/TestGift.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Gift.h"

using namespace std;

// -----------
// TestGift
// -----------

// ----
// check
// ----

TEST(GiftFixture, check_1) {
    string s("12345421");
    int  pos  = 0;
    bool rc; 
    rc = gift_check (s, pos);
    ASSERT_EQ(    2, pos);
    ASSERT_EQ(false, rc);}

TEST(GiftFixture, check_2) {
    string s("12345678987654321");
    int  pos  = 3;
    bool rc; 
    rc = gift_check (s, pos);
    ASSERT_EQ(   8, pos);
    ASSERT_EQ(true, rc);}

// ----
// eval
// ----

TEST(GiftFixture, eval_1) {
	string s("a");
    gift_eval(s);
    ASSERT_EQ(string("aa"), s);}

TEST(GiftFixture, eval_2) {
	string s("ee");
    gift_eval(s);
    ASSERT_EQ(string("eee"), s);}

TEST(GiftFixture, eval_3) {
	string s("abcdcba");
    gift_eval(s);
    ASSERT_EQ(string("abcddcba"), s);}

TEST(GiftFixture, eval_4) {
	string s("abcdedcb");
    gift_eval(s);
    ASSERT_EQ(string("abcdedcba"), s);}

TEST(GiftFixture, eval_5) {
	string s("abcdedcbat");
    gift_eval(s);
    ASSERT_EQ(string("tabcdedcbat"), s);}

TEST(GiftFixture, eval_6) {
	string s("abcdefgdcba");
    gift_eval(s);
    ASSERT_EQ(string("NA"), s);}


// -----
// print
// -----

/*
TEST(GiftFixture, print) {
    ostringstream w;
    gift_print(w, 1, 10, 20);
    ASSERT_EQ("1 10 20\n", w.str());}
*/

// -----
// solve
// -----

TEST(GiftFixture, solve_1) {
    istringstream r("12234321\n");
    ostringstream w;
    gift_solve(r, w);
    ASSERT_EQ("122343221\n", w.str());}

TEST(GiftFixture, solve_2) {
    istringstream r("122334321\n");
    ostringstream w;
    gift_solve(r, w);
    ASSERT_EQ("NA\n", w.str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Gift.c++ TestGift.c++ -o TestGift -lgtest -lgtest_main -lpthread



% valgrind TestGift                                         >  TestGift.out 2>&1
% gcov -b Gift.c++     | grep -A 5 "File 'Gift.c++'"     >> TestGift.out
% gcov -b TestGift.c++ | grep -A 5 "File 'TestGift.c++'" >> TestGift.out



% cat TestGift.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestGift
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Gift
[ RUN      ] Gift.read
[       OK ] Gift.read (31 ms)
[ RUN      ] Gift.eval_1
[       OK ] Gift.eval_1 (5 ms)
[ RUN      ] Gift.eval_2
[       OK ] Gift.eval_2 (3 ms)
[ RUN      ] Gift.eval_3
[       OK ] Gift.eval_3 (3 ms)
[ RUN      ] Gift.eval_4
[       OK ] Gift.eval_4 (3 ms)
[ RUN      ] Gift.print
[       OK ] Gift.print (17 ms)
[ RUN      ] Gift.solve
[       OK ] Gift.solve (10 ms)
[----------] 7 tests from Gift (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Gift.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Gift.c++.gcov'
File 'TestGift.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestGift.c++.gcov'
*/
