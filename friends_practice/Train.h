#pragma once
#include <iostream>
#include <string>
using namespace std;

class Train
{
private:
	size_t number = 0;
	string name = "None";
	Car* cars = nullptr;
	size_t size;

	static size_t trainCount;
public:
	Train() = default;
	Train(size_t number, string name, size_t size);
	Train(const Train& other);
	~Train();

	size_t totalPassengers() const;
	void print_train() const;
	size_t getNumber() const;
	string getName() const;
	size_t getSize() const;
	static size_t getTrainCount();

	friend ostream& operator<<(ostream& out, const Train& t);
	friend istream& operator>>(istream& in, Train& t);
};

class Car
{
private:
	string type;
	size_t passengers;

public:
	Car() = default;
	Car(string type_, size_t passengers_);
	Car(const Car& other);
	~Car();

	void setType(string type_);
	string getType() const;
	void setPassengers(size_t passengers_);
	size_t getPassengers() const;

	void print() const;

	friend ostream& operator<<(const Car& car, ostream& out);
	friend istream& operator>>(Car& car, istream& in);

};

inline Car::Car(string type_, size_t passengers_)
	:type{type_}, passengers{passengers_}
{
}

inline Car::Car(const Car& other)
{
	type = other.type;
	passengers = other.passengers;
}

inline Car::~Car()
{
}

inline void Car::setType(string type_)
{
	type = type_;
}

inline string Car::getType() const
{
	return type;
}

inline void Car::setPassengers(size_t passengers_)
{
	passengers = passengers_;
}

inline size_t Car::getPassengers() const
{
	return passengers;
}

inline Train::Train(size_t number, string name, size_t size)
	:number{number}, name{name}, size{size}
{
	cars = new Car[size];
	trainCount++;
}

Train::~Train()
{
	delete[] cars;
	trainCount--;
}

inline size_t Train::getNumber() const
{
	return number;
}





