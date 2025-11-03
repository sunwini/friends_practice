#include "Train.h"

void Car::print() const
{
	cout << "Type :: " << type << endl;
	cout << "Passengers :: " << passengers << endl;
}

ostream& operator<<(const Car& car, ostream& out)
{
	out << "Type :: " << car.type << endl;
	out << "Passengers :: " << car.passengers << endl;
}

istream& operator>>(Car& car, istream& in)
{
	cout << "Enter car type :: ";
	in >> car.type;
	cout << "Enter amount of passengers :: ";
	in >> car.passengers;
}

Train::Train(const Train& other)
{
	number = other.number;
	name = other.name;
	size = other.size;
	cars = new Car[size];
	for (size_t i = 0; i < size; i++)
	{
		cars[i] = other.cars;
	}
	trainCount++;
}

size_t Train::totalPassengers() const
{
	size_t total = 0;
	for (size_t i = 0; i < size; i++)
	{
		total += cars[i].getPassengers();
	}
	return total;
}

void Train::print_train() const
{
	cout << "Train #" << number << "( " << name << " )" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "Car " << i + 1 << " :: " << cars[i] << endl;
	}
	cout << "Total passengers :: " << totalPassengers() << endl;
}



