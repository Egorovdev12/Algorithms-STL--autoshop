// 7. STL.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



class Auto
{
private:
	string model;
	int HP;
	int cost;

public:

	

	Auto()
	{
		model = "nodata";
		HP = 0;
		cost = 0;
	}
	
	Auto(string _model, int _HP, int _cost)
	{
		this->model = _model;
		this->HP = _HP;
		this->cost = _cost;
	}

	Auto(const Auto &obj)
	{
		this->model = obj.model;
		this->HP = obj.HP;
		this->cost = obj.cost;
	}

	void showCost()
	{
		cout << this->cost;
	}

	int getCost() const
	{
		return this->cost;
	}

	string getName()
	{
		return this->model;
	}
	
	friend ostream& operator<< (ostream &os, const Auto &info)
	{
		cout << "Model: " << info.model << endl;
		cout << "H/P: " << info.HP << endl;
		cout << "Current cost: " << info.cost << "$" << endl;
			return os;
	}
};




void getPrice(vector<Auto> &list)
{
	cout << "Доступные для покупки автомобили:" << endl << endl;
	for (int i = 0; i < list.size(); i++)
	{
		cout << i + 1 << ")" << endl;
		cout << list[i] << endl;
	}
	cout << endl;
}


Auto addAuto()
{
	string name; int power; int val;
	cout << "Введите название автомобиля: "; cin >> name; cout << endl;
	cout << "Мощность двигателя: "; cin >> power; cout << endl;
	cout << "Цена продажи: "; cin >> val; cout << endl;
	return Auto(name, power, val);
}

int choice()
{
	int h;
	cout << endl << "1. Показать соответствующие товары " << endl;
	cout << "2. Продолжить " << endl;
	cin >> h;
	if (h == 1)
	{
		return h;
	}
	else if (h == 2)
	{
		return h;
	}
	else
	{
		cout << "Введенный неправильный символ, пожалуйста, повторите ввод" << endl;
		choice();
	}
}



int main()
{
	setlocale(0, "");


	vector<Auto> PriceList;			// создаём контейнер, который будет хранить данные типа Auto


	PriceList.push_back(Auto("Ferrari_LaFerrari", 435, 65000));
	PriceList.push_back(Auto("Aston_Martin_Vulcan", 380, 49000));
	PriceList.push_back(Auto("Chevrolet_Camaro", 230, 25500));
	PriceList.push_back(Auto("Range_Rover_Sport", 250, 35000));
	PriceList.push_back(Auto("KIA_Optima", 215, 31000));
	PriceList.push_back(Auto("Bugatti_Diva", 580, 67500));

	char c = '0';
	int helper;
	vector<Auto>::iterator it;
	string findAuto;

	while (c != 'e')
	{


		cout << "            AUTO SHOP " << endl << endl;
		cout << "1. Ознакомиться с автомобилями в продаже " << endl;
		cout << "2. Выставить авто на продажу " << endl;
		cout << "3. Убрать авто с продажи " << endl;
		cout << "4. Узнать стоимость автомобился по названию " << endl;
		cout << "5. Автомобили в определенной ценовой категории " << endl;

		cin >> c;

		switch (c)
		{
		case '1':	getPrice(PriceList); 
			
			cout << "1. Сортировать список по возрастанию цены" << endl;
			cout << "2. Сортировать список по убыванию цены" << endl;
			cin >> helper;

			if (helper == 1)
			{
				sort(PriceList.begin(), PriceList.end(), [](const Auto &a1, const Auto &a2)
				{
					bool result = a1.getCost() < a2.getCost();
					return result;
				});
			}

			else if (helper == 2)
			{
				sort(PriceList.begin(), PriceList.end(), [](const Auto &a1, const Auto &a2)
				{
					bool result = a1.getCost() > a2.getCost();
					return result;
				});
			}


			break;

		case '2':	PriceList.push_back(addAuto()); break;

		case '3':
			cout << "Введите индекс автомобиля: "; 
			cin >> helper;
			it = PriceList.begin();							// инициализируем итератор началом списка списка
			it = it + (helper - 1);							// присваиваем итератору значение удаляемого элемента
			PriceList.erase(it);							// Удаляем нужный элемент
			break;

		case '4': 
			cout << "Введите название автомобиля: ";
			cin >> findAuto;

			for (vector<Auto>::iterator i = PriceList.begin(); i != PriceList.end(); i++)
			{
				

				if (findAuto == (*i).getName())
				{
					cout << "Стоимость данной модели: "; (*i).showCost(); cout << "$" << endl << endl;
					break;
				}
				
				if (i == PriceList.end() - 1)
				{
					cout << "Данной модели в продаже нет!" << endl << endl;
				}
				
			}
			break;

		case '5':
			
			cout << "Введите ценовой порог: " << endl;
			helper = 0; cin >> helper;

			int result = count_if(PriceList.begin(), PriceList.end(), [&helper](const Auto &a1)
			{
				if (a1.getCost() < helper)
					return true;
				else
					return false;
			});
			cout << "В указанном ценовом диапазоне найдено товаров: " << result << endl;
			
			int ans = choice();

			if (ans == 1)
			{
				for (vector<Auto>::iterator i = PriceList.begin(); i != PriceList.end(); i++)
				{
					if ((*i).getCost() <= helper)
					{
						cout << (*i) << endl;
					}
				}
				break;
			}

			else if (ans == 2)
			{
				break;
			}

		}
	}

    return 0;
}

