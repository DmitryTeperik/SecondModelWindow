/* Создать класс ModelWindow для работы с моделями экранных окон.В качестве полей
задаются : заголовок окна, координаты левого верхнего угла, размер по горизонтали,
размер по вертикали, цвет окна, состояние “видимое\невидимое”, состояние “с рамкой \
без рамки”.Координаты и размеры указываются в целых числах.Реализовать операции :
передвижения окна по горизонтали и по вертикали; изменение высоты и ширины окна;
изменение состояния, опрос состояния.Операции передвижения и изменения размера
должны осуществлять проверку на пересечение границ экрана.

Теперик Д. 9 группа
*/

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class ModelWindow
{
private:
	string Name;
	int TopLeftCornerX;
	int TopLeftCornerY;
	int Width;
	int Height;
	string Color;
	bool Frame;
	bool Visible;
public:
    //Конструктор
	ModelWindow()
	{
		SetXY(0, 0);
		SetWidthHeight(0, 0);
		SetColor("");
		Frame = Condition(0);
		Visible = Condition(0);
	};

	//Устанавливает координаты верхнего левого угла
	void SetXY(int X, int Y)
	{
		TopLeftCornerX = X;
		TopLeftCornerY = Y;
	};

	//Устанавливает ширину и высоту окна
	void SetWidthHeight(int W, int H)
	{
		Width = W;
		Height = H;
	};

	//Устанавливает цвет
	void SetColor(string Col)
	{
		Color = Col;
	}

	//Устанавливает состояние с рамкой/без рамки, видимое/невидимое
	bool Condition(bool B)
	{
		return B;
	};

	//Передвигает окно по экрану
	bool MovingXY(int X, int Y, int displayW, int displayH)
	{
		//проверка на границы экрана
		if ((TopLeftCornerX + X) >= 0 && (TopLeftCornerX + Width + X) <= displayW && (TopLeftCornerY - Height + Y) >= 0 && (TopLeftCornerY + Y) <= displayH)
		{
			TopLeftCornerX += X;
			TopLeftCornerY += Y;
			return 1;
		}
		else
			return 0;
	}

	//Изменяет размеры окна
	bool SizeXY(int W, int H, int displayW, int displayH)
	{
		//Проверка на выход за границы экрана
		if (TopLeftCornerX + W <= displayW && TopLeftCornerY - H >= 0)
		{
			SetWidthHeight(W, H);
			return 1;
		}
		else
			return 0;
	}

	//Меняет видимость
	void ChangeVisible()
	{
		Visible = !Visible;
	}

	//Меняет рамку
	void ChangeFrame()
	{
		Frame = !Frame;
	}


	//Ввод с клавиатуры
	bool Read(int displayW, int displayH)
	{


		cout << "Введите имя окна " << endl;
		string n;
		cin >> n;
		Name = n;

		cout << "Введите координаты верхнего левого угла окна" << endl;
		int x = 0, y = 0;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		if (x < displayW && x > 0 && y < displayH && y > 0)
			SetXY(x, y);
		else
		{
			cout << "Координата выходит за границу экрана" << endl << endl;
			return 0;
		}


		cout << "Введите ширину и высоту окна" << endl;
		int W = 0, H = 0;
		cout << "Ширина: ";
		cin >> W;
		cout << "Высота: ";
		cin >> H;
		if (x + W < displayW && y - H > 0)
			SetWidthHeight(W, H);
		else
		{
			cout << "Окно выходит за границы экрана" << endl << endl;
			return 0;
		}


		cout << "Введите цвет окна" << endl;
		string Col;
		cin >> Col;
		SetColor(Col);

		char c;
		cout << "Окно с рамкой? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Frame = Condition(1);
			else
				Frame = Condition(0);
		else
		{
			cout << "Некорректный ввод" << endl << endl;
			return 0;
		}

		cout << "Окно видимое? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Visible = Condition(1);
			else
				Visible = Condition(0);
		else
		{
			cout << "Некорректный ввод" << endl << endl;
			return 0;
		}
		return 1;



	}

	//Вывод на экран
	void Display()
	{
		cout << "__________________________________________" << endl;
		cout << "Имя окна: " << Name << endl;
		cout << "Верхний левый угол x: " << TopLeftCornerX << " y: " << TopLeftCornerY << endl;
		cout << "ширина окна: " << Width << " высота окна: " << Height << endl;
		cout << "Цвет окна: " << Color << endl;
		cout << "Окно ";
		if (Frame)
			cout << "с рамкой" << endl;
		else
			cout << "без рамки" << endl;
		cout << "Окно ";
		if (Visible)
			cout << "видимое" << endl;
		else
			cout << "невидимое" << endl;
		cout << "__________________________________________" << endl;

	}

	//Установка состояний
	void SetCondition()
	{
		char c;
		cout << "Окно с рамкой? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Frame = Condition(1);
			else
				Frame = Condition(0);
		else
			cout << "Некорректный ввод" << endl;

		cout << "Окно видимое? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Visible = Condition(1);
			else
				Visible = Condition(0);
		else
			cout << "Некорректный ввод" << endl;
	}

};


int main()
{
	ModelWindow Window;
	int number;
	int const  W = 1920, H = 1080;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	for (; ;)
	{
		cout << " Меню  " << endl;
		cout << "1 Ввод данных" << endl;
		cout << "2 Вывод данных" << endl;
		cout << "3 Передвижение окна" << endl;
		cout << "4 Изменение размера окна" << endl;
		cout << "5 Изменение состояния" << endl;
		cout << "6 Опрос состояния " << endl;
		cout << "7 Выход " << endl << endl;
		cout << "Введите ваш вариант " << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			if (Window.Read(W, H))
				cout << "Данные успешно записаны!" << endl;
			else
				cout << "Ошибка при вводе данных, попробуйте еще раз!" << endl << endl;
			break;
		case 2: Window.Display(); break;
		case 3:
		{
			int x, y;
			cout << "Передвинуть по горизонтали на ";
			cin >> x;
			cout << "Передвинуть по вертикали на ";
			cin >> y;
			if (!Window.MovingXY(x, y, W, H))
				cout << "Окно выходит за границы экрана" << endl;
			break;
		}
		case 4:
		{
			int Width, Height;
			cout << "Новая ширина окна ";
			cin >> Width;
			cout << "Новая высота окна ";
			cin >> Height;
			if (!Window.SizeXY(Width, Height, W, H))
				cout << "Окно выходит за границы экрана" << endl;
			break;
		}
		case 5:
		{
			char c;

			cout << "Изменить видимость? (y/n) " << endl;
			cin >> c;
			if (c == 'y' || c == 'n')
				if (c == 'y')
					Window.ChangeVisible();
				else
					cout << "Некорректный ввод" << endl;

			cout << "Изменить рамку? (y/n) " << endl;
			cin >> c;
			if (c == 'y' || c == 'n')
				if (c == 'y')
					Window.ChangeFrame();
				else
					cout << "Некорректный ввод" << endl;



			break;
		}
		case 6:
		{
			Window.SetCondition();
			break;
		}
		case 7: exit(1); break;
		default: cout << "Некорретный ввод " << endl; break;
		}
		getchar();

	}
	return 0;
}



