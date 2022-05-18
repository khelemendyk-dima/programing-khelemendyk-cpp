/**
 * @mainpage
 * # Загальне завдання
 * Поширити реалізацію лабораторної роботи "Динамічні масиви" 
 * наступним шляхом:
 * 		• замінити масив та CRUD (create/read/update/delete) 
 * методи роботи з ним на використання STL; 
 * 		• додати функцію сортування колекції з використанням функтора.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

#include "list.hpp"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю 4 лампочки, використовуючи 3 реалізованних конструкторів, 
 * та створюю вектор;
 * - далі додаю лампочки в вектор 4 рази у кінець функцією push_back та 
 * друкую їх за допомогою функції {@link print};
 * - потім видаляю першу лампочку шляхом виклику функції erase;
 * - також знаходю згорівші лампочки за допомогою функції 
 * {@link findBurnedBulbs};
 * - нарешті, сортую лампочки за зворотнім лічильником функцією 
 * {@link sortBulbs} та друкую результат функцією {@link print};
 * - @return успішний код повернення з програми (0).
 */

int main()
{
	Bulb bulb1;
	Bulb bulb2("no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21");
	Bulb bulb3("yes", "yes", "TOV Pont", 152, 5, 3600, "Square", "E63");
	Bulb bulb4("no", "no", "Kapusta", 13, 20, 1234, "Octangle", "E55");
	vector<Bulb> vector;
	cout << "Adding bulbs and print them" << endl;
	vector.push_back(bulb1);
	vector.push_back(bulb2);
	vector.push_back(bulb3);
	vector.push_back(bulb4);
	vector.push_back(bulb1);
	print(vector);
	cout << "Removing bulb" << endl;
	vector.erase(vector.begin() + 0);
	print(vector);
	cout << "Finding burnt out bulbs" << endl;
	findBurnedBulbs(vector);
	cout << "Sorting bulbs by reverse counter" << endl;
	compare_class functor;
	sortBulbs(vector, functor);
	print(vector);
	return 0;
}