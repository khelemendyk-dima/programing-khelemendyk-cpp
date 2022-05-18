#ifndef LAB_22_LIST_HPP
#define LAB_22_LIST_HPP

/**
 * @file list.hpp
 * @brief Файл з описом функцій: вивод вектора на екран, знаходження 
 * згорівших лампочок, та сортування лампочок за зворотнім лічільником.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

#include "entity.h"

/**
 * Вивод списка.
 *
 * Функція друкує вектор на екран.Отримує вектор лампочок.
 */
void print(const vector<Bulb> &vector);
/**
 * Знаходження згорівших лампочок.
 *
 * Функція перевіряє чи є лампочки взагалі, якщо є - перевіряє 
 * на наявність згорівшої лампочки, та при наявності хоча б однієї 
 * згорівшої лампочки - друкує її. Отримує вектор лампочок.
 */
void findBurnedBulbs(const vector<Bulb> &vector);
/**
 * Функтор.
 *
 * Об'єкт класа з перенавантаженим оператором(). Порівнює два 
 * цілих числа.
 */
class compare_class {
    public:
	bool operator()(int a, int b)
	{
		return (a > b);
	}
};
/**
 * Сортування лампочок за зворотнім лічильником.
 *
 * Функція сортує лампочки за зворотнім лічильником у порядку 
 * збільшення. Отримує вектор лампочок та функтор.
 */
template <class ComparisonFunctor> void sortBulbs(vector<Bulb> &vector, ComparisonFunctor c)
{
	for (size_t i = 0; i < vector.size(); i++) {
		for (size_t j = 0; j < vector.size() - 1; j++) {
			int a = vector[j].getReverseCounter();
			int b = vector[j + 1].getReverseCounter();
			if (c(a, b)) {
				Bulb temp = vector[j];
				vector[j] = vector[j + 1];
				vector[j + 1] = temp;
			}
		}
	}
}
void print(const vector<Bulb> &vector)
{
	for (size_t i = 0; i < vector.size(); i++) {
		cout << "Bulb " << i + 1 << ": ";
		vector[i].print();
	}
	cout << endl;
}
void findBurnedBulbs(const vector<Bulb> &vector)
{
	if (vector.size() == 0) {
		cout << "You don't have any bulb..." << endl;
	} else {
		int is_any_burned_bulb = 0;
		string yes = "yes";
		cout << "Burnt out bulb(s):" << endl;
		for (size_t i = 0; i < vector.size(); i++) {
			if (vector[i].getIsBurned() == yes) {
				cout << "Bulb " << i + 1 << ": ";
				vector[i].print();
				is_any_burned_bulb = 1;
			}
		}
		if (is_any_burned_bulb == 0) {
			cout << "Any burnt out bulb..." << endl;
		}
	}
}

#endif