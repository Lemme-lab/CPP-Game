#include <iostream>
#include <string>
#include "header.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int lenght = 10;
int player_pos = 0;
bool play_again = true;
bool leave = false;
char input;
char input_YN;
int Postion_Wert;
string Spielfeld("|");
int sp_länge;
int checker = 0;

void finish()
{
	while (checker == 0) {
		cout << "Wollen sie weiter Spielen Y/N" << endl;
		cin >> input_YN;
		if (input_YN == 'Y' || input_YN == 'y') {
			play_again = true;
			checker = 1;
		}

		else if (input_YN == 'N' || input_YN == 'n') {
			leave = true;
			checker = 1;

		}
		else {
			cout << "Failed" << endl;
		}


	}



}

void move()
{
	if (Spielfeld.at(sp_länge) == 'P') {
		cout << endl;
		cout << "Gewonnen" << endl;
		play_again = false;
		Spielfeld = "|";
	}
	else {

		cin >> input;

		if (input == 'd') {
			for (int i = 0; i < sp_länge; i++) {
				if (Spielfeld.at(i) == 'P' && Spielfeld.at(i + 1) != '|') {
					Postion_Wert = i;
					Spielfeld[i] = '.';
					Spielfeld[i + 1] = 'P';
					i = 12;
				}
			}
			cout << Spielfeld;
		}


		if (input == 'a') {

			for (int i = 0; i < sp_länge; i++) {

				if (Spielfeld.at(i) == 'P' && Spielfeld.at(i - 1) != '|') {
					Postion_Wert = i;
					Spielfeld[i] = '.';
					Spielfeld[i - 1] = 'P';
					i = 12;
				}
			}
			cout << Spielfeld;
		}
	}
}

void create_map()
{
	checker = 0;

	for (int var = 0; var <= lenght; var++) {

		if (var != player_pos && var != lenght) {
			Spielfeld = Spielfeld + '.';
		}
		else if (var == player_pos) {
			Spielfeld = Spielfeld + 'P';
		}
		else if (var == lenght) {
			Spielfeld = Spielfeld + '|';
			sp_länge = lenght;
		}
	}
	cout << Spielfeld;
}

void game()
{

	while (leave == false) {

		create_map();

		while (play_again == true) {

			move();
		}
		finish();
	}
}