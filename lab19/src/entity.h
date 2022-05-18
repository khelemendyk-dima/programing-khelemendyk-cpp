#ifndef LAB_19_ENTITY_H
#define LAB_19_ENTITY_H

/**
 * @file entity.h
 * @brief Файл з описом функції класа "лампочка": конструктор за 
 * замовчуванням, копіюванням, конструктор з аргументами,
 * конструктор зі строкою, деструктор, гетери/сетери 
 * та представлення об'єкту у вигляді строки, оператори присвоєння, 
 * порівняння, вводу та виводу.
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
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
using std::ifstream;
using std::istream;
using std::ofstream;
using std::ostream;
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
	 * та повертає посилання на рядок.
	 */
	string toString();
	/**
	 * Оператор присвоювання.
	 *
	 * Функція присвоює одній лампочці всі дані іншої лампочки. 
	 * Отримує лампочку, дані якої будуть присвоєні. 
	 * Повертає посилання на об'єкт Bulb.
	 */
	Bulb &operator=(const Bulb &bulb);
	/**
	 * Оператор порівняння.
	 *
	 * Функція порівнює чи однакові всі дані однієї лампочки з даними іншої.
	 * Отримує лампочку, дані якої будуть порівнянні. 
	 * Повертає 1 якщо лампочки однакові, інакше - 0.
	 */
	bool operator==(const Bulb &bulb) const;
	/**
	 * Оператор порівняння.
	 *
	 * Функція порівнює чи не рівні всі дані однієї лампочки з даними іншої.
	 * Отримує лампочку, дані якої будуть порівнянні. 
	 * Повертає 1 якщо лампочки не однакові, інакше - 0.
	 */
	bool operator!=(const Bulb &bulb) const;
	/**
	 * Оператор виводу.
	 *
	 * Функція виводить всі змінні лампочки через кому.
	 */
	friend ostream &operator<<(ostream &output, const Bulb &d);
	/**
	 * Оператор вводу.
	 *
	 * Функція запитує у користувача дані та записує їх у об'єкт.
	 */
	friend istream &operator>>(istream &input, Bulb &d);
};
#endif