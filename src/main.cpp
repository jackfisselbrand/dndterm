#include "util/util.h"

using namespace std;

int main(void) {
	d20Roll roll;
	roll.advantage = true;
	roll.modifier = 5;
	roll.roll_type += "attack";

	string result;
	int roll_result = 0;
	while (roll_result != -200) {
		result = "";
		roll_result = getD20Roll(roll, &result);
	}

	cout<<"roll_result: "<<roll_result<<endl;
	cout<<"result: "<<result<<endl;

	return 0;
}