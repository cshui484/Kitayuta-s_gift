// --------------------------
// projects/gift/Gift.h
// Copyright (C) 2015
// CS Hui
// --------------------------

#ifndef Gift_h
#define Gift_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// gift_check
// ------------

/**
 * check if the given string is a palindrome
 * @param s a string 
 * @param pos staring position for checking; if failed, points to the failed position
 * @return a boolean true is s is palindrome, false otherwise
 */
bool gift_check (const string& s, int& pos);

// ------------
// gift_eval
// ------------

/**
 * @param s string to be converted to be a palindrome 
 * @return void, s will be converted to a plaindrome if sucessful or 'NA' if failed
 */
void gift_eval (string& s);

// -------------
// gift_print
// -------------

/**
 * print a string
 * @param w an ostream
 * @param s the string
 */
void gift_print (ostream& w, string s);

// -------------
// gift_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void gift_solve (istream& r, ostream& w);

#endif // Gift_h
