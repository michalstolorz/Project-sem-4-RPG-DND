#include "drawing.h"



drawing::drawing()
{
	
}

void drawing::draw_sorceress(RenderWindow &app_window, Vector2i tab_co_sorceress)
{
	Vector2f tab_co_sorceress_float = static_cast<Vector2f>(tab_co_sorceress);
	sprite_sorceress.setPosition(tab_co_sorceress_float);
	app_window.draw(sprite_sorceress);
	return;
}

void drawing::draw_ranger(RenderWindow & app_window, Vector2i tab_co_ranger)
{
	Vector2f tab_co_ranger_float = static_cast<Vector2f>(tab_co_ranger);
	sprite_ranger.setPosition(tab_co_ranger_float);
	app_window.draw(sprite_ranger);
	return;
}

void drawing::draw_monk(RenderWindow & app_window, Vector2i tab_co_monk)
{
	Vector2f tab_co_monk_float = static_cast<Vector2f>(tab_co_monk);
	sprite_monk.setPosition(tab_co_monk_float);
	app_window.draw(sprite_monk);
	return;
}

void drawing::draw_paladin(RenderWindow & app_window, Vector2i tab_co_paladin)
{
	Vector2f tab_co_paladin_float = static_cast<Vector2f>(tab_co_paladin);
	sprite_paladin.setPosition(tab_co_paladin_float);
	app_window.draw(sprite_paladin);
	return;
}

void drawing::draw_warrior(RenderWindow & app_window, Vector2i tab_co_warrior)
{
	Vector2f tab_co_warrior_float = static_cast<Vector2f>(tab_co_warrior);
	sprite_warrior.setPosition(tab_co_warrior_float);
	app_window.draw(sprite_warrior);
	return;
}

void drawing::draw_blue_dragon(RenderWindow &app_window, Vector2i tab_co_blue_dragon)
{
	Vector2f tab_co_blue_dragon_float = static_cast<Vector2f>(tab_co_blue_dragon);
	sprite_blue_dragon.setPosition(tab_co_blue_dragon_float);
	app_window.draw(sprite_blue_dragon);
	return;
}

void drawing::draw_fire_gigant(RenderWindow & app_window, Vector2i tab_co_fire_gigant)
{
	Vector2f tab_co_fire_gigant_float = static_cast<Vector2f>(tab_co_fire_gigant);
	sprite_fire_gigant.setPosition(tab_co_fire_gigant_float);
	app_window.draw(sprite_fire_gigant);
	return;
}

void drawing::draw_devil(RenderWindow & app_window, Vector2i tab_co_devil)
{
	Vector2f tab_co_devil_float = static_cast<Vector2f>(tab_co_devil);
	sprite_devil.setPosition(tab_co_devil_float);
	app_window.draw(sprite_devil);
	return;
}

void drawing::draw_shield_guardian(RenderWindow & app_window, Vector2i tab_co_shield_guardian)
{
	Vector2f tab_co_shield_guardian_float = static_cast<Vector2f>(tab_co_shield_guardian);
	sprite_shield_guardian.setPosition(tab_co_shield_guardian_float);
	app_window.draw(sprite_shield_guardian);
	return;
}

void drawing::draw_earth_elemental(RenderWindow & app_window, Vector2i tab_co_earth_elemental)
{
	Vector2f tab_co_earth_elemental_float = static_cast<Vector2f>(tab_co_earth_elemental);
	sprite_earth_elemental.setPosition(tab_co_earth_elemental_float);
	app_window.draw(sprite_earth_elemental);
	return;
}

void drawing::draw_movement_marker(RenderWindow &app_window, Vector2i tab_co_movement_marker)
{
	Vector2f tab_co_movement_marker_float = static_cast<Vector2f>(tab_co_movement_marker);
	sprite_movement_marker.setPosition(tab_co_movement_marker_float);
	app_window.draw(sprite_movement_marker);
	return;
}

void drawing::draw_hitbox_move_error(RenderWindow & app_window, Vector2i tab_co_movement_marker_error)
{
	Vector2f tab_co_movement_marker_error_float = static_cast<Vector2f>(tab_co_movement_marker_error);
	sprite_hitbox_move_error.setPosition(tab_co_movement_marker_error_float);
	app_window.draw(sprite_hitbox_move_error);
	return;
}

void drawing::draw_your_choice(RenderWindow & app_window)
{
	sprite_your_choice.setPosition(400, 700);
	app_window.draw(sprite_your_choice);
	return;
}

void drawing::draw_terminal(RenderWindow & app_window)
{
	RectangleShape rectangle;
	rectangle.setPosition(0, 900);
	rectangle.setSize(Vector2f(1600, 100));
	rectangle.setTexture(&texture_terminal);
	app_window.draw(rectangle);
}

void drawing::draw_terrain(RenderWindow &app_window)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sprite_terrain.setPosition(0 + 400 * j, 0 + 400 * i);
			app_window.draw(sprite_terrain);
		}
	}
	return;
}

void drawing::draw_terrain_blur(RenderWindow & app_window)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sprite_terrain_blur.setPosition(0 + 400 * j, 0 + 400 * i);
			app_window.draw(sprite_terrain_blur);
		}
	}
	return;
}

void drawing::draw_choose_the_party(RenderWindow & app_window)
{
	sprite_choose_the_party.setPosition(137, 300);
	app_window.draw(sprite_choose_the_party);
	return;
}

void drawing::draw_choose_an_enemy(RenderWindow & app_window)
{
	sprite_choose_an_enemy.setPosition(624, 300);
	app_window.draw(sprite_choose_an_enemy);
	return;
}

void drawing::draw_ready_for_battle(RenderWindow & app_window)
{
	sprite_ready_for_battle.setPosition(1111, 300);
	app_window.draw(sprite_ready_for_battle);
	return;
}

void drawing::draw_button1(RenderWindow & app_window, Vector2i tab_co_button)
{
	Vector2f tab_co_buttonr_float = static_cast<Vector2f>(tab_co_button);
	sprite_button1.setPosition(tab_co_buttonr_float);
	app_window.draw(sprite_button1);
	return;
}

void drawing::draw_button2(RenderWindow & app_window, Vector2i tab_co_button)
{
	Vector2f tab_co_buttonr_float = static_cast<Vector2f>(tab_co_button);
	sprite_button2.setPosition(tab_co_buttonr_float);
	app_window.draw(sprite_button2);
	return;
}

void drawing::draw_button3(RenderWindow & app_window, Vector2i tab_co_button)
{
	Vector2f tab_co_buttonr_float = static_cast<Vector2f>(tab_co_button);
	sprite_button3.setPosition(tab_co_buttonr_float);
	app_window.draw(sprite_button3);
	return;
}

void drawing::draw_button4(RenderWindow & app_window, Vector2i tab_co_button)
{
	Vector2f tab_co_buttonr_float = static_cast<Vector2f>(tab_co_button);
	sprite_button4.setPosition(tab_co_buttonr_float);
	app_window.draw(sprite_button4);
	return;
}

void drawing::draw_button5(RenderWindow & app_window, Vector2i tab_co_button)
{
	Vector2f tab_co_buttonr_float = static_cast<Vector2f>(tab_co_button);
	sprite_button5.setPosition(tab_co_buttonr_float);
	app_window.draw(sprite_button5);
	return;
}


void drawing::load_textures()
{
	if (!texture_terrain.loadFromFile("teren_testowanie.png")) throw 0;
	if (!texture_terrain_blur.loadFromFile("teren_testowanie_blur.png")) throw 0;
	//
	if (!texture_choose_the_party.loadFromFile("choose_the_party_butt.png")) throw 0;
	if (!texture_choose_an_enemy.loadFromFile("choose_an_enemy_butt.png")) throw 0;
	if (!texture_ready_for_battle.loadFromFile("ready_to_battle.png")) throw 0;
	if (!texture_button1.loadFromFile("button_1.png")) throw 0;
	if (!texture_button2.loadFromFile("button_2.png")) throw 0;
	if (!texture_button3.loadFromFile("button_3.png")) throw 0;
	if (!texture_button4.loadFromFile("button_4.png")) throw 0;
	if (!texture_button5.loadFromFile("button_5.png")) throw 0;
	if (!texture_terminal.loadFromFile("terminal.png")) throw 0;
	//characters
	if (!texture_sorceress.loadFromFile("sorceress.png")) throw 0;
	if (!texture_ranger.loadFromFile("ranger.png")) throw 0;
	if (!texture_monk.loadFromFile("monk.png")) throw 0;
	if (!texture_paladin.loadFromFile("paladin.png")) throw 0;
	if (!texture_warrior.loadFromFile("warrior.png")) throw 0;
	//enemies
	if (!texture_blue_dragon.loadFromFile("blue_dragon.png")) throw 0;
	if (!texture_fire_gigant.loadFromFile("fire_gigant.png")) throw 0;
	if (!texture_devil.loadFromFile("devil.png")) throw 0;
	if (!texture_shield_guardian.loadFromFile("shield_guardian.png")) throw 0;
	if (!texture_earth_elemental.loadFromFile("earth_elemental.png")) throw 0;
	//
	if (!texture_movement_marker.loadFromFile("kwadrat_znacznik.png")) throw 0;
	if (!texture_hitbox_move_error.loadFromFile("movement_marker_error.png")) throw 0;
	if (!texture_your_choice.loadFromFile("your_choice.png")) throw 0;
	return;
}

void drawing::load_sprites()
{
	sprite_terrain.setTexture(texture_terrain);
	sprite_terrain_blur.setTexture(texture_terrain_blur);
	//
	sprite_choose_the_party.setTexture(texture_choose_the_party);
	sprite_choose_an_enemy.setTexture(texture_choose_an_enemy);
	sprite_ready_for_battle.setTexture(texture_ready_for_battle);
	sprite_button1.setTexture(texture_button1);
	sprite_button2.setTexture(texture_button2);
	sprite_button3.setTexture(texture_button3);
	sprite_button4.setTexture(texture_button4);
	sprite_button5.setTexture(texture_button5);
	//sprite_terminal.setTexture(texture_terminal);
	//
	sprite_sorceress.setTexture(texture_sorceress);
	sprite_ranger.setTexture(texture_ranger);
	sprite_monk.setTexture(texture_monk);
	sprite_paladin.setTexture(texture_paladin);
	sprite_warrior.setTexture(texture_warrior);
	//
	sprite_blue_dragon.setTexture(texture_blue_dragon);
	sprite_fire_gigant.setTexture(texture_fire_gigant);
	sprite_devil.setTexture(texture_devil);
	sprite_shield_guardian.setTexture(texture_shield_guardian);
	sprite_earth_elemental.setTexture(texture_earth_elemental);
	//
	sprite_movement_marker.setTexture(texture_movement_marker);
	sprite_hitbox_move_error.setTexture(texture_hitbox_move_error);
	sprite_your_choice.setTexture(texture_your_choice);
	return;
}

void drawing::rerender(RenderWindow &app_window, Postac *tab_characters[4])
{
	for (int i = 0; i < 4; i++) 
	{
		if (dynamic_cast<Czarodziejka*>(tab_characters[i]) && tab_characters[i]->check_if_alive())
			draw_sorceress(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Ranger*>(tab_characters[i]) && tab_characters[i]->check_if_alive())
			draw_ranger(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Warrior*>(tab_characters[i]) && tab_characters[i]->check_if_alive())
			draw_warrior(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Paladin*>(tab_characters[i]) && tab_characters[i]->check_if_alive())
			draw_paladin(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Monk*>(tab_characters[i]) && tab_characters[i]->check_if_alive())
			draw_monk(app_window, tab_characters[i]->get_tab_co_character().back());
		//
		else if (dynamic_cast<Blue_Dragon*>(tab_characters[i]))
			draw_blue_dragon(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Fire_Gigant*>(tab_characters[i]))
			draw_fire_gigant(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Devil*>(tab_characters[i]))
			draw_devil(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Earth_Elemental*>(tab_characters[i]))
			draw_earth_elemental(app_window, tab_characters[i]->get_tab_co_character().back());
		else if (dynamic_cast<Shield_Guardian*>(tab_characters[i]))
			draw_shield_guardian(app_window, tab_characters[i]->get_tab_co_character().back());
	}
	draw_terminal(app_window);
	return;
}

void drawing::true_rerender(RenderWindow & app_window, Postac * tab_characters[4], vector<string>& what_happend_in_battle, drawing draw_object, int id_number)
{
	terminal term;
	draw_object.draw_terrain(app_window);
	draw_object.rerender(app_window, tab_characters);
	term.draw_string(app_window, tab_characters[id_number]->get_name(), term.get_tab_co_name(), 30);
	term.draw_string(app_window, term.get_HP_string(), term.get_tab_co_HP_string(), 30);
	term.draw_string(app_window, to_string(tab_characters[id_number]->HP), term.get_tab_co_HP_number(), 30);
	term.draw_action_menu(app_window);
	term.draw_what_happend_terminal(app_window, what_happend_in_battle);
	return;
}


drawing::~drawing()
{
}
