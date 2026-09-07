#include "util.h"

int getDamageRoll(damageInstance roll, string* result) {
	srand(time(nullptr)); // set rand() seed
	int roll_total = 0;

	// loop through all damage sources
	for (int i=0; i<roll.source_vector.size(); i++) {

		// if this damage instance is a critical hit, then double the amount of dice rolled in this current damage source
		if (roll.critical_hit == true) {
			roll.source_vector.at(i).dice_count *= 2;
		}

		// loop through the dice in the current damage source
		for (int j=0; j<roll.source_vector.at(i).dice_count; j++) {
			
			int dice_roll = (rand() % roll.source_vector.at(i).dice_type) + 1; // calculate the dice roll
			dice_roll *= roll.source_vector.at(i).damage_interaction; // take damage interactions into account in the dice roll (resistance, vulnerability, immunity)

			// Add the total of the current damage source to the total dice roll
			roll_total += dice_roll;
		}

		cout<<endl<<endl;
	}

	return roll_total;
}