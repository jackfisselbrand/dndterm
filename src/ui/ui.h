#ifndef UI_H
#define UI_H

#include "ftxui/component/app.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/component_options.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/color.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace ftxui;

void main_ui(void);

Component init_new_character_window(void);
Component init_load_character_window(void);
Component init_dice_roller_window(bool dice_check_states[], int dice_amounts[]);

#endif