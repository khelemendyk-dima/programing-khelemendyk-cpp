#ifndef LAB_21_LIST_HPP
#define LAB_21_LIST_HPP

/**
 * @file list.h
 * @brief Файл з описом функцій класа "список": конструктор, деструктор, 
 * гетери та сетери, додавання та видалення елемента у динамічному масиві, 
 * отримання індексу за елементом, вивод списку на екран, сортування та 
 * отримання мінімального елемента.
 *
 * @author Khelemendyk D.
 * @date 15-may-2022
 * @version 0.1
 */
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/**
 * Шаблоний клас "список". Зберігає динамічний масив 
 * та його розмір.
 */
template <class T> class List {
    private:
	T **array;
	size_t size;

    public:
	List() : array(NULL), size(0)
	{
	}
	~List()
	{
		for (size_t i = 0; i < size; i++) {
			delete (array[i]);
		}
		delete[] array;
	}

	// гетери/сетери
	T &getElement(size_t index)
	{
		if (index >= size)
			index = size - 1;
		return array[index][0];
	}
	size_t getSize() const
	{
		return size;
	}
	void setSize(const size_t s)
	{
		size = s;
	}

	/**
	 * Додавання елемента у список.
	 *
	 * Функція виділяє пам'ять для більшого масива, переписує 
	 * в нього старі елементи(якщо вони є) та додає новий 
	 * елемент в кінець динамічного масива.
	 * Отримує елемент для додавання.
	 */
	void add(const T element)
	{
		T **new_array = new T *[size + 1];
		for (size_t i = 0; i < size; i++) {
			new_array[i] = array[i];
		}
		new_array[size] = new T(element);
		delete[] array;
		array = new_array;
		size++;
	}
	/**
	 * Видалення елемента зі списку.
	 *
	 * Функція видаляє елемент зі списку шляхом виділення 
	 * пам'яті для меншого масива та заповненням в нього 
	 * всі елементи окрім видаленого.
	 * Отримує позицію для видалення.
	 */
	void remove(size_t pos)
	{
		if (size == 0)
			return;
		T **new_array = new T *[size - 1];
		if (pos >= size)
			pos = size - 1;
		for (size_t i = 0; i < pos; i++) {
			new_array[i] = array[i];
		}
		for (size_t i = pos; i < size - 1; i++) {
			new_array[i] = array[i + 1];
		}
		delete array[pos];
		delete[] array;
		array = new_array;
		size--;
	}
	/**
	 * Вивод списка.
	 *
	 * Функція друкує список на екран.
	 */
	void print() const
	{
		for (size_t i = 0; i < size; i++) {
			cout << array[i][0] << " ";
		}
		cout << endl;
	}
	/**
	 * Отримання індекса за значенням елемента.
	 * 
	 * Функція повертає індекс шуканого елемента.
	 * Отримує елемент, індекс якого потрібно знайти.
	 */
	size_t findIndex(const T element) const
	{
		size_t index = 0;
		size_t i = 0;
		while (i != size) {
			T temp = array[i][0] - element;
			if (temp < 0.0001 && temp >= 0) {
				index = i;
			}
			i++;
		}
		return index;
	}
	/**
	 * Сортування масиву.
	 * 
	 * Функція сортує масив елементів за збільшенням 
	 * значення.
	 */
	void sort() const
	{
		for (size_t i = 0; i < size; i++) {
			for (size_t j = 0; j < size - 1; j++) {
				if (array[j][0] > array[j + 1][0]) {
					T temp = array[j][0];
					array[j][0] = array[j + 1][0];
					array[j + 1][0] = temp;
				}
			}
		}
	}
	/**
	 * Знаходження мінімального елемента.
	 * 
	 * Функція повертає мінімальний елемент.
	 */
	T findMin() const
	{
		T min = array[0][0];
		for (size_t i = 1; i < size; i++) {
			if (min > array[i][0]) {
				min = array[i][0];
			}
		}
		return min;
	}
};

#endif