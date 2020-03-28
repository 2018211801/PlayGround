// ConsoleApplication7.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include "pch.h"
/***********************
Practica1:C++����֪ʶʵ��
��дC++������ɡ��������¹��ܣ�
��1�� �ٶ������СΪ 4��5�����ͣ���
��2�� ����ռ���� new ��̬���룬������ָ���У�
��3�� ��������ʼ�����������Դ� cin ���������Ԫ�أ�
��4�� �����������������������ʽ������� cout��
��5�� ���������ӵĺ�����ʵ������������ӵĹ��ܣ������������һ�������У�
��6�� �����������ĺ�����ʵ��������������Ĺ��ܣ������������һ�������У�
��7�� ��̬������������A1��A2��A3��
��8�� ��ʼ�� A1��A2��
��9�� ���㲢��� A3 = A1 �� A2��A3 = A1 �� A2��
��10�� �ͷž���ռ�

  Scripted by��Xuefen in Bupt
***********************/
/*Ҫ����㷨��*/
#include<iostream>
using namespace std;

class matrix
{
public:
	int a[4][5];
	void input()
	{
		int i, j;

		cout << "���������A1(4*5):" << endl;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cin >> a[i][j];
			}
		}
	}

	void output()
	{
		int i, j;

		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}

	void sum(matrix &a, matrix &b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				this->a[i][j] = a.a[i][j] + b.a[i][j];
			}
		}
	}

	void sub(matrix &a, matrix &b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				this->a[i][j] = a.a[i][j] - b.a[i][j];
			}
		}
	}

};

int main()
{
	matrix *A1, *A2, *A3;
	A1 = new matrix;
	A2 = new matrix;
	A3 = new matrix;

	A1->input();
	A2->input();

	cout << "A1����Ϊ��" << endl;
	A1->output();

	cout << "A2����Ϊ��" << endl;
	A2->output();

	A3->sum(*A1, *A2);
	cout << "���������Ϊ��" << endl;
	A3->output();

	A3->sub(*A1, *A2);
	cout << "���������Ϊ��" << endl;
	A3->output();

	delete A1;
	delete A2;
	delete A3;
	return 0;
}
















/********************************************************
Traditional solution without "New":
class matrix
{
public:
	//����Ԫ�� 
	int a[4][5];
	//��Ա���� 
	void input()
	{
		int i, j;
		//cout << "Please input matrix(4*5) in line here:" << endl;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				cin >> a[i][j];
	}

	void output()
	{
		int i, j;
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 5; j++)
			{
				cout << a[i][j] << " ";
			}
			cout << endl;
		}
	}
	void sum(matrix a, matrix b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				this->a[i][j] = a.a[i][j] + b.a[i][j];
	}

	void sub(matrix a, matrix b)
	{
		int i, j;
		for (i = 0; i < 4; i++)
			for (j = 0; j < 5; j++)
				this->a[i][j] = a.a[i][j] - b.a[i][j];
	}
};



int main()
{
	matrix A1, A2;
	cout << "Please input A1 matrix ��4*5-scale�� info in line here:\n";
	A1.input();
	cout << "Please input A2 matrix ��4*5-scale��info in line here:\n";
	A2.input();
	//Display of A1 A2 is of no meaning

	cout << endl;
	cout << "Sum of A1 and A2 is:\n";
	matrix A3;
	A3.sum(A1, A2);
	A3.output();
	cout << "Substract of A1 and A2 is:\n";
	A3.sub(A1, A2);
	A3.output();

	return 0;
}
********************************************************/

