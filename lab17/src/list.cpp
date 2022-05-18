/**
 * @file list.cpp
 * @brief Файл з реалізацією функцій: конструктор, деструктор, 
 * гетери та сетери, додавання та видалення лампочки
 * у динамічному масиві, отримання лампочки за позицією, вивод списку, 
 * знаходження згорівших лампочок.
 *
 * @author Khelemendyk D.
 * @date 09-may-2022
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
		bulbs[i][0].print();
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
				bulbs[i][0].print();
				is_any_burned_bulb = 1;
			}
		}
		if (is_any_burned_bulb == 0) {
			cout << "Any burnt out bulb..." << endl;
		}
	}
}