#include "Vector2d.h"
#include <fstream>
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <sstream>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

Vector2d& Vector2d::operator=(const Vector2d &copy){ //surcharge =
	row = copy.row;
	col = copy.col;
	array = new int*[row];
	for (int i = 0; i<row; i++){
		array[i] = new int[col];
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = copy.array[i][j];
		}
	}
	return *this;

}

Vector2d::Vector2d(){ //construteur
	row = 2;
	col = 2;
	array = new int*[row];
	for (int i = 0; i<row; i++){
		array[i] = new int[col];
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = 0;
		}
	}

}

Vector2d::Vector2d(int r, int c){ //para construteur
	row = r;
	col = c;
	array = new int*[row];
	for (int i = 0; i<row; i++){
		array[i] = new int[col];
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = 0;
		}
	}
}


Vector2d::Vector2d(const Vector2d& m){ //copy construer
	row = m.row;
	col = m.col;
	array = new int*[row];
	for (int i = 0; i<row; i++){
		array[i] = new int[col];
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = m.array[i][j];
		}
	}
}


Vector2d::~Vector2d(){ //desctrutor
	for (int i = 0; i<row; i++){
		delete[] array[i];
	}
	delete[] array;
};



void Vector2d::setVal(int r, int c, int val){ //set
	array[r][c] = val;
};

int Vector2d::getVal(int r, int c){ //get
	return array[r][c];
}


Vector2d Vector2d::operator+(const Vector2d& m){ //surcharge +
	if (row != m.row || col != m.col){
		cerr << "Matrix sizes do not match. Mission impossible.";
		return (*this);
	}
	Vector2d new_mat(row, col);
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			new_mat.array[i][j] = array[i][j] + m.array[i][j];
		}
	}
	return new_mat;
}

Vector2d Vector2d::operator-(const Vector2d& m){ //surcharge -
	if (row != m.row || col != m.col){
		cerr << "Matrix sizes do not match. Mission impossible.";
		return (*this);
	}
	Vector2d new_mat(row, col);
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			new_mat.array[i][j] = array[i][j] - m.array[i][j];
		}
	}
	return new_mat;
}

Vector2d Vector2d::operator*(const Vector2d& m){ //surcharge *
	if (row != m.row || col != m.col){
		cerr << "Matrix sizes do not match. Mission impossible.";
		return (*this);
	}
	Vector2d new_mat(row, col);
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			new_mat.array[i][j] = array[i][j] * m.array[i][j];
		}
	}
	return new_mat;
}

std::ostream& operator<<(std::ostream& output, const Vector2d& m) //imprimer
{
	for (int i = 0; i< m.row; i++)
	{
		for (int j = 0; j<m.col; j++)
			output << m.array[i][j] << " ";
		output << endl;
	}
	return output;
}


Vector2d& Vector2d::operator+=(int val){ //surcharge +=

	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = array[i][j] + val;
		}
	}
	return *this;
}

Vector2d& Vector2d::operator-=(int val){ //surcharge -=

	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = array[i][j] - val;
		}
	}
	return *this;
}

Vector2d& Vector2d::operator*=(int val){ //surcharge *=

	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[i][j] = array[i][j] * val;
		}
	}
	return *this;
}

Vector2d& Vector2d::tran(){ //transpose
	Vector2d new_mat(row, col);

	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			new_mat.array[i][j] = array[i][j];
		}
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[j][i] = new_mat.array[i][j];
		}
	}
	return *this;
}

Vector2d& Vector2d::inv(){//inverse
	Vector2d new_mat(row, col);
	int deter = (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			new_mat.array[i][j] = array[i][j];
		}
	}
	for (int i = 0; i<row; i++){
		for (int j = 0; j<col; j++){
			array[j][i] = new_mat.array[i][j] * (1 / deter);
		}
	}
	return *this;
}

int Vector2d::det(){ //determinant
	int deter = (array[0][0] * array[1][1]) - (array[0][1] * array[1][0]);
	return deter;
}