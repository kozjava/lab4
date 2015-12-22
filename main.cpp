#include<iostream>
#include<string.h>
#include<conio.h>
#include<cstdio>
using namespace std;



class Test//test
{
protected:
	char nazvanie_predmeta[100];
	int kol_vo = 0;
	int current = 0;
	Test *next;
	friend class Question;
public:
	virtual void printTitle() = 0;
	virtual void Input(void) = 0;
	Test()
	{
		cout << "Default constructor : Test " << endl;
		next = 0;
		strcpy(nazvanie_predmeta, "Without_name");
		kol_vo = 0;
	}
	~Test()
	{
		cout << "Destructor : Test" << endl;
	}
	Test(char *nazvanie_predmeta, int nomer_testa)
	{
		strcpy(this->nazvanie_predmeta, nazvanie_predmeta);
		this->kol_vo = kol_vo;
		next = 0;
	}
};
class Question//вопросы
{
private:
	Test* begin;
public:
	void Insert(Test *p)
	{
		Test *r;
		r = begin;
		begin = p;
		p->next = r;
	}
	void printTitle()
	{
		Test *r;
		r = begin;
		while (r)
		{
			r->printTitle();
			r = r->next;
		}

	}
	~Question()
	{
		Test *r;
		while (begin)
		{
			r = begin;
			begin = begin->next;
			delete r;
		}
	}
};

class Exam: public Test//экзамен
{
protected:
	int srednee;
public:
	Exam()
	{
		cout << "Default constructor : Exam " << endl;
		srednee = 0;
	}
	Exam(char*nazvanie_predmeta,int srednee,int kol_vo) : Test(nazvanie_predmeta,kol_vo)
	{
		cout << "Constructor : Exam" << endl;
		this->srednee = srednee;

	}
	~Exam()
	{
		cout << "Destructor : Exam" << endl;
	}
	void printTitle()
	{
		cout << "Название предмета = " << nazvanie_predmeta << " Количество вопросов = " << kol_vo << " Средняя оценка = " << srednee << endl;
	}
	void Input()
	{
		cout << "Название предмета = ";
		cin >> nazvanie_predmeta;
		cout << " Количество вопросов = ";
		cin >> kol_vo;
		cout << " Средняя оценка = ";
		cin >> srednee;
	}
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
	/*Math mat(1);
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
	return 0;*/
	setlocale(LC_CTYPE, "Russian");
	Question qq;
	Exam *ex;
	ex = new Exam("Философия", 4, 60);
	qq.Insert(ex);
	ex = new Exam("Высшая математика",4,60);
	qq.Insert(ex);
	qq.printTitle();
	return 0;
}
