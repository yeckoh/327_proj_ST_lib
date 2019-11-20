/*
 *       File: Smalltalk.cpp
 *    Project: cs327 p5 - obj hierarchies, std_ptrs, ABCs
 *       Prof: K. Perkins @ CNU
 * Created on: Nov 7, 2019
 *     Author: wchang 00960978
 *  LModified: Nov 20, 2019
 */
#include <memory>

#include "./includes/Functions.h"
#include "./includes/Smalltalk_American.h"
#include "./includes/ST_American_DonutEnthusiest.h"
#include "./includes/Smalltalk_Brit.h"
#include "./includes/Watch.h"
#include "./includes/constants.h"

using namespace std;

/* create a vector to hold SmallTalk unique pointers
add brits to vector
add americans  to vector
add american donut enthusiest to vector
give the watches away to first NUM_WATCHES people in the vector */
vector<unique_ptr<Smalltalk>> getPeople(int numBrit,
		int numAmerican, int numbAmericanDonutEnthusiest,
		int numWatches) {
	vector<unique_ptr<Smalltalk>> people;
	for(int i = 0; i < numBrit; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_Brit(i)));
	for(int i = 0; i < numAmerican; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new Smalltalk_American(i)));
	for(int i = 0; i < numbAmericanDonutEnthusiest; ++i)
		people.push_back(std::unique_ptr<Smalltalk>(new ST_American_DonutEnthusiest(i)));
	if(numWatches > people.size())
		numWatches = people.size(); // passed by value, modifying ok
	for(int i = 0; i < numWatches; ++i) {
		unique_ptr<Watch> handout(new Watch());
		people[i]->giveWatch(handout);
	}
	return people;
}
