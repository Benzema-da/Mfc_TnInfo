#pragma once


// ChildDlg �Ի���

class ChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg)

public:
	ChildDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ChildDlg();

// �Ի�������
	enum { IDD = IDD_ChildDlg };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
