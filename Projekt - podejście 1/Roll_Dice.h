#pragma once
#include <iostream>
#include <random>

using namespace std;

class Roll_Dice
{
public:
	int roll_d4();
	int roll_d6();
	int roll_d8();
	int roll_d10();
	int roll_d12();
	int roll_d20();
	bool is_it_draw(vector<int> tab_initiative);
	void same_initiative_solution(vector<int> &tab_initiative);
	Roll_Dice();
	~Roll_Dice();
};

