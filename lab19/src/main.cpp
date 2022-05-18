/**
 * @mainpage
 * # Загальне завдання
 * Поширити попередню лабораторну роботу (потоковий i/o при роботі 
 * зі класами) таким чином:
 * • у базовому класі (прикладної галузі) перевантажити:
 * 		– оператор присвоювання;
 * 		– оператор порівняння (на вибір 2 протележних оператора: == , != ; < , >= ; > , <= );
 * 		– оператори введення / виведення;
 * • у класі-списку перевантажити:
 * 		– оператор індексування ( [ ] );
 * 		– оператори введення / виведення з акцентом роботи, у тому числі і з файлами.
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
 * @version 0.1
 */

/**
 * @file main.cpp
 * @brief Файл з демонстрацією роботи функцій
 * та методів оперування ними.
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
 * @version 0.1
 */

#include "list.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створюю 3 лампочки та друкую їх за допомогою оператора {@link operator<<};
 * - далі присвоюю друга лампочку третій шляхом виклику оператора 
 * {@link operator=};
 * - тепер порівнюю першу та третю лампочки двома операторами: 
 * {@link operator==} та {@link operator!=};
 * - створюю четверту лампочку та заповнюю її даними за допомогою {@link operator>>};
 * - створюю список та додаю в нього три лампочки шляхом виклику оператора 
 * {@link operator>>}, також друкую його оператором {@link operator<<};
 * - зараз створюю п'яту лампочку з даними другої лампочки списку, дані отримую 
 * за допомогою оператора {@link operator[]};
 * - потім відкриваю файл для читання та зчитую з нього дані, записую їх 
 * оператором {@link operator>>};
 * - нарешті, відкриваю файл для запису та записую в нього весь список 
 * за допомогою оператора {@link operator<<};
 * - @return успішний код повернення з програми (0).
 */

int main()
{
	Bulb bulb1;
	Bulb bulb2("no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21");
	Bulb bulb3;
	cout << "Printing bulbs by operator<<" << endl;
	cout << "Bulb1: " << bulb1;
	cout << "Bulb2: " << bulb2;
	cout << "Bulb3: " << bulb3;
	cout << "\nBulb3 before operator=" << endl;
	cout << bulb3 << endl;
	cout << "Bulb3 after operator=" << endl;
	bulb3 = bulb2;
	cout << bulb3 << endl;
	cout << "Comparing bulb1 and bulb3 by operator==" << endl;
	if (bulb3 == bulb1) {
		cout << "Operator==: Bulb3 and bulb1 are equal" << endl;
	} else {
		cout << "Operator==: Bulb3 and bulb1 are not equal" << endl;
	}
	cout << "\nComparing bulb1 and bulb3 by operator!=" << endl;
	if (bulb3 != bulb1) {
		cout << "Operator!=: Bulb3 and bulb1 are not equal" << endl;
	} else {
		cout << "Operator!=: Bulb3 and bulb1 are equal" << endl;
	}
	Bulb bulb4;
	cout << "\nFilling bulb4 by operator>>" << endl;
	cout << "Enter parameters: " << endl;
	cin >> bulb4;
	cout << "\nBulb4: " << bulb4 << endl;
	List list;
	cout << "Filling list with 3 bulbs by operator>>" << endl;
	cin >> list;
	cout << "Printing list by operator<<" << endl;
	cout << list;
	cout << "Getting bulb number 2 from list by operator[]" << endl;
	Bulb bulb5 = list[1];
	cout << bulb5;
	// openning file, read it and writting to the list by operator>>
	ifstream f("/home/dima/dev/programing-khelemendyk-cpp/lab19/assets/input.txt");
	if (!f.is_open()) {
		std::cerr << "Opening error f..." << endl;
	} else {
		f >> list;
	}
	f.close();
	// openning file output and writting data to it by operator<<
	ofstream fout;
	fout.open("/home/dima/dev/programing-khelemendyk-cpp/lab19/assets/output.txt");
	if (!fout.is_open()) {
		std::cerr << "Opening error fout..." << endl;
	} else {
		fout << list;
	}
	fout.close();
	return 0;
}