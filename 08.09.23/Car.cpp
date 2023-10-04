#include "Car.h"//файл реализации
#include <iostream>
using namespace std;
Car::Car()
{
	model = nullptr;
	color = nullptr;
	year = 0;
	price = 0.00;
}

Car::Car(const char* m, const char* c, int y, double pr)
{
	this->model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);

	this->color = new char[strlen(c) + 1];
	strcpy_s(color, strlen(c) + 1, c);

	this->price = pr;
	this->year = y;
}

Car::~Car()
{
	delete[]model;
	delete[]color;
}

void Car::Input()
{
	char buff[20];
	cout << "Enter model: ";
	cin >> buff;
	SetModel(buff);
	cout << "Enter color: ";
	cin >> buff;
	SetColor(buff);


	cout << "Enter year: ";
	cin >> year;
	SetYear(year);

	cout << "Enter price in $: ";
	cin >> price;
	SetPrice(price);
	
}

void Car::Print()
{
	cout << "Model: " << model << "\tColor: " << color << "\tYear: " << year << "\tPrice: " << price << endl;
}

char* Car::GetModel()
{
	return model;
}

char* Car::GetColor()
{
	return color;
}

int Car::GetYear()
{
	return year;
}

double Car::GetPrice()
{
	return price;
}

void Car::SetModel(const char* m)
{
	if (model != nullptr)
	{
		cout << model << "...delete" << endl;
		delete[]model;
	}
	this->model = new char[strlen(m) + 1];
	strcpy_s(model, strlen(m) + 1, m);
}

void Car::SetColor(const char* c)//white
{
	if (color != nullptr)
	{
		cout << color << "...delete" << endl;
		delete[]color;
	}

	this->color = new char[strlen(c) + 1];
	strcpy_s(color, strlen(c) + 1, c);
}

void Car::SetYear(int y)
{
	if (year >= 1990 && year <= 2023)
	{
		this->year = y;
	}
	else {
		cout << "Year<1990.It is bad(" <<endl;
	}
	
}

void Car::SetPrice(double pr)
{
	if (price >= 1000)
	{
		this->price = pr;
	}
	else
	{
		cout << "Price<1000 $. It is strange)" <<endl;
	}
	
}
