#pragma once

#include "wx/wx.h"
#include <fstream>
#include <iostream>
#include <vector> 
#include <algorithm> 
#include <sstream>
#include <random>
#include <cstdlib>
#include <time.h>
#include <wx/filepicker.h>

using namespace std;


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	wxButton *m_btn1 = nullptr;
	wxButton *m_btn2 = nullptr;
	wxButton *m_btn3 = nullptr;
	wxTextCtrl *m_txt1 = nullptr;
	wxTextCtrl *m_txt2 = nullptr;
	wxFilePickerCtrl *m_file = nullptr;
	


	void OnButtonClicked(wxCommandEvent &evt);
	void OnButtonRandom(wxCommandEvent &evt);
	void OnButtonSave(wxCommandEvent &evt);
	void op(vector<char>, int);

	wxDECLARE_EVENT_TABLE();
};

