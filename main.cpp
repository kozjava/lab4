#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdio>
#include "Print.h"
using namespace std;

class Question//вопросы
{
private:
	char *text;
public:
	void setText(char *buffer)
	{
		//cout << "buffer :" << buffer << endl;
		text = buffer;
	}
	char* getText()
	{
		return text;
	}
	void Print()
	{
		cout << "Your Questions are : " << endl;
		cout << text << endl;
	}
};


class Test//test
{
private:
	Question *Arr;//массив вопросов
	int size = 0;
	int current = 0;
public:
	Test()
	{
		cout << "Default constructor : Test " << endl;
	}
	~Test()
	{
		cout << "Destructor : Test" << endl;
	}
	Test(int s)
	{
		cout << "Constructor : Test " << endl;
		size = s;
		Arr = new Question[size];
	}
	void addQuestion(char *buffer)
	{
		if (current <= size)
		{
			Arr[current].setText(buffer);
			current++;
		}
		else
		{
			cout << "ERROR" << endl;
			abort();
		}
	}
	void getquestion()
	{
		for (int i = 0; i < current; i++)
			Arr[i].Print();
	}
	void setSize(int s)
	{
		size = s;
	}
};
class Exam : Test, public Printing
{
private:
	int size = 0;
	int current = 0;
	Question* Mass;
public:
	Exam()
	{
		cout << "Default constructor : Exam " << endl;
	}
	Exam(int s)
	{
		cout << "Constructor : Exam" << endl;
		size = s;
		Mass = new Question[size];
	}
	~Exam()
	{
		cout << "Destructor : Exam" << endl;
	}
	void addQuestionExam(char* buffer)
	{
		if (current <= size)
		{
			Mass[current].setText(buffer);
			current++;
		}
		else
		{
			cout << "ERROR" << endl;
			abort();
		}
	}
	void getQuestionExam()
	{
		printTitle();
		for (int i = 0; i < current; i++)
			Mass[i].Print();
	}
	void setSize(int s)
	{
		size = s;
	}
};

class Math:public Exam
{
public:
	Math(int s) :Exam(s) {};
	void printTitle()
	{
		cout << "Math exams: " << endl;
	}
private:

};


class Fil:public Exam
{
public:
	Fil(int s) :Exam(s) {};
	void printTitle()
	{
		cout << "Fil exams: " << endl;
	}

private:

};





int main()
{
	/*
	T.getquestion();
	cout << "----------" << endl;
	Exam E(3);
	for (int i = 0; i < 3; i++)
	{
		char* str2 = new char[250];
		cin.getline(str2, 250);
		E.addQuestionExam(str2);
	}
	E.getQuestionExam();
	cout << "----------" << endl;*/
	Math mat(1);
	for (int i = 0; i < 1; i++)
	{
		char* str2 = new char[250];
		cin.getline(str2, 250);
		mat.addQuestionExam(str2);
	}
	Fil fil(1);
	for (int i = 0; i < 1; i++)
	{
		char* str2 = new char[250];
		cin.getline(str2, 250);
		fil.addQuestionExam(str2);
	}
	mat.getQuestionExam();
	cout << "----------" << endl;
	fil.getQuestionExam();
	system("pause");
	return 0;

}
