/*
 * ST_American_Donut_enthusiest.cpp
 *
 *  Created on: Nov 7, 2019
 *      Author: wc
 */

#include <string>
#include <vector>
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/constants.h"

using namespace std;

ST_American_DonutEnthusiest::ST_American_DonutEnthusiest(int i) : Smalltalk_American(AMERICAN_DE, i) {
	populatePhrases();
}

ST_American_DonutEnthusiest::~ST_American_DonutEnthusiest(void) {

}

//base class populatePhrases() will be called first as part of its construction
//before this class calls populate phrases as part of its construction
//the end result is mySmallTalk will contain first the base class phrases and
//then this classes phrases
void ST_American_DonutEnthusiest::populatePhrases() {
	this->Smalltalk_American::populatePhrases();

	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_1);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_2);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_3);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_4);
	this->mySmallTalk.push_back(AMERICAN_DE_PHRASE_5);
}

