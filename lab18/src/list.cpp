/**
 * @file list.cpp
 * @brief Файл з реалізацією функцій: конструктор, деструктор, 
 * гетери та сетери, додавання та видалення лампочки
 * у динамічному масиві, отримання лампочки за позицією, вивод списку 
 * на екран, знаходження згорівших лампочок, зчитування даних з файла 
 * та запис даних у файл.
 *
 * @author Khelemendyk D.
 * @date 12-may-2022
 */

#include "list.h"

List::List() : bulbs(NULL), size(0)
{
}
List::~List()
{
	for (size_t i = 0; i < size; i++) {
		delete (bulbs[i]);
	}
	delete[] bulbs;
}
size_t List::getSize() const
{
	return size;
}
void List::setSize(const size_t s)
{
	size = s;
}
void List::addBulb(const Bulb &bulb, size_t pos)
{
	// memory allocation
	Bulb **new_bulbs = new Bulb *[size + 1];
	if (pos > size)
		pos = size;
	// writting to the dynamic array
	for (size_t i = 0; i < pos; i++) {
		new_bulbs[i] = bulbs[i];
	}
	new_bulbs[pos] = new Bulb(bulb);
	for (size_t i = pos; i < size; i++) {
		new_bulbs[i + 1] = bulbs[i];
	}
	delete[] bulbs;
	bulbs = new_bulbs;
	size++;
}
void List::removeBulb(size_t pos)
{
	if (size == 0)
		return;
	Bulb **new_bulbs = new Bulb *[size - 1];
	if (pos >= size)
		pos = size - 1;
	for (size_t i = 0; i < pos; i++) {
		new_bulbs[i] = bulbs[i];
	}
	for (size_t i = pos; i < size - 1; i++) {
		new_bulbs[i] = bulbs[i + 1];
	}
	delete bulbs[pos];
	delete[] bulbs;
	bulbs = new_bulbs;
	size--;
}
Bulb &List::getBulb(size_t index)
{
	if (index >= size)
		index = size - 1;
	return bulbs[index][0];
}
void List::print() const
{
	for (size_t i = 0; i < size; i++) {
		cout << "Bulb " << i + 1 << ": ";
		cout << bulbs[i][0].toString();
	}
	cout << endl;
}
void List::findBurnedBulbs() const
{
	if (size == 0) {
		cout << "You don't have any bulb..." << endl;
	} else {
		int is_any_burned_bulb = 0;
		string yes = "yes";
		cout << "Burnt out bulb(s):" << endl;
		for (size_t i = 0; i < size; i++) {
			if (bulbs[i][0].getIsBurned() == yes) {
				cout << "Bulb " << i + 1 << ": ";
				cout << bulbs[i][0].toString();
				is_any_burned_bulb = 1;
			}
		}
		if (is_any_burned_bulb == 0) {
			cout << "Any burnt out bulb..." << endl;
		}
	}
}
void List::readFromFile(string &fileName)
{
	string line;
	std::ifstream f(fileName);
	if (!f.is_open()) {
		std::cerr << "Opening error readFromFile..." << endl;
		return;
	}
	// removing existing bulbs
	for (size_t i = 0; i < size; i++) {
		delete (bulbs[i]);
	}
	size = 0;
	// adding bulbs in the list
	size_t j = 0;
	while (getline(f, line)) {
		Bulb bulb(line);
		addBulb(bulb, j);
		j++;
	}
	f.close();
}
void List::writeToFile(string &fileName)
{
	std::ofstream fout;
	fout.open(fileName);
	if (!fout.is_open()) {
		std::cerr << "Opening error writeToFile..." << endl;
		return;
	}
	if (size == 0) {
		fout << "You don't have any bulb...";
	} else {
		for (size_t i = 0; i < size; i++) {
			fout << "Bulb " << i + 1 << ": ";
			fout << bulbs[i][0].toString();
		}
	}
	fout.close();
}