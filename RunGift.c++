// -------------------------------
// projects/gift/RunGift.c++
// Copyright (C) 2015
// CS Hui
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Gift.h"

// ----
// main
// ----

int main () {
    using namespace std;
    gift_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Gift.c++ RunGift.c++ -o RunGift



% cat RunGift.in
1 10
100 200
201 210
900 1000



% RunGift < RunGift.in > RunGift.out



% cat RunGift.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
