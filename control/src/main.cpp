/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

#include "card.h"

int main()
{
	vector<Card> cards;
	string s = "5H 3D 6H 7H 10H";
	writeToVector(cards, s);
	sortCards(cards);
	findCombination(cards);
	return 0;
}