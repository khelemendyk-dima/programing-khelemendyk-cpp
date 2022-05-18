/**
 * @mainpage
 * # Загальне завдання
 * • Зробити шаблоний клас-список (на базі динамічного масиву), що має 
 * шаблоноване поле масиву (для будь-якого існуючого типу даних)
 * • Створити наступні методи:
 * 		– вивод вмісту масиву на екран;
 * 		– визначити індекс переданого елемента в заданому масиві;
 *  	– відсортувати елементи масиву;
 *		– визначити значення мінімального елемента масиву;
 * 		– додати елемент до кінця масиву;
 * 		– видалити елемент з масиву за індексом.
 *
 * @author Khelemendyk D.
 * @date 15-may-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 15-may-2022
 * @version 0.1
 */

#include "list.hpp"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю список int та додаю в нього 5 значень функцією {@link add};
 * - друкую масив за допомогою {@link print};
 * - видаляю елемент з 0 індексом шляхом виклику функції {@link remove} 
 * та знову друкую масив функцією {@link print};
 * - далі знаходю індекс елемента зі значенням 2 за допомогою {@link findIndex};
 * - потім сортую масив функцією {@link sort};
 * - також знаходю мінімальний елемент масива функцією {@link findMin};
 * - тепер виконую всі ці дії знову, але з масивом типу double;
 * - @return успішний код повернення з програми (0).
 */

int main()
{
	// working with int
	List<int> int_arr;
	int_arr.add(8);
	int_arr.add(3);
	int_arr.add(2);
	int_arr.add(1);
	int_arr.add(-6);
	cout << "Elements before removing first element: " << endl;
	int_arr.print();
	cout << "Elements after removing first element: " << endl;
	int_arr.remove(0);
	int_arr.print();
	cout << "Getting index of 2" << endl;
	cout << int_arr.findIndex(2) << endl;
	cout << "Sorting array" << endl;
	int_arr.sort();
	int_arr.print();
	cout << "Min element: " << int_arr.findMin() << endl;
	cout << endl;
	// working with double
	List<double> double_arr;
	double_arr.add(8.8);
	double_arr.add(3.1);
	double_arr.add(2.3);
	double_arr.add(1.2);
	double_arr.add(-6.9);
	cout << "Elements before removing first element: " << endl;
	double_arr.print();
	cout << "Elements after removing first element: " << endl;
	double_arr.remove(0);
	double_arr.print();
	cout << "Getting index of 2.3" << endl;
	cout << double_arr.findIndex(2.3) << endl;
	cout << "Sorting array" << endl;
	double_arr.sort();
	double_arr.print();
	cout << "Min element: " << double_arr.findMin() << endl;
	return 0;
}