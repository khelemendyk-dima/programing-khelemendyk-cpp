/**
 * @file entity.cpp
 * @brief Файл з реалізацією функцій: конструктор за 
 * замовчуванням, копіюванням та конструктор з аргументами,
 * деструктор, гетери/сетери та вивід лампочки на екран.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 */

#include "card.h"

Card::Card()
{
}
Card::Card(int n, char s)
{
	number = n;
	suite = s;
}
Card::~Card()
{
}
int Card::getNumber() const
{
	return number;
}
void Card::setNumber(const int n)
{
	number = n;
}
char Card::getSuite() const
{
	return suite;
}
void Card::setSuite(const char s)
{
	suite = s;
}
void Card::printCard() const
{
	cout << number << suite;
}

void writeToVector(vector<Card> &vec, string s)
{
	int mode = 0;
	int num = 0;
	char suite;
	for (size_t i = 0; i < s.size(); i++) {
		if (s[i] != ' ') {
			if (mode == 0) {
				if (s[i] == 'J')
					num = 11;
				else if (s[i] == 'Q')
					num = 12;
				else if (s[i] == 'K')
					num = 13;
				else if (s[i] == 'A')
					num = 14;
				else
					num = atoi(&s[i]);
				mode++;
			} else {
				suite = s[i];
			}
		} else {
			Card card(num, suite);
			vec.push_back(card);
			mode = 0;
		}
	}
	Card card(num, suite);
	vec.push_back(card);
}
void printVector(const vector<Card> &vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
		vec[i].printCard();
		cout << " ";
	}
	cout << endl;
}
void sortCards(vector<Card> &vec)
{
	for (size_t i = 0; i < vec.size(); i++) {
		for (size_t j = 0; j < vec.size() - 1; j++) {
			int num1 = vec[j].getNumber();
			int num2 = vec[j + 1].getNumber();
			if (num1 < num2) {
				Card temp = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = temp;
			}
		}
	}
}
void findCombination(const vector<Card> &vec)
{
	// suites is equal
	int eq_suite = 1;
	char symbol_suite = vec[0].getSuite();
	for (size_t i = 0; i < vec.size(); i++) {
		if (symbol_suite != vec[i].getSuite()) {
			eq_suite = 0;
			break;
		}
	}
	int num1 = vec[0].getNumber();
	int num2 = vec[1].getNumber();
	int num3 = vec[2].getNumber();
	int num4 = vec[3].getNumber();
	int num5 = vec[4].getNumber();
	int is_strit_flash = 0;
	int is_flash_royale = 0;
	int is_kare = 0;
	int is_full_house = 0;
	int is_flash = 0;
	int is_strit = 0;
	int is_set = 0;
	int is_two_pairs = 0;
	int is_one_pair = 0;
	int is_max_number = 0;
	if (eq_suite == 1) {
		// strit-flash
		if (num1 != 14) {
			for (size_t i = 0; i < vec.size() - 1; i++) {
				if (vec[i].getNumber() == (vec[i + 1].getNumber() + 1)) {
					is_strit_flash = 1;
				} else {
					is_strit_flash = 0;
					break;
				}
			}
		}
		// flash-royale
		if (num1 == 14) {
			for (size_t i = 0; i < vec.size() - 1; i++) {
				if (vec[i].getNumber() == (vec[i + 1].getNumber() + 1)) {
					is_flash_royale = 1;
				} else {
					is_flash_royale = 0;
					break;
				}
			}
		}
		// kare
		if ((num2 == num3) && (num3 == num4) && (num4 == num5)) {
			is_kare = 1;
		}
		// full house
		if ((num1 == num2) && (num2 == num3) && (num4 == num5)) {
			is_full_house = 1;
		}
		// flash
		is_flash = 1;
	} else if (eq_suite == 0) {
		// kare
		if ((num2 == num3) && (num3 == num4) && (num4 == num5)) {
			is_kare = 1;
		}
		// full house
		if ((num1 == num2) && (num2 == num3) && (num4 == num5)) {
			is_full_house = 1;
		}
		// strit
		if (num1 == 14 && num2 == 5) {
			for (size_t i = 1; i < vec.size() - 1; i++) {
				if (vec[i].getNumber() == (vec[i + 1].getNumber() + 1)) {
					is_strit = 1;
				} else {
					is_strit = 0;
					break;
				}
			}
		} else {
			for (size_t i = 0; i < vec.size() - 1; i++) {
				if (vec[i].getNumber() == (vec[i + 1].getNumber() + 1)) {
					is_strit = 1;
				} else {
					is_strit = 0;
					break;
				}
			}
		}
		// set
		if (((num1 == num2) && (num2 == num3)) || ((num2 == num3) && (num3 == num4)) || ((num3 == num4) && (num4 == num5))) {
			is_set = 1;
		}
		// two pairs
		if (((num1 == num2) && (num3 == num4)) || ((num2 == num3) && (num4 == num5))) {
			is_two_pairs = 1;
		}
		// one pair
		for (size_t i = 0; i < vec.size() - 1; i++) {
			if (vec[i].getNumber() == vec[i + 1].getNumber()) {
				is_one_pair = 1;
			}
		}
		// max number
		if (num1 == 14) {
			is_max_number = 1;
		}
	}
	if (is_strit_flash) {
		cout << "Strit-flash" << endl;
	} else if (is_flash_royale) {
		cout << "Flash-royale" << endl;
	} else if (is_kare) {
		cout << "Kare" << endl;
	} else if (is_full_house) {
		cout << "Full house" << endl;
	} else if (is_flash) {
		cout << "Flash" << endl;
	} else if (is_strit) {
		cout << "Strit" << endl;
	} else if (is_set) {
		cout << "Set" << endl;
	} else if (is_two_pairs) {
		cout << "Two pairs" << endl;
	} else if (is_one_pair) {
		cout << "One pair" << endl;
	} else if (is_max_number) {
		cout << "Max number" << endl;
	} else {
		cout << "Any combination was found..." << endl;
	}
}