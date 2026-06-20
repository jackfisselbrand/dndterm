#include "ui.h"


bool show_create_character_window = false;
bool show_load_character_window = false;
bool show_dice_roller_window = false;

void main_ui(void) {
	App screen = App::Fullscreen();

	Component exit_button = Button("Exit", screen.ExitLoopClosure(), ButtonOption::Animated(Color::Red));
	Component create_character_button = Button("Create Character", [&] {show_create_character_window = true;}, ButtonOption::Animated());
	Component load_character_button = Button("Load Character", [&] {show_load_character_window = true;}, ButtonOption::Animated());
	Component dice_roller_button = Button("Dice Roller", [&] {show_dice_roller_window = true;}, ButtonOption::Animated()); 
	
	Component top_bar = Container::Horizontal({
		exit_button,
		create_character_button,
		load_character_button,
		dice_roller_button,
	});

	Component create_character_window = getCreateCharacterWindow();
	Component load_character_window = getLoadCharacterWindow();
	Component dice_roller_window = getDiceRollerWindow();

	Component main_ui = Container::Vertical({
		top_bar,
		Container::Stacked({
			create_character_window | Maybe(&show_create_character_window),
			load_character_window | Maybe(&show_load_character_window),
			dice_roller_window | Maybe(&show_dice_roller_window),
		}),
	});

	screen.Loop(main_ui);
}



Component getCreateCharacterWindow(void) {
	Component exit_button = Button("X", [&] {show_create_character_window = false;}, ButtonOption::Animated(Color::Red));
	Component top_bar = Container::Horizontal({
		exit_button,
	});

	Component window_contents = Container::Vertical({
		top_bar,
		Renderer([] {
			return text("The Create Character function is not yet implemented.");
		}),
	});

	Component window = Window({
		.inner = window_contents,
		.title = "Create Character"
	});

	return window;
}



Component getLoadCharacterWindow(void) {
	Component exit_button = Button("X", [&] {show_load_character_window = false;}, ButtonOption::Animated(Color::Red));
	Component top_bar = Container::Horizontal({
		exit_button,
	});

	Component window_contents = Container::Vertical({
		top_bar,
		Renderer([] {
			return text("The Load Character function is not yet implemented.");
		}),
	});

	Component window = Window({
		.inner = window_contents,
		.title = "Load Character"
	});

	return window;
}



Component getDiceRollerWindow(void) {
	Component exit_button = Button("X", [&] {show_dice_roller_window = false;}, ButtonOption::Animated(Color::Red));
	Component top_bar = Container::Horizontal({
		exit_button,
	});

	Component window_contents = Container::Vertical({
		top_bar,
		Renderer([] {
			return text("The Dice Roller function is not yet implemented.");
		}),
	});

	Component window = Window({
		.inner = window_contents,
		.title = "Dice Roller"
	});

	return window;
}