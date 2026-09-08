#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
	A specific damage source.
	Includes:
		1. dice_count: The amount of dice to be rolled
		2. dice_type: The type of dice being rolled
		3. damage_modifier: The damage modifier of an instance of damage
		4. damage_interaction: The damage interaction of an instance of damage (Neutral(1), Resistance(.5), Vulnerability(2), Immunity(0))
		5. damage_type: The type of damage being rolled
*/
typedef struct damageSource {
	int dice_count = 0;
	int dice_type = 0;
	int damage_modifier = 0;
	double damage_interaction = 1;
	string damage_type;
} damageSource;

typedef struct damageInstance {
	bool critical_hit = false;
	vector <damageSource> source_vector;
} damageInstance;

typedef struct d20Roll {
	bool advantage = false;
	bool disadvantage = false;
	int modifier = 0;
	string roll_type;
} d20Roll;

// Calculate a damage roll
int getDamageRoll(damageInstance roll, string* result);

// Calculate a d20 roll
int getD20Roll(d20Roll roll, string* result);

#endif