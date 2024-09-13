#pragma once


// ChildDlg 对话框

class ChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg)

public:
	ChildDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ChildDlg();

// 对话框数据
	enum { IDD = IDD_ChildDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CString m_id;
	CString m_lastname;
	CString m_firstname;
	CString m_date;
	CString m_content;
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnBnClickedModifypass();
	CString m_id;
};
