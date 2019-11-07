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
	unique_ptr<Smalltalk> person;
	for(int i = 0; i < numBrit; ++i) {
//		person = std::unique_ptr<Smalltalk>(new Smalltalk_Brit(i));
//		people.push_back(person);
//		people.push_back(person = new Smalltalk_Brit(i));
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_Brit(i)));

	}

		//add americans  to vector
	for(int i = 0; i < numAmerican; ++i) {
		//person = std::unique_ptr<Smalltalk>(new Smalltalk_American(i));
		//people.push_back(person);
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_American(i)));
	}

		//add american donut enthusiest to vector
	for(int i = 0; i < numbAmericanDonutEnthusiest; ++i) {
		//person = std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i));
		//people.push_back(person);
		people.push_back(std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i)));
	}

		//create some watches (as long as number watches <= numb people)
		//then give the watches away to first NUM_WATCHES people in the vector
//	if(numWatches > people.size())
//		numWatches = people.size();
	unique_ptr<Watch> handout;
	for(int i = 0; i < numWatches && i < people.size(); ++i) {
		handout = std::unique_ptr<Watch>(new Watch());
		people[i]->giveWatch(handout);
		//people[i]->giveWatch(std::unique_ptr<Watch>(new Watch()));
	}

		// when you are finished using the vector you return
		//from this function(see Smalltalk header for hints)

		//return your vector
	return people;
}
