/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій: заповнення карт в вектор, 
 * сортування карт за зменшенням. 
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

#include "card.h"
#include <gtest/gtest.h>

/*
 * Фукція порівняння карт.
 *
 * Функція порівнює всі змінні класа Bulb.
 */
void compareCards(const Card &card1, const Card &card2)
{
	ASSERT_EQ(card1.getNumber(), card2.getNumber());
	ASSERT_EQ(card1.getSuite(), card2.getSuite());
}
/**
 * Верифікація роботи функції {@link writeToVector}
 * на основі вхідних даних декількох карт, вектора 
 * та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(ProgramingControlCpp, writeToVector_test)
{
	const int DATA_SIZE = 5;
	string s = "5H 3D 6H 7H 10H";
	vector<Card> data;
	writeToVector(data, s);
	Card expected_value[5] = { { 5, 'H' }, { 3, 'D' }, { 6, 'H' }, { 7, 'H' }, { 10, 'H' } };
	for (size_t i = 0; i < DATA_SIZE; i++) {
		Card actual_value = data[i];
		compareCards(actual_value, expected_value[i]);
	}
}
/**
 * Верифікація роботи функції {@link writeToVector}
 * на основі вхідних даних декількох карт, вектора 
 * та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(ProgramingControlCpp, sortCards_test)
{
	const int DATA_SIZE = 5;
	string s = "5H 3D 6H 7H 10H";
	vector<Card> data;
	writeToVector(data, s);
	sortCards(data);
	Card expected_value[5] = { { 10, 'H' }, { 7, 'H' }, { 6, 'H' }, { 5, 'H' }, { 3, 'D' } };
	for (size_t i = 0; i < DATA_SIZE; i++) {
		Card actual_value = data[i];
		compareCards(actual_value, expected_value[i]);
	}
}