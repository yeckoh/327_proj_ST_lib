/*
 * Smalltalk.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: wc
 */

#include <string>
#include <vector>
#include "./includes/Smalltalk.h"
#include "./includes/constants.h"

using namespace std;

Smalltalk::Smalltalk(string myNationality,int iPerson) : nationality(myNationality), iPerson(1), current_phrase(0) {
	this->pWatch = 0;
}

Smalltalk::~Smalltalk(void) {

}

	//cycles through phrases added in populatePhrases. Returns them 1 by 1 starting with the first and ending
	//with the last and then it starts over
	//takes the form Nationality iPerson: phrase
	//for instance the following string comes from an American instance, the 10th iPerson and it is printing AMERICAN_PHRASE_2
	//AMERICAN 10:Why yes, I would like to supersize that
	string Smalltalk::saySomething() {
		return this->nationality + to_string(iPerson) + this->mySmallTalk[this->current_phrase];
	}

	//returns the time (if pWatch contains a watch ) in the form of THE_CURRENT_TIME_IS: (from the actual watch object itself) and then the time
	//or I_DO_NOT_HAVE_A_WATCH string (if pWatch does not contain a watch)
	string Smalltalk::getTime() {
		if(!pWatch)
			return I_DO_NOT_HAVE_A_WATCH;
		return pWatch->getTime();
	}

	//if this object has a watch it is taken away, otherwise an empty unique_ptr is returned
	// This transaction simulates giving away a watch
	unique_ptr<Watch> Smalltalk::takeWatch() {
		if(!pWatch)
			return 0;
		return move(pWatch);
	}

	//if already have a watch then return false and dont change pWatch pointer
	//otherwise accept watch (return true) and set this->pWatch=pWatch (use std::move)
	bool Smalltalk::giveWatch(unique_ptr<Watch> &pWatch) {
		if(!pWatch)
			return false;
		this->pWatch = move(pWatch);
		return true;
	}

	//Abstract Base Class (ABC), implement in derived classes
	// TODO: pure virual functions in base class implementation y/n
	//virtual void Smalltalk::populatePhrases()=0;

