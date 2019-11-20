/*
 *       File: Smalltalk.cpp
 *    Project: cs327 p5 - obj hierarchies, std_ptrs, ABCs
 *       Prof: K. Perkins @ CNU
 * Created on: Nov 7, 2019
 *     Author: wchang 00960978
 *  LModified: Nov 20, 2019
 */

#include <string>
#include <vector>

#include "./includes/Smalltalk.h"
#include "./includes/constants.h"

using namespace std;

Smalltalk::Smalltalk(string myNationality,int iPerson) : nationality(myNationality), iPerson(1), current_phrase(0) {}

Smalltalk::~Smalltalk(void) {}

string Smalltalk::saySomething() {
	if(current_phrase == mySmallTalk.size()) // less expensive than %, and stops overflow
		current_phrase = 0;
	return nationality + " " + to_string(iPerson) + ':' + mySmallTalk[current_phrase++];
}

string Smalltalk::getTime() {
	if(pWatch)
		return pWatch->getTime();
	return I_DO_NOT_HAVE_A_WATCH;
}

unique_ptr<Watch> Smalltalk::takeWatch() {
	if(pWatch)
		return move(pWatch);
	return NULL;
}

bool Smalltalk::giveWatch(unique_ptr<Watch> &pWatch) {
	if(!pWatch)
		return false;
	this->pWatch = move(pWatch);
	return true;
}

