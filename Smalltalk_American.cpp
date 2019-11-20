/*
 *       File: Smalltalk_American.cpp
 *    Project: cs327 p5 - obj hierarchies, std_ptrs, ABCs
 *       Prof: K. Perkins @ CNU
 * Created on: Nov 7, 2019
 *     Author: wchang 00960978
 *  LModified: Nov 7, 2019
 */

#include <string>
#include <vector>
#include "./includes/Smalltalk_American.h"
#include "./includes/constants.h"

using namespace std;

Smalltalk_American::Smalltalk_American(int iPerson) : Smalltalk(AMERICAN, iPerson) {
	populatePhrases();
}

Smalltalk_American::Smalltalk_American(string myNationality, int iPerson) : Smalltalk(myNationality, iPerson) {}

Smalltalk_American::~Smalltalk_American(void) {}

void Smalltalk_American::populatePhrases() {
	this->mySmallTalk.clear();
	this->mySmallTalk.push_back(AMERICAN_PHRASE_1);
	this->mySmallTalk.push_back(AMERICAN_PHRASE_2);
	this->mySmallTalk.push_back(AMERICAN_PHRASE_3);
	this->mySmallTalk.push_back(AMERICAN_PHRASE_4);
	this->mySmallTalk.push_back(AMERICAN_PHRASE_5);
}
