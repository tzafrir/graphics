// HW0Dialog.cpp : implementation file
//

#include "stdafx.h"
#include "demo.h"
#include "HW0Dialog.h"

// HW0Dialog dialog

IMPLEMENT_DYNAMIC(HW0Dialog, CDialog)

HW0Dialog::HW0Dialog(float val /*=128*/, CWnd* pParent /*=NULL*/)
	: CDialog(HW0Dialog::IDD, pParent)
	, val(val)
{
}

HW0Dialog::~HW0Dialog()
{
}

void HW0Dialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, val);
	DDV_MinMaxFloat(pDX, val, 0.0, 1024.0);
}


BEGIN_MESSAGE_MAP(HW0Dialog, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &HW0Dialog::OnEnChangeEdit1)
END_MESSAGE_MAP()


// HW0Dialog message handlers

void HW0Dialog::OnEnChangeEdit1()
{
}

float HW0Dialog::getVal() {
	return val;
}

