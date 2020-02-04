#pragma once
#include <iostream>

using namespace std;
class Vector2d
{
	friend ostream& operator<<(ostream&, const Vector2d&); //imprimer

public:
	int **array;
	int row;
	int col;

public:
	Vector2d();   //constructeur
	Vector2d(int, int); //para constructeur
	Vector2d(const Vector2d&); //copy constructeur
	~Vector2d();  //decontruceur
	void setVal(int, int, int); //set
	int getVal(int, int);  //get
	Vector2d operator+(const Vector2d&);  //surcharge op +
	Vector2d operator-(const Vector2d&);	//surcharge op -
	Vector2d operator*(const Vector2d&);	//surcharge op *
	Vector2d& operator=(const Vector2d &copy); //surcharge op =
	Vector2d& operator+=(int); //surcharge op +=
	Vector2d& operator-=(int);//surcharge op -=
	Vector2d& operator*=(int);//surcharge op *=

	Vector2d& tran(); //op transpose
	Vector2d& inv(); //op inverse
	int det(); //op dterminant





};

