// ----------------------------
// projects/gift/Gift.c++
// Copyright (C) 2015
// CS Hui
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Gift.h"

using namespace std;

// ------------
// gift_check
// ------------

bool gift_check (const string& s, int& pos) {
	int sLen_  = s.length();
	int cSize_ = sLen_ / 2;
	int lastP_ = sLen_ - 1;

	while ((s[pos] == s[lastP_-pos]) && (pos < cSize_)) {
//		cout << pos << ':' << s[pos] << ':' << s[lastP_-pos] << endl;
		pos++;	}	

//	cout << "pos = " << pos << " cSize = " << cSize_ << " sLen_ = " << sLen_ << endl;
	
	if (pos == cSize_) {
		return true; }				// match
	else {
		return false; }				// not match
}

// ------------
// gift_eval
// ------------

void gift_eval (string& s) {
	bool	matched;
	bool	done = false;
	bool	inserted_LHS_ = false;
	bool	inserted_RHS_ = false;
	int		posSaved_;
	int 	pos_  = 0;
	int 	sLen_ = s.length();
	

/*
	for (uint i=0; i<s.length(); ++i) {
		std::cout << s[i]; }
	cout << endl;

	s.insert(2,1,'x');
*/
	while (!done) {
		matched = gift_check (s, pos_);
		if (matched) {
			if (!inserted_LHS_) {
				s.insert(pos_, 1, s[pos_]); }
//			cout << "matched = " << s << endl;
			done = true; }
		else if (!inserted_LHS_) {						// first try insert at LHS
			inserted_LHS_ = true;
			posSaved_ = pos_;							// in case need to insert at RHS
			s.insert(pos_, 1, s[sLen_-1-pos_]);			// inserted at LHS
			sLen_++; }									// update sLen_
		else if (!inserted_RHS_) {						// need to try insert at RHS
			inserted_RHS_ = true;
			pos_ = posSaved_;							// restore original failed position
			s.erase(pos_, 1); 							// remove the LHS inserted char
			s.insert(sLen_-1-pos_, 1, s[pos_]);	}		// insert at RHS, -1 as Slen_ is updated
		else {											// can't make a palindrome
			done = true;
			s.erase(sLen_-posSaved_, 1);
//			cout << "not matched = " << s << endl; 
			s = string("NA"); }}

//		cout << pos_ << '=' << s[pos_] << ':' << s[sLen_-1-pos_] << endl; }

//	return 1;
}

// -------------
// gift_print
// -------------

void gift_print (ostream& w, string r) {
    w << r << endl;}

// -------------
// gift_solve
// -------------

void gift_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
/*
        const pair<int, int> p = gift_read(s);
        const int            i = p.first;
        const int            j = p.second;
*/
                    		 gift_eval(s);
        gift_print(w, s);}}
