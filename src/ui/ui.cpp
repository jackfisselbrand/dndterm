#include "ui.h"

void main_ui(void) {
	auto screen = App::Fullscreen();

	auto new_character_window = Window({});
	auto load_character_window = Window({});
	auto dice_roller_window = Window({});

	bool dice_list_states[] = {false, false, false, false, false, false, false};
	int dice_list_amounts[] = {0, 0, 0, 0, 0, 0, 0};

	auto exit_button = Button("Exit", screen.ExitLoopClosure(), ButtonOption::Animated(Color::Red));/*
	Component new_character_button = Button("New Character", [&] {new_character_window = init_new_character_window();}, ButtonOption::Animated());
	Component load_character_button = Button("Load Character", [&] {load_character_window = init_load_character_window();}, ButtonOption::Animated());
	Component dice_roller_button = Button("Dice Roller", [&] {dice_roller_window = init_dice_roller_window(dice_list_states, dice_list_amounts);}, ButtonOption::Animated());
*/
	auto top_bar = Container::Horizontal({
		exit_button,/*
		new_character_button,
		load_character_button,
		dice_roller_button*/
	});

	auto main_ui = Renderer([&]{
		return vbox({
			top_bar->Render() /*| border,/*
			new_character_window->Render(),
			load_character_window->Render(),
			dice_roller_window->Render(),*/
		});
	});

	screen.Loop(top_bar);
}



Component init_new_character_window(void) {
	Component window_text = Renderer([]{
		return text("Create a new character...Once this feature is implemented.");
	});

	Component window_contents = Container::Vertical({
		window_text,
	});

	Component window = Window({
		.inner = window_contents,
		.title = "New Character"
	});

	return window;
}



Component init_load_character_window(void) {
	Component window_text = Renderer([]{
		return text("Load a character...Once this feature is implemented.");
	});

	Component window_contents = Container::Vertical({
		window_text,
	});

	Component window = Window({
		.inner = window_contents,
		.title = "Load Character"
	});

	return window;
}



Component init_dice_roller_window(bool dice_check_states[], int dice_amounts[]) {
	
	auto window_contents = Container::Vertical({
		Container::Horizontal({
			Checkbox("D100", &dice_check_states[0]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D20", &dice_check_states[1]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D12", &dice_check_states[2]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D10", &dice_check_states[3]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D8", &dice_check_states[4]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D6", &dice_check_states[5]),
			Input(),
		}),
		Container::Horizontal({
			Checkbox("D4", &dice_check_states[6]),
			Input(),
		}),
		Button("Exit", [] {return;}, ButtonOption::Animated()),
	});

	Component window = Window({
		.inner = window_contents,
		.title = "Dice Roller"
	});

	return window;
}