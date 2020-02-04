#pragma once

#include "wx/wx.h"
#include "cMain.h"

class cAPP : public wxApp
{
public:
	cAPP();
	~cAPP();

private:
	cMain* m_frame1 = nullptr;


public:
	virtual bool OnInit();
};

