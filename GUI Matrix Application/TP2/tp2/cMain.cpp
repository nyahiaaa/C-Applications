#include "cMain.h"
#include <fstream>
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <sstream>
#include <random>
#include <cstdlib>
#include <time.h>
#include "Vector2d.h"
#include <wx/filepicker.h>

using namespace std;




wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(10001, OnButtonClicked)
EVT_BUTTON(10002, OnButtonRandom)
EVT_BUTTON(10003, OnButtonSave)
wxEND_EVENT_TABLE()


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "TP2 GUI", wxPoint(30,30), wxSize(700,500))
{
	m_btn1 = new wxButton(this, 10001, "Run", wxPoint(20, 20), wxSize(100, 30));
	m_btn2 = new wxButton(this, 10002, "Random", wxPoint(280, 370), wxSize(100, 30));
	m_btn3 = new wxButton(this, 10003, "Save", wxPoint(280, 410), wxSize(100, 30));
	m_txt1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(20, 60), wxSize(300, 300), wxTE_MULTILINE);
	m_txt2 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(350, 60), wxSize(300, 300), wxTE_MULTILINE | wxTE_READONLY);
	m_file = new wxFilePickerCtrl(this, wxID_ANY, "", "", "", wxPoint(150, 20), wxSize(500, 30));
	

	string input;	//pour les commandes
	string ofile;   //pour nom du fichier out
	string ifile;   //pour nom du fichier in
	vector<char> tempa; //matrice 
	int i;	       //compteur
	char oper;


}


cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent &evt){
	m_txt1->Clear();
	m_txt2->Clear();
	string ifile;
//	*m_txt2 << m_txt1->GetValue();

	ifile = m_file->GetPath();

	ifstream ifs(ifile);//ouvrir le fichier
	string tempstr;
	char tempint;
	int count = 0;
	bool bynum = false;
	vector<char> tempv;


	while (getline(ifs, tempstr)) { //lire la ligne et mettre les valeur dans un vecteur
		istringstream iss(tempstr);
		*m_txt1 << tempstr;
		*m_txt1 << "\n";

		while (iss >> tempint) {
			count++;
			if (isdigit(tempint)){
				tempv.push_back(tempint);
				if (bynum){
					//call output function with vector
					op(tempv, 1);
					//clear vector
					tempv.clear();
					count = 0;
					bynum = false;
				}
			}

			if (isalpha(tempint)){
				tempv.push_back(tempint);
				//call output function with vector
				op(tempv, 2);
				//clear vector
				tempv.clear();
				count = 0;

			}

			if (tempint == '+' || tempint == '-' || tempint == '*'){
				tempv.push_back(tempint);
				if (count == 5){
					bynum = true;
				}
				else{
					//call output function with vector
					op(tempv, 0);
					//clear vector
					tempv.clear();
					count = 0;
				}

			}
		}
	}

	evt.Skip();
}


void cMain::OnButtonSave(wxCommandEvent &evt){
	ofstream outfile;
	string ofile = "out.txt";
	outfile.open(ofile);
	stringstream ss;
	ss << "  INPUT \n";
	ss << m_txt1->GetValue();
	ss << "\n\n  OUTPUT \n";
	ss << m_txt2->GetValue();
	outfile << ss.str();


	evt.Skip();
}





void cMain::OnButtonRandom(wxCommandEvent &evt){

	vector<char> tempa; //matrice 
	int i;	       //compteur
	char oper;
	stringstream ss;


	srand((unsigned)time(NULL));
	int rando, sel;

	bool check = true;

	sel = rand() % 10;

	if (sel == 0)
		oper = '+';
	else if (sel == 1)
		oper = '-';
	else if (sel == 2)
		oper = '*';
	else if (sel == 3)
		oper = '!';
	else if (sel == 4)
		oper = '@';
	else if (sel == 5)
		oper = '#';
	else if (sel == 6)
		oper = 'T';
	else if (sel == 7)
		oper = 'D';
	else if (sel == 8)
		oper = 'I';
	else if (sel == 9)
		oper = '+';

	rando = rand() % 10;
	for (int i = 0; i < 4; i++){
		tempa.push_back(rando + '0');
		ss << rando;
		rando = rand() % 10;
	}
	ss << "\n"<< oper;


	if (oper == '+' || oper == '-' || oper == '*'){
		ss << "\n";
		for (int i = 0; i < 4; i++){
			tempa.push_back(rando + '0');
			ss << rando;
			rando = rand() % 10;
		}
		tempa.push_back(oper);
		op(tempa, 0);
	}

	if (oper == '!' || oper == '@' || oper == '#'){
		ss << "\n";
		if (oper == '!')
			oper = '+';
		else if (oper == '@')
			oper = '-';
		else if (oper == '#')
			oper = '*';
		else
			oper = '+';
		tempa.push_back(oper);
		int val = rand() % 10;
		ss << val;
		tempa.push_back(val + '0');
		op(tempa, 1);
	}

	if (oper == 'T' || oper == 'D' || oper == 'I'){
		tempa.push_back(oper);
		op(tempa, 2);
	}
	tempa.clear();
	*m_txt1 << ss.str() <<"\n";

	evt.Skip();
}


void cMain::op(vector<char> v1, int f){ //fonction op pour gere les operations

	Vector2d vecta;
	Vector2d vectb;
	Vector2d vectc;
	char oper;
	int val;
	vecta.setVal(0, 0, v1[0] - '0'); //matrice num 1
	vecta.setVal(0, 1, v1[1] - '0');
	vecta.setVal(1, 0, v1[2] - '0');
	vecta.setVal(1, 1, v1[3] - '0');


	if (f == 0){

		vectb.setVal(0, 0, v1[4] - '0'); //matrice num 2
		vectb.setVal(0, 1, v1[5] - '0');
		vectb.setVal(1, 0, v1[6] - '0');
		vectb.setVal(1, 1, v1[7] - '0');

		oper = v1[8];
		//operations + - *
		if (oper == '+'){
			vectc = vecta + vectb;
		}
		if (oper == '-'){
			vectc = vecta - vectb;
		}
		if (oper == '*'){
			vectc = vecta * vectb;
		}
			stringstream ss;
			ss << vecta << oper << endl << vectb << " = " << endl << vectc;

			ss << "-----" << endl;
			*m_txt2 << ss.str();



	}
	if (f == 1){
		vectb = vecta;
		oper = v1[4];
		val = v1[5] - '0';
		//operations += -= *=
		if (oper == '+'){
			vecta += val;
		}
		if (oper == '-'){
			vecta -= val;
		}
		if (oper == '*'){
			vecta *= val;
		}
		vectc = vecta;

			stringstream ss;
			ss << vectb << oper << "=" << val << endl << " = " << endl << vectc;
			ss << "-----" << endl;
			*m_txt2 << ss.str();

	}

	if (f == 2){
		//operations T D I
		vectb = vecta;
		oper = v1[4];
		if (oper == 'T'){
			vecta.tran();
			vectc = vecta;

				stringstream ss;
				ss << vectb << oper << endl << " = " << endl << vectc;
				ss << "-----" << endl;
				*m_txt2 << ss.str();
			
		}
		if (oper == 'D'){
			int d = vecta.det();
	
				stringstream ss;
				ss << vectb << oper << endl << " = " << endl << d << endl;
				ss << "-----" << endl;
				*m_txt2 << ss.str();
			
		}
		if (oper == 'I'){
			vecta.inv();
			vectc = vecta;

				stringstream ss;
				ss << vectb << oper << endl << " = " << endl << vectc;
				ss << "-----" << endl;
				*m_txt2 << ss.str();
			
		}


	}





}