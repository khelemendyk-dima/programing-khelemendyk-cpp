/**
 * @file entity.cpp
 * @brief Файл з реалізацією функцій: конструктор за замовчуванням, 
 * копіюванням, конструктор з аргументами, конструктор зі строкою, 
 * деструктор, гетери/сетери, представлення об'єкта у вигляді строки, 
 * оператори присвоєння, порівняння, вводу та виводу.
 *
 * @author Khelemendyk D.
 * @date 14-may-2022
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
Bulb::Bulb(string &s)
{
	string temp;
	int mode = 0;
	size_t i = 0;
	// clear spaces before first letter or number
	while (!(isalnum(s[i]))) {
		i++;
	}
	for (; i < s.size(); i++) {
		if ((mode == 2) && !(ispunct(s[i]))) {
			temp += s[i];
		} else if (!(ispunct(s[i])) && s[i] != ' ') {
			temp += s[i];
		} else {
			// writting to object
			if (mode == 0) {
				is_on = temp;
			} else if (mode == 1) {
				is_burned = temp;
			} else if (mode == 2) {
				size_t j = temp.size(); // end of string
				size_t index = 0; // number of spaces
				// removing spaces after words in string
				while (temp[j - 1] == ' ') {
					j--;
					index++;
				}
				// writting to the variable factory
				if (index != 0) {
					factory = temp.substr(0, (temp.size() - index));
				} else {
					factory = temp;
				}
			} else if (mode == 3) {
				reverse_counter = stoi(temp);
			} else if (mode == 4) {
				vatt = stoi(temp);
			} else if (mode == 5) {
				color_temp = stoi(temp);
			} else if (mode == 6) {
				shape = temp;
			} else {
				base_type = temp;
				break;
			}
			// if before next part of string is spaces
			while (!(isalnum(s[i]))) {
				i++;
			}
			i--;
			mode++;
			temp.clear();
		}
	}
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
string Bulb::toString()
{
	stringstream ss;
	ss << is_on << ", " << is_burned << ", " << factory << ", " << reverse_counter << ", " << vatt << ", " << color_temp << ", " << shape << ", "
	   << base_type << '.' << endl;
	string result = ss.str();
	return result;
}
Bulb &Bulb::operator=(const Bulb &bulb)
{
	if (this == &bulb) {
		return *this;
	}
	is_on = bulb.is_on;
	is_burned = bulb.is_burned;
	factory = bulb.factory;
	reverse_counter = bulb.reverse_counter;
	vatt = bulb.vatt;
	color_temp = bulb.color_temp;
	shape = bulb.shape;
	base_type = bulb.base_type;

	return *this;
}
bool Bulb::operator==(const Bulb &other) const
{
	return this->is_on == other.is_on && this->is_burned == other.is_burned && this->factory == other.factory &&
	       this->reverse_counter == other.reverse_counter && this->vatt == other.vatt && this->color_temp == other.color_temp &&
	       this->shape == other.shape && this->base_type == other.base_type;
}
bool Bulb::operator!=(const Bulb &other) const
{
	return !(this == &other);
}
ostream &operator<<(ostream &output, const Bulb &d)
{
	output << d.getIsOn() << ", " << d.getIsBurned() << ", " << d.getFactory() << ", " << d.getReverseCounter() << ", " << d.getVatt() << ", "
	       << d.getColorTemp() << ", " << d.getShape() << ", " << d.getBaseType() << '.' << endl;
	return output;
}
istream &operator>>(istream &input, Bulb &d)
{
	cout << "Is bulb on?: ";
	input >> d.is_on;
	cout << "Is bulb burned?: ";
	input >> d.is_burned;
	cout << "Who is manufacturer of bulb?: ";
	getchar();
	getline(input, d.factory);
	cout << "How many clicks to burn out?: ";
	input >> d.reverse_counter;
	cout << "How many vatt?: ";
	input >> d.vatt;
	cout << "What is temp color?: ";
	input >> d.color_temp;
	cout << "What is the shape?: ";
	input >> d.shape;
	cout << "What is the base type?: ";
	input >> d.base_type;
	return input;
}