#ifndef LAB_18_ENTITY_H
#define LAB_18_ENTITY_H

/**
 * @file entity.h
 * @brief Файл з описом функції класа "лампочка": конструктор за 
 * замовчуванням, копіюванням, конструктор з аргументами,
 * конструктор, котрий приймає строку, деструктор, гетери/сетери 
 * та представлення об'єкту у вигляді строки.
 *
 * @author Khelemendyk D.
 * @date 12-may-2022
 * @version 0.1
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <cctype>
using std::cin;
using std::cout;
using std::endl;
using std::stoi;
using std::string;
using std::stringstream;

/**
 * Клас "лампочка"
 */
class Bulb {
    private:
	string is_on;
	string is_burned;
	string factory;
	int reverse_counter;
	int vatt;
	int color_temp;
	string shape;
	string base_type;

    public:
	/**
	 * Конструктор за замовчуванням.
	 *
	 * Конструктор заповнює всі змінні лампочки стандартними даними.
	 */
	Bulb();
	/**
	 * Конструктор з аргументами.
	 *
	 * Конструктор заповнює всі змінні лампочки заданими даними.
	 * Отримує дані для запонювання.
	 */
	Bulb(string is_on, string is_burned, string factory, int reverse_counter, int vatt, int color_temp, string shape, string base_type);
	/**
	 * Конструктор копіювання.
	 *
	 * Конструктор копіює всі дані з однієї лампочки в іншу.
	 * Отримує силку на лампочку.
	 */
	Bulb(const Bulb &copy);
	/**
	 * Конструктор зі строкою
	 * 
	 * Конструктор приймає строку, обробляє її та заповнює 
	 * всі змінні данними.
	 */
	Bulb(string &s);
	/**
	 * Десткруктор.
	 *
	 * Звілюнює виділену пам'ять.
	 */
	~Bulb();

	//  гетери/сетери

	string getIsOn() const;
	void setIsOn(const string io);

	string getIsBurned() const;
	void setIsBurned(const string ib);

	string getFactory() const;
	void setFactory(const string f);

	int getReverseCounter() const;
	void setReverseCounter(const int rc);

	int getVatt() const;
	void setVatt(const int v);

	int getColorTemp() const;
	void setColorTemp(const int ct);

	string getShape() const;
	void setShape(const string s);

	string getBaseType() const;
	void setBaseType(const string bs);

	/**
	 * Отримання рядка-інформації.
	 *
	 * Функція створює рядок-інформацію про об'єкт з наявних даних 
	 * та повертає ссилку на рядок.
	 */
	string toString();
};
#endif