/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій: додавання елементів у масив, 
 * видалення з нього, отримання індекса за значенням елемента, знаходження 
 * мінімального значення з усіх елементів та сортування масиву.
 *
 * @author Khelemendyk D.
 * @date 15-may-2022
 * @version 0.1
 */

#include "list.hpp"
#include <gtest/gtest.h>

/*
 * Верифікація роботи функції {@link add)}
 * на основі вхідних та очікуваних даних типа int.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing05cpp, add_test)
{
	const int DATA_SIZE_ARR = 5;
	int data_and_exp_val[DATA_SIZE_ARR] = { 1, 2, 3, 4, 5 };
	List<int> data_list;
	for (int i = 0; i < DATA_SIZE_ARR; i++) {
		data_list.add(data_and_exp_val[i]);
	}
	for (size_t i = 0; i < DATA_SIZE_ARR; i++) {
		int actual_value = data_list.getElement(i);
		ASSERT_EQ(actual_value, data_and_exp_val[i]);
	}
}
/*
 * Верифікація роботи функції {@link remove)}
 * на основі вхідних та очікуваних даних типа int.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing05cpp, remove_test)
{
	const int DATA_SIZE_ARR = 5;
	const int DATA_SIZE_EXP_VAL = 4;
	int data[DATA_SIZE_ARR] = { 1, 2, 3, 4, 5 };
	List<int> data_list;
	for (int i = 0; i < DATA_SIZE_ARR; i++) {
		data_list.add(data[i]);
	}
	data_list.remove(0);
	int expected_value[DATA_SIZE_EXP_VAL] = { 2, 3, 4, 5 };
	for (size_t i = 0; i < DATA_SIZE_EXP_VAL; i++) {
		int actual_value = data_list.getElement(i);
		ASSERT_EQ(actual_value, expected_value[i]);
	}
}
/*
 * Верифікація роботи функції {@link findIndex)}
 * на основі вхідних та очікуваних даних типа int.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing05cpp, findIndex_test)
{
	const int DATA_SIZE_ARR = 5;
	int data[DATA_SIZE_ARR] = { 1, 2, 3, 4, 5 };
	List<int> data_list;
	for (int i = 0; i < DATA_SIZE_ARR; i++) {
		data_list.add(data[i]);
	}
	size_t actual_value = data_list.findIndex(3);
	size_t expected_value = 2;
	ASSERT_EQ(actual_value, expected_value);
}
/*
 * Верифікація роботи функції {@link sort)}
 * на основі вхідних та очікуваних даних типа int.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing05cpp, sort_test)
{
	const int DATA_SIZE_ARR = 5;
	int data[DATA_SIZE_ARR] = { 5, 4, 3, 2, 1 };
	List<int> data_list;
	for (int i = 0; i < DATA_SIZE_ARR; i++) {
		data_list.add(data[i]);
	}
	data_list.sort();
	int expected_value[DATA_SIZE_ARR] = { 1, 2, 3, 4, 5 };
	for (size_t i = 0; i < DATA_SIZE_ARR; i++) {
		int actual_value = data_list.getElement(i);
		ASSERT_EQ(actual_value, expected_value[i]);
	}
}
/*
 * Верифікація роботи функції {@link findMin)}
 * на основі вхідних та очікуваних даних типа int.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing05cpp, findMin_test)
{
	const int DATA_SIZE_ARR = 5;
	int data[DATA_SIZE_ARR] = { 5, 4, -1, 2, 1 };
	List<int> data_list;
	for (int i = 0; i < DATA_SIZE_ARR; i++) {
		data_list.add(data[i]);
	}
	int actual_value = data_list.findMin();
	int expected_value = -1;
	ASSERT_EQ(actual_value, expected_value);
}