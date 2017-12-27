/* ������� ����� ModelWindow ��� ������ � �������� �������� ����.� �������� �����
�������� : ��������� ����, ���������� ������ �������� ����, ������ �� �����������,
������ �� ���������, ���� ����, ��������� ��������\���������, ��������� �� ������ \
��� �����.���������� � ������� ����������� � ����� ������.����������� �������� :
������������ ���� �� ����������� � �� ���������; ��������� ������ � ������ ����;
��������� ���������, ����� ���������.�������� ������������ � ��������� �������
������ ������������ �������� �� ����������� ������ ������.

������� �. 9 ������
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
    //�����������
	ModelWindow()
	{
		SetXY(0, 0);
		SetWidthHeight(0, 0);
		SetColor("");
		Frame = Condition(0);
		Visible = Condition(0);
	};

	//������������� ���������� �������� ������ ����
	void SetXY(int X, int Y)
	{
		TopLeftCornerX = X;
		TopLeftCornerY = Y;
	};

	//������������� ������ � ������ ����
	void SetWidthHeight(int W, int H)
	{
		Width = W;
		Height = H;
	};

	//������������� ����
	void SetColor(string Col)
	{
		Color = Col;
	}

	//������������� ��������� � ������/��� �����, �������/���������
	bool Condition(bool B)
	{
		return B;
	};

	//����������� ���� �� ������
	bool MovingXY(int X, int Y, int displayW, int displayH)
	{
		//�������� �� ������� ������
		if ((TopLeftCornerX + X) >= 0 && (TopLeftCornerX + Width + X) <= displayW && (TopLeftCornerY - Height + Y) >= 0 && (TopLeftCornerY + Y) <= displayH)
		{
			TopLeftCornerX += X;
			TopLeftCornerY += Y;
			return 1;
		}
		else
			return 0;
	}

	//�������� ������� ����
	bool SizeXY(int W, int H, int displayW, int displayH)
	{
		//�������� �� ����� �� ������� ������
		if (TopLeftCornerX + W <= displayW && TopLeftCornerY - H >= 0)
		{
			SetWidthHeight(W, H);
			return 1;
		}
		else
			return 0;
	}

	//������ ���������
	void ChangeVisible()
	{
		Visible = !Visible;
	}

	//������ �����
	void ChangeFrame()
	{
		Frame = !Frame;
	}


	//���� � ����������
	bool Read(int displayW, int displayH)
	{


		cout << "������� ��� ���� " << endl;
		string n;
		cin >> n;
		Name = n;

		cout << "������� ���������� �������� ������ ���� ����" << endl;
		int x = 0, y = 0;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		if (x < displayW && x > 0 && y < displayH && y > 0)
			SetXY(x, y);
		else
		{
			cout << "���������� ������� �� ������� ������" << endl << endl;
			return 0;
		}


		cout << "������� ������ � ������ ����" << endl;
		int W = 0, H = 0;
		cout << "������: ";
		cin >> W;
		cout << "������: ";
		cin >> H;
		if (x + W < displayW && y - H > 0)
			SetWidthHeight(W, H);
		else
		{
			cout << "���� ������� �� ������� ������" << endl << endl;
			return 0;
		}


		cout << "������� ���� ����" << endl;
		string Col;
		cin >> Col;
		SetColor(Col);

		char c;
		cout << "���� � ������? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Frame = Condition(1);
			else
				Frame = Condition(0);
		else
		{
			cout << "������������ ����" << endl << endl;
			return 0;
		}

		cout << "���� �������? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Visible = Condition(1);
			else
				Visible = Condition(0);
		else
		{
			cout << "������������ ����" << endl << endl;
			return 0;
		}
		return 1;



	}

	//����� �� �����
	void Display()
	{
		cout << "__________________________________________" << endl;
		cout << "��� ����: " << Name << endl;
		cout << "������� ����� ���� x: " << TopLeftCornerX << " y: " << TopLeftCornerY << endl;
		cout << "������ ����: " << Width << " ������ ����: " << Height << endl;
		cout << "���� ����: " << Color << endl;
		cout << "���� ";
		if (Frame)
			cout << "� ������" << endl;
		else
			cout << "��� �����" << endl;
		cout << "���� ";
		if (Visible)
			cout << "�������" << endl;
		else
			cout << "���������" << endl;
		cout << "__________________________________________" << endl;

	}

	//��������� ���������
	void SetCondition()
	{
		char c;
		cout << "���� � ������? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Frame = Condition(1);
			else
				Frame = Condition(0);
		else
			cout << "������������ ����" << endl;

		cout << "���� �������? (y/n)" << endl;
		cin >> c;
		if (c == 'y' || c == 'n')
			if (c == 'y')
				Visible = Condition(1);
			else
				Visible = Condition(0);
		else
			cout << "������������ ����" << endl;
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
		cout << " ����  " << endl;
		cout << "1 ���� ������" << endl;
		cout << "2 ����� ������" << endl;
		cout << "3 ������������ ����" << endl;
		cout << "4 ��������� ������� ����" << endl;
		cout << "5 ��������� ���������" << endl;
		cout << "6 ����� ��������� " << endl;
		cout << "7 ����� " << endl << endl;
		cout << "������� ��� ������� " << endl;
		cin >> number;

		switch (number)
		{
		case 1:
			if (Window.Read(W, H))
				cout << "������ ������� ��������!" << endl;
			else
				cout << "������ ��� ����� ������, ���������� ��� ���!" << endl << endl;
			break;
		case 2: Window.Display(); break;
		case 3:
		{
			int x, y;
			cout << "����������� �� ����������� �� ";
			cin >> x;
			cout << "����������� �� ��������� �� ";
			cin >> y;
			if (!Window.MovingXY(x, y, W, H))
				cout << "���� ������� �� ������� ������" << endl;
			break;
		}
		case 4:
		{
			int Width, Height;
			cout << "����� ������ ���� ";
			cin >> Width;
			cout << "����� ������ ���� ";
			cin >> Height;
			if (!Window.SizeXY(Width, Height, W, H))
				cout << "���� ������� �� ������� ������" << endl;
			break;
		}
		case 5:
		{
			char c;

			cout << "�������� ���������? (y/n) " << endl;
			cin >> c;
			if (c == 'y' || c == 'n')
				if (c == 'y')
					Window.ChangeVisible();
				else
					cout << "������������ ����" << endl;

			cout << "�������� �����? (y/n) " << endl;
			cin >> c;
			if (c == 'y' || c == 'n')
				if (c == 'y')
					Window.ChangeFrame();
				else
					cout << "������������ ����" << endl;



			break;
		}
		case 6:
		{
			Window.SetCondition();
			break;
		}
		case 7: exit(1); break;
		default: cout << "����������� ���� " << endl; break;
		}
		getchar();

	}
	return 0;
}



