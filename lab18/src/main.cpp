/**
 * @mainpage
 * # Загальне завдання
 * Поширити попередню лабораторну роботу таким чином:
 * • замінити метод виводу інформації про об’єкт на метод, 
 * що повертає рядок-інформацію про об’єкт, який далі 
 * можна виводити на екран;
 * • замінити метод вводу інформації про об’єкт на метод, 
 * що приймає рядок з інформацією про об’єкт, обробляє 
 * його та створює об’єкт на базі цієї інформації;
 * • поширити клас-список, шляхом реалізації методів роботи 
 * з файлами за допомогою файлових потоків (fstream) 
 * (читання та запис).
 *
 * @author Khelemendyk D.
 * @date 12-may-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 12-may-2022
 * @version 0.1
 */

#include "list.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю 4 лампочки, використовуючи 4 реалізованних конструктора;
 * - друкую четверту лампочку шляхом виклику функції {@link toString};
 * - далі створюю список та додаю в нього ці лампочки 
 * функцією {@link addBulb} та друкую його за допомогою {@link print};
 * - потім створюю дві строки: одна з адресом файла, котрий потрібно 
 * зчитати, інша - з адресом файла для запису даних; 
 * - тепер зчитую дані з файла шляхом виклику функції {@link readFromFile};
 * - нарешті, записую дані у файл функцією {@link writeToFile};
 * - @return успішний код повернення з програми (0).
 */

int main()
{
	Bulb bulb1;
	Bulb bulb2("no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21");
	Bulb bulb3(bulb1);
	string data_for_bulb4 = "    yes   ,  no  ,   TOV Pont   ,  33 ,  10    ,  3600 ,    quad , E42  .";
	Bulb bulb4(data_for_bulb4);
	cout << "Printing bulb4" << endl;
	cout << "Bulb 4: " << bulb4.toString() << endl;
	List list;
	cout << "Adding 4 bulbs and printing them" << endl;
	list.addBulb(bulb1);
	list.addBulb(bulb2, 1);
	list.addBulb(bulb3, 2);
	list.addBulb(bulb4, 4);
	list.print();
	string input_file = "/home/dima/dev/programing-khelemendyk-cpp/lab18/assets/input.txt";
	string output_file = "/home/dima/dev/programing-khelemendyk-cpp/lab18/assets/output.txt";
	list.readFromFile(input_file);
	list.writeToFile(output_file);
	return 0;
}