#include "terminal.h"



terminal::terminal()
{
	set_co();
}

void terminal::draw_string(RenderWindow &app_window, string informations, Vector2i position, int size)
{
	Vector2f position_float = static_cast<Vector2f>(position);
	Text text;
	Font font;
	font.loadFromFile("Enchanted Land.otf");
	text.setFont(font);
	text.setString(informations);
	text.setCharacterSize(size);
	text.setPosition(position_float);
	text.setFillColor(Color::White);
	app_window.draw(text);
	return;
}

void terminal::draw_action_menu(RenderWindow & app_window)
{
	draw_string(app_window, "1. Ruch", tab_co_actions1, 30);
	draw_string(app_window, "2. Akcja", tab_co_actions2, 30);
	draw_string(app_window, "3. Koniec tury", tab_co_actions3, 30);
	return;
}

void terminal::draw_action_menu_paladin(RenderWindow & app_window)
{
	draw_string(app_window, "1. Atak", tab_co_actions1_character, 30);
	draw_string(app_window, "2. Sacred weapon", tab_co_actions2_character, 30);
	draw_string(app_window, "3. Lay on Hands", tab_co_actions3_character, 30);
	return;
}

void terminal::draw_heal_string(RenderWindow & app_window)
{
	draw_string(app_window, "Kogo chcesz uleczyc?", tab_co_actions1_paladin, 30);
	return;
}

void terminal::draw_paladin_heal_person(RenderWindow & app_window, string who_is_healed, int id_number)
{
	if (id_number == 0)
		draw_string(app_window, who_is_healed, tab_co_actions2_paladin, 30);
	else if (id_number == 1)
		draw_string(app_window, who_is_healed, tab_co_actions3_paladin, 30);
	else if (id_number == 2)
		draw_string(app_window, who_is_healed, tab_co_actions4_paladin, 30);
}

void terminal::draw_action_menu_warrior(RenderWindow & app_window)
{
	draw_string(app_window, "1. Atak", tab_co_actions1_character, 30);
	draw_string(app_window, "2. Action surge", tab_co_actions2_character, 30);
	draw_string(app_window, "3. Second wind", tab_co_actions3_character, 30);
	return;
}

void terminal::draw_action_menu_monk(RenderWindow & app_window)
{
	draw_string(app_window, "1. Atak", tab_co_actions1_character, 30);
	draw_string(app_window, "2. Flurry of blows", tab_co_actions2_character, 30);
	draw_string(app_window, "3. Wholeness body", tab_co_actions3_character, 30);
	return;
}

void terminal::draw_action_menu_sorceress(RenderWindow & app_window)
{
	draw_string(app_window, "Jakie zaklecie chcesz rzucic?", tab_co_actions1_sorceress, 30);
	draw_string(app_window, "1. Cantrip", tab_co_actions2_sorceress, 30);
	draw_string(app_window, "2. Pierwszo poziomowe", tab_co_actions3_sorceress, 30);
	draw_string(app_window, "3. Drugo poziomowe", tab_co_actions4_sorceress, 30);
	draw_string(app_window, "4. Trzecio poziomowe", tab_co_actions5_sorceress, 30);
	return;
}

void terminal::draw_sorceress_spells(RenderWindow & app_window, string first_spell, string second_spell)
{
	draw_string(app_window, "1. " + first_spell, tab_co_actions6_sorceress, 30);
	draw_string(app_window, "2. " + second_spell, tab_co_actions7_sorceress, 30);
	return;
}

void terminal::draw_haste_characters(RenderWindow & app_window, string tab_names[2])
{
	draw_string(app_window, "Na kogo rzucic haste?", tab_co_actions6_sorceress, 30);
	draw_string(app_window, tab_names[0], tab_co_actions7_sorceress, 30);
	draw_string(app_window, tab_names[1], tab_co_actions8_sorceress, 30);
	return;
}

void terminal::draw_what_happend_terminal(RenderWindow & app_window, vector<string> what_happend)
{
	draw_string(app_window, what_happend[what_happend.size() - 3], tab_co_what_happend_terminal1, 30);
	draw_string(app_window, what_happend[what_happend.size() - 2], tab_co_what_happend_terminal2, 30);
	draw_string(app_window, what_happend[what_happend.size() - 1], tab_co_what_happend_terminal3, 30);
	return;
}

void terminal::draw_you_win(RenderWindow & app_window)
{
	Vector2i you_win;
	you_win.x = 300;
	you_win.y = 100;
	draw_string(app_window, "KONIEC   GRY", you_win, 200);
	you_win.x = 300;
	you_win.y = 400;
	draw_string(app_window, "PRZECIWNIK", you_win, 200);
	you_win.y = 630;
	draw_string(app_window, " POKONANY", you_win, 200);
	return;
}

void terminal::draw_you_lose(RenderWindow & app_window)
{
	Vector2i you_lose;
	you_lose.x = 300;
	you_lose.y = 100;
	draw_string(app_window, "KONIEC   GRY", you_lose, 200);
	you_lose.x = 180;
	you_lose.y = 400;
	draw_string(app_window, "BOHATEROWIE", you_lose, 200);
	you_lose.x = 300;
	you_lose.y = 630;
	draw_string(app_window, " POKONANI", you_lose, 200);
	return;
}

void terminal::set_co()
{
	tab_co_name.x = 75;
	tab_co_name.y = 902;
	tab_co_HP_string.x = 75;
	tab_co_HP_string.y = 930;
	tab_co_HP_number.x = 115;
	tab_co_HP_number.y = 930;
	//
	tab_co_actions1.x = 170;
	tab_co_actions1.y = 902;
	tab_co_actions2.x = 170;
	tab_co_actions2.y = 927;
	tab_co_actions3.x = 170;
	tab_co_actions3.y = 952;
	//
	tab_co_actions1_character.x = 290;
	tab_co_actions1_character.y = 902;
	tab_co_actions2_character.x = 290;
	tab_co_actions2_character.y = 927;
	tab_co_actions3_character.x = 290;
	tab_co_actions3_character.y = 952;
	//
	tab_co_what_happend_terminal1.x = 950;
	tab_co_what_happend_terminal1.y = 902;
	tab_co_what_happend_terminal2.x = 950;
	tab_co_what_happend_terminal2.y = 927;
	tab_co_what_happend_terminal3.x = 950;
	tab_co_what_happend_terminal3.y = 952;
	//
	tab_co_actions1_sorceress = tab_co_actions1_character;
	tab_co_actions2_sorceress = tab_co_actions2_character;
	tab_co_actions3_sorceress = tab_co_actions3_character;
	tab_co_actions4_sorceress.x = 530;
	tab_co_actions4_sorceress.y = 902;
	tab_co_actions5_sorceress.x = 530;
	tab_co_actions5_sorceress.y = 927;
	tab_co_actions6_sorceress.x = 720;
	tab_co_actions6_sorceress.y = 902;
	tab_co_actions7_sorceress.x = 720;
	tab_co_actions7_sorceress.y = 927;
	tab_co_actions8_sorceress.x = 720;
	tab_co_actions8_sorceress.y = 952;
	//
	tab_co_actions1_paladin.x = 435;
	tab_co_actions1_paladin.y = 902;
	tab_co_actions2_paladin.x = 435;
	tab_co_actions2_paladin.y = 927;
	tab_co_actions3_paladin.x = 435;
	tab_co_actions3_paladin.y = 952;
	tab_co_actions4_paladin.x = 620;
	tab_co_actions4_paladin.y = 902;
	return;
}

Vector2i terminal::get_tab_co_name()
{
	return tab_co_name;
}

Vector2i terminal::get_tab_co_HP_string()
{
	return tab_co_HP_string;
}

Vector2i terminal::get_tab_co_HP_number()
{
	return tab_co_HP_number;
}

Vector2i terminal::get_tab_co_action1()
{
	return tab_co_actions1;
}

Vector2i terminal::get_tab_co_action2()
{
	return tab_co_actions2;
}

Vector2i terminal::get_tab_co_action3()
{
	return tab_co_actions3;
}

string terminal::get_HP_string()
{
	return HP_string;
}



terminal::~terminal()
{
}
