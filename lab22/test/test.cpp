/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій: сортування 
 * лампочок за зворотнім лічильником. 
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 * @version 0.1
 */

#include "list.hpp"
#include <gtest/gtest.h>

/*
 * Фукція порівняння лампочок.
 *
 * Функція порівнює всі змінні класа Bulb.
 */
void compareBulbs(const Bulb &bulb1, const Bulb &bulb2)
{
	ASSERT_EQ(bulb1.getIsOn(), bulb2.getIsOn());
	ASSERT_EQ(bulb1.getIsBurned(), bulb2.getIsBurned());
	ASSERT_EQ(bulb1.getFactory(), bulb2.getFactory());
	ASSERT_EQ(bulb1.getReverseCounter(), bulb2.getReverseCounter());
	ASSERT_EQ(bulb1.getVatt(), bulb2.getVatt());
	ASSERT_EQ(bulb1.getColorTemp(), bulb2.getColorTemp());
	ASSERT_EQ(bulb1.getShape(), bulb2.getShape());
	ASSERT_EQ(bulb1.getBaseType(), bulb2.getBaseType());
}
/**
 * Верифікація роботи функції {@link sortBulb}
 * на основі вхідних даних декількох лампочок, вектора 
 * та очікуваних даних.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
TEST(Programing06cpp, sortBulbs_test)
{
	const int DATA_SIZE_ARRAY = 3;
	Bulb data_array[DATA_SIZE_ARRAY] = { { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" },
					     { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
					     { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" } };
	vector<Bulb> data_vector;
	for (size_t i = 0; i < DATA_SIZE_ARRAY; i++) {
		data_vector.push_back(data_array[i]);
	}
	Bulb expected_array[DATA_SIZE_ARRAY] = { { "no", "yes", "Romashka", 21, 15, 2400, "Triangle", "E21" },
						 { "yes", "no", "TOV Roga and kopyta", 100, 10, 1800, "Circle", "E40" },
						 { "yes", "yes", "TOV Pont", 650, 5, 3600, "Octangle", "E63" } };
	compare_class functor;
	sortBulbs(data_vector, functor);
	for (size_t i = 0; i < DATA_SIZE_ARRAY; i++) {
		Bulb expected_value = expected_array[i];
		Bulb actual_value = data_vector[i];
		compareBulbs(actual_value, expected_value);
	}
}