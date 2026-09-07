#include "util/util.h"

using namespace std;

int main(void) {
	damageSource d1, d2;

	d1.dice_count = 1;
	d1.dice_type = 8;
	d1.damage_modifier = 3;
	d1.damage_interaction = 0.5;
	d1.damage_type = "slashing";

	d2.dice_count = 2;
	d2.dice_type = 4;
	d2.damage_interaction = 2.0;
	d2.damage_type = "fire";

	vector <damageSource> d = {d1, d2};

	damageInstance dr;
	dr.critical_hit = true;
	dr.source_vector = d;

	string result;

	int damage_roll = getDamageRoll(dr, &result);
	cout<<"You deal: "<<damage_roll<<" damage!"<<endl;
	//cout<<result<<endl;

	return 0;
}