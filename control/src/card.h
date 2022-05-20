#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <vector>
#include <cctype>
#include <cstdlib>
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * Клас "карта"
 */
class Card {
    private:
	int number;
	char suite;

    public:
	Card();
	Card(int n, char s);
	~Card();
	int getNumber() const;
	void setNumber(const int n);
	char getSuite() const;
	void setSuite(const char s);
	void printCard() const;
};
void writeToVector(vector<Card> &vec, string s);
void printVector(const vector<Card> &vec);
void sortCards(vector<Card> &vec);
void findCombination(const vector<Card> &vec);

#endif