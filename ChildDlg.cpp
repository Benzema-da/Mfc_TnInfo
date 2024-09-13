// ChildDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TnInfo.h"
#include "ChildDlg.h"
#include "afxdialogex.h"


// ChildDlg �Ի���

IMPLEMENT_DYNAMIC(ChildDlg, CDialogEx)

ChildDlg::ChildDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ChildDlg::IDD, pParent)
	, m_id(_T(""))
	, m_lastname(_T(""))
	, m_firstname(_T(""))
	, m_date(_T(""))
	, m_content(_T(""))
{

	//m_id = _T("");
}

ChildDlg::~ChildDlg()
{
}

void ChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_id);
	DDX_Text(pDX, IDC_EDIT2, m_lastname);
	DDX_Text(pDX, IDC_EDIT3, m_firstname);
	DDX_Text(pDX, IDC_EDIT4, m_date);
	DDX_Text(pDX, IDC_EDIT5, m_content);
	DDX_Text(pDX, IDC_EDIT1, m_id);
}


BEGIN_MESSAGE_MAP(ChildDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT4, &ChildDlg::OnEnChangeEdit4)
	ON_BN_CLICKED(IDC_ModifyPass, &ChildDlg::OnBnClickedModifypass)
END_MESSAGE_MAP()


// ChildDlg ��Ϣ�������


void ChildDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void ChildDlg::OnBnClickedModifypass()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	//if(m_id==TEXT("")||m_lastname==TEXT("")||m_firstname==TEXT("")||m_date==TEXT("")||m_content==TEXT("")){
	//MessageBox(TEXT("����Ϊ�գ�"));
	//}
	 CString errorMsg;
    if (m_id.IsEmpty()) {
        errorMsg += TEXT("ID ����Ϊ�գ�\n");
    }
    if (m_lastname.IsEmpty()) {
        errorMsg += TEXT("���ϲ���Ϊ�գ�\n");
    }
    if (m_firstname.IsEmpty()) {
        errorMsg += TEXT("���ֲ���Ϊ�գ�\n");
    }
    if (m_date.IsEmpty()) {
        errorMsg += TEXT("���ڲ���Ϊ�գ�\n");
    }
    if (m_content.IsEmpty()) {
        errorMsg += TEXT("���ݲ���Ϊ�գ�\n");
    }

    if (!errorMsg.IsEmpty()) {
        MessageBox(errorMsg, TEXT("�������"), MB_OK | MB_ICONWARNING);
		//(��ʾ�����ݣ����⣬MB_OK��ʾ��Ϣ�����һ����ȷ������ť��MB_ICONWARNING ��ʾ��Ϣ�����ʾһ������ͼ�꣬�����û��������⡣)
	}else{
	   OnOK();
	   return;
	}
}
