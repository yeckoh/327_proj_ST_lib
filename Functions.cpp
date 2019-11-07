//
/*
 * Functions.cpp
 *
 *  Created on: Nov 5, 2017
 *      Author: keith
 */
#include <iostream>
#include <memory>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

using namespace std;

//create a vector with appropriate numbers of Smalltalk_Brit,Smalltalk_American and ST_American_DonutEnthusiest
//objects using unique pointers.  Since we are using c++11 returning this vector by value is fine since the 
//compiler will move the vector on return rather than recreate it (this means there is no copy penalty)
vector<unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	
	//create a vector to hold SmallTalk unique pointers
	vector<unique_ptr<Smalltalk>> people;

		//add brits to vector
	for(int i = 0; i < numBrit; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_Brit(i)));

		//add americans  to vector
	for(int i = 0; i < numAmerican; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_American(i)));

		//add american donut enthusiest to vector
	for(int i = 0; i < numbAmericanDonutEnthusiest; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i)));

		//create some watches (as long as number watches <= numb people)
	if(numWatches > people.size())
		numWatches = people.size(); // looks passed by value, ok

		//then give the watches away to first NUM_WATCHES people in the vector
	for(int i = 0; i < numWatches; ++i)
		people[i]->giveWatch(*new unique_ptr<Watch>(new Watch()));

	return people;
}
