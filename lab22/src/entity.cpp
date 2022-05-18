/**
 * @file entity.cpp
 * @brief Файл з реалізацією функцій: конструктор за 
 * замовчуванням, копіюванням та конструктор з аргументами,
 * деструктор, гетери/сетери та вивід лампочки на екран.
 *
 * @author Khelemendyk D.
 * @date 18-may-2022
 */

#include "entity.h"

Bulb::Bulb()
	: is_on("yes"), is_burned("no"), factory("TOV Roga and kopyta"), reverse_counter(100), vatt(5), color_temp(1800), shape("Circle"),
	  base_type("E40")
{
}
Bulb::Bulb(string is_on, string is_burned, string factory, int reverse_counter, int vatt, int color_temp, string shape, string base_type)
	: is_on(is_on), is_burned(is_burned), factory(factory), reverse_counter(reverse_counter), vatt(vatt), color_temp(color_temp), shape(shape),
	  base_type(base_type)
{
}
Bulb::Bulb(const Bulb &copy)
	: is_on(copy.is_on), is_burned(copy.is_burned), factory(copy.factory), reverse_counter(copy.reverse_counter), vatt(copy.vatt),
	  color_temp(copy.color_temp), shape(copy.shape), base_type(copy.base_type)
{
}
Bulb::~Bulb()
{
}
string Bulb::getIsOn() const
{
	return is_on;
}
void Bulb::setIsOn(const string io)
{
	is_on = io;
}
string Bulb::getIsBurned() const
{
	return is_burned;
}
void Bulb::setIsBurned(const string ib)
{
	is_burned = ib;
}
string Bulb::getFactory() const
{
	return factory;
}
void Bulb::setFactory(const string f)
{
	factory = f;
}
int Bulb::getReverseCounter() const
{
	return reverse_counter;
}
void Bulb::setReverseCounter(const int rc)
{
	reverse_counter = rc;
}
int Bulb::getVatt() const
{
	return vatt;
}
void Bulb::setVatt(const int v)
{
	vatt = v;
}
int Bulb::getColorTemp() const
{
	return color_temp;
}
void Bulb::setColorTemp(const int ct)
{
	color_temp = ct;
}
string Bulb::getShape() const
{
	return shape;
}
void Bulb::setShape(const string s)
{
	shape = s;
}
string Bulb::getBaseType() const
{
	return base_type;
}
void Bulb::setBaseType(const string bs)
{
	base_type = bs;
}
void Bulb::print() const
{
	cout << is_on << ", " << is_burned << ", " << factory << ", " << reverse_counter << ", " << vatt << ", " << color_temp << ", " << shape
	     << ", " << base_type << '.' << endl;
}