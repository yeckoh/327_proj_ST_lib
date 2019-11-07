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

Smalltalk::Smalltalk(string myNationality,int iPerson) : nationality(myNationality), iPerson(1), current_phrase(0) {}

Smalltalk::~Smalltalk(void) {

}

string Smalltalk::saySomething() {
	if(current_phrase == mySmallTalk.size())
		current_phrase = 0;
	return nationality + " " + to_string(iPerson) + ':' + mySmallTalk[current_phrase++];
}

string Smalltalk::getTime() {
	if(!pWatch)
		return I_DO_NOT_HAVE_A_WATCH;
	return pWatch->getTime();
}

unique_ptr<Watch> Smalltalk::takeWatch() {
	if(!pWatch)
		return 0;
	return move(pWatch);
}

bool Smalltalk::giveWatch(unique_ptr<Watch> &pWatch) {
	if(!pWatch)
		return false;
	this->pWatch = move(pWatch);
	return true;
}

// TODO: destructors, memleaks, valgrind,

