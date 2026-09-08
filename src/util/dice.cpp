#include "util.h"


/*
	DISCLAIMER!!!
	I still need to test the crit success/crit fail functionality.
*/



int getDamageRoll(damageInstance roll, string* result) {
	srand(time(nullptr)); // set rand() seed
	int roll_total = 0;

	if (roll.critical_hit == true) {
		*result += "<CRIT> ";
	}

	// loop through all damage sources
	for (int i=0; i<roll.source_vector.size(); i++) {
		int dice_roll = 0;
		string damage_interaction_string = "";

		// Associate each damage interaction with a string
		if (roll.source_vector.at(i).damage_interaction == 0) {
			damage_interaction_string += "immunity";
		}
		else if (roll.source_vector.at(i).damage_interaction == 0.5) {
			damage_interaction_string += "resistance";
		}
		else if (roll.source_vector.at(i).damage_interaction == 2.0) {
			damage_interaction_string += "vulnerability";
		}

		// if this damage instance is a critical hit, then double the amount of dice rolled in this current damage source
		if (roll.critical_hit == true) {
			roll.source_vector.at(i).dice_count *= 2;
		}

		// loop through the dice in the current damage source
		for (int j=0; j<roll.source_vector.at(i).dice_count; j++) {

			// calculate the dice roll
			dice_roll += (rand() % roll.source_vector.at(i).dice_type) + 1;
		}

		// add the damage modifier onto the roll
		dice_roll += roll.source_vector.at(i).damage_modifier;

		// take damage interactions into account in the dice roll (resistance, vulnerability, immunity)
		dice_roll *= roll.source_vector.at(i).damage_interaction;

		// get the result string
		*result += to_string(roll.source_vector.at(i).dice_count) + "d" + to_string(roll.source_vector.at(i).dice_type) +
		"+" + to_string(roll.source_vector.at(i).damage_modifier) + " " + roll.source_vector.at(i).damage_type +
		" (" + damage_interaction_string + ") = " + to_string(dice_roll);
		if (i<roll.source_vector.size()-1) {
			*result += " + ";
		}

		// Add the total of the current damage source to the total dice roll
		roll_total += dice_roll;
	}

	*result += " --> " + to_string(roll_total) + " damage";
	return roll_total;
}



int getD20Roll(d20Roll roll, string* result) {
	srand(time(nullptr)); // set rand() seed
	int roll_total = 0;
	
	// The eqivalent to xor of advantage and disadvantage. If you have either advantage or disadvantage, you roll 2 dice. Otherwise, you roll one.
	int dice_amount = (roll.advantage != roll.disadvantage) ? 2 : 1;

	if (dice_amount == 1) {
		roll_total = ((rand() % 20) + 1);
		if (roll_total == 20) {
			*result += "<CRIT SUCCESS> ";
			return 200;
		}
		else if (roll_total == 1) {
			*result += "<CRIT FAIL> ";
			return -200;
		}
		roll_total += roll.modifier;
	}

	else {
		int roll1 = ((rand() % 20) + 1);
		int roll2 = ((rand() % 20) + 1);
		cout<<"roll1: "<<roll1<<endl<<"roll2: "<<roll2<<endl;

		// rolling with advantage
		if (roll.advantage) {
			roll_total = (roll1 > roll2) ? roll1 : roll2;
			*result += "<ADVANTAGE> ";

			if (roll_total == 20) {
				*result += "<CRIT SUCCESS> ";
				roll_total = 200;
			}
			else if (roll_total == 1) {
				*result += "<CRIT FAIL> ";
				roll_total = -200;
			}
			else {
				roll_total += roll.modifier;
			}
		}
		// rolling with disadvantage
		else {
			roll_total = (roll1 < roll2) ? roll1 : roll2;
			*result += "<DISADVANTAGE> ";

			if (roll_total == 20) {
				*result += "<CRIT SUCCESS> ";
				roll_total = 200;
			}
			else if (roll_total == 1) {
				*result += "<CRIT FAIL> ";
				roll_total = -200;
			}
			else {
				roll_total += roll.modifier;
			}
		}
	}

	*result += roll.roll_type + " roll: " + to_string(roll_total);
	return roll_total;

}