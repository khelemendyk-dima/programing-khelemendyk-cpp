/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій: додавання, видалення,
 * отримання лампочки по індексу, конструктор зі строкою та повернення 
 * рядка-інформації, оператор присвоювання, порівняння, індексування(для списку).
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
 * @version 0.1
 */

#include "list.h"
#include <gtest/gtest.h>

/*
 * Верифікація роботи функції {@link operator==}
 * на основі вхідних даних лампочок та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, operatorEqual_test)
{
	Bulb data1 = { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" };
	Bulb data2 = { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" };
	int expected_value = 1;
	int actual__value = -1;
	if (data1 == data2) {
		actual__value = 1;
	} else {
		actual__value = 0;
	}
	ASSERT_EQ(expected_value, actual__value);
}
/*
 * Верифікація роботи функції {@link operator!=}
 * на основі вхідних даних лампочок та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, operatorNonEqual_test)
{
	Bulb data1 = { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" };
	Bulb data2 = { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" };
	int expected_value = 1;
	int actual__value = -1;
	if (data1 != data2) {
		actual__value = 1;
	} else {
		actual__value = 0;
	}
	ASSERT_EQ(expected_value, actual__value);
}
/*
 * Верифікація роботи функції {@link operator=}
 * на основі вхідних та очікуваних даних лампочки.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, operatorAssignment_test)
{
	Bulb data_and_exp_val = { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" };
	Bulb actual_value = data_and_exp_val;
	ASSERT_EQ(actual_value, data_and_exp_val);
}
/*
 * Верифікація роботи функції {@link operator[]}
 * на основі вхідних даних лампочок, списка та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, operatorIndex_test)
{
	Bulb data_array[3] = { { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
			       { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" },
			       { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" } };
	List list;
	list.addBulb(data_array[0]);
	list.addBulb(data_array[1], 1);
	list.addBulb(data_array[2], 2);
	Bulb expected_value = data_array[1];
	Bulb actual_value = list[1];
	ASSERT_EQ(expected_value, actual_value);
}
/*
 * Верифікація роботи функції {@link addBulb}
 * на основі вхідних даних декількох лампочок, класса,
 * та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, addBulb_test)
{
	const int DATA_SIZE_ARRAY = 3;
	Bulb data_array[DATA_SIZE_ARRAY] = { { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
					     { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" },
					     { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" } };
	List list;
	list.addBulb(data_array[0]);
	list.addBulb(data_array[1], 1);
	list.addBulb(data_array[2], 2);
	for (size_t i = 0; i < DATA_SIZE_ARRAY; i++) {
		Bulb expected_value = data_array[i];
		Bulb actual_value = list.getBulb(i);
		ASSERT_EQ(actual_value, expected_value);
	}
}
/*
 * Верифікація роботи функції {@link removeBulb}
 * на основі вхідних даних декількох лампочок, класса,
 * та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, removeBulb_test)
{
	const int DATA_SIZE_ARRAY = 3;
	const int DATA_SIZE_EXP_VALUE = 2;
	Bulb data_array[DATA_SIZE_ARRAY] = { { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
					     { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" },
					     { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" } };
	List list;
	list.addBulb(data_array[0]);
	list.addBulb(data_array[1], 1);
	list.addBulb(data_array[2], 2);
	list.removeBulb(1);
	Bulb expected_value[DATA_SIZE_EXP_VALUE] = { { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
						     { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" } };
	for (size_t i = 0; i < DATA_SIZE_EXP_VALUE; i++) {
		Bulb actual_value = list.getBulb(i);
		ASSERT_EQ(actual_value, expected_value[i]);
	}
}
/*
 * Верифікація роботи функції {@link getBulb}
 * на основі вхідних даних лампочки, класса, індекса лампочки
 * та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, getBulb_test)
{
	Bulb data1("no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21");
	Bulb data2;
	List list;
	list.addBulb(data1);
	list.addBulb(data2, 1);
	Bulb expected_value(data1);
	Bulb actual_value = list.getBulb(0);
	ASSERT_EQ(actual_value, expected_value);
}
/*
 * Верифікація роботи функції {@link Bulb(string &s)}
 * на основі вхідних та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, BulbString_test)
{
	string data = "    yes   ,  no  ,   TOV Pont   ,  33 ,  10    ,  3600 ,    Square , E42  .";
	Bulb expected_value = { "yes", "no", "TOV Pont", 33, 10, 3600, "Square", "E42" };
	Bulb actual_value(data);
	ASSERT_EQ(actual_value, expected_value);
}
/*
 * Верифікація роботи функції {@link ToString)}
 * на основі вхідних та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */

TEST(Programing03cpp, ToString_test)
{
	Bulb data = { "yes", "no", "TOV Pont", 33, 10, 3600, "Square", "E42" };
	string expected_value = "yes, no, TOV Pont, 33, 10, 3600, Square, E42.\n";
	string actual_value = data.toString();
	ASSERT_EQ(actual_value, expected_value);
}