#pragma once


// HW0Dialog dialog

class HW0Dialog : public CDialog
{
	DECLARE_DYNAMIC(HW0Dialog)

public:
	HW0Dialog(float val = 128.0, CWnd* pParent = NULL);   // standard constructor
	float getVal();
	virtual ~HW0Dialog();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
protected:
	float val;
};
