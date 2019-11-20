/*
 *       File: ST_American_Donut_enthusiest.cpp
 *    Project: cs327 p5 - obj hierarchies, std_ptrs, ABCs
 *       Prof: K. Perkins @ CNU
 * Created on: Nov 7, 2019
 *     Author: wchang 00960978
 *  LModified: Nov 7, 2019
 */

#include <string>
#include <vector>
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/constants.h"

using namespace std;

ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int i) : Smalltalk_American(AMERICAN_DE, i) {
	populatePhrases();
}

ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {}

void ST_American_DonutEnthusiest::populatePhrases() {
	this->Smalltalk_American::populatePhrases();
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}

