// ChildDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TnInfo.h"
#include "ChildDlg.h"
#include "afxdialogex.h"


// ChildDlg 对话框

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


// ChildDlg 消息处理程序


void ChildDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void ChildDlg::OnBnClickedModifypass()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//if(m_id==TEXT("")||m_lastname==TEXT("")||m_firstname==TEXT("")||m_date==TEXT("")||m_content==TEXT("")){
	//MessageBox(TEXT("输入为空！"));
	//}
	 CString errorMsg;
    if (m_id.IsEmpty()) {
        errorMsg += TEXT("ID 不能为空！\n");
    }
    if (m_lastname.IsEmpty()) {
        errorMsg += TEXT("姓氏不能为空！\n");
    }
    if (m_firstname.IsEmpty()) {
        errorMsg += TEXT("名字不能为空！\n");
    }
    if (m_date.IsEmpty()) {
        errorMsg += TEXT("日期不能为空！\n");
    }
    if (m_content.IsEmpty()) {
        errorMsg += TEXT("内容不能为空！\n");
    }

    if (!errorMsg.IsEmpty()) {
        MessageBox(errorMsg, TEXT("输入错误"), MB_OK | MB_ICONWARNING);
		//(显示的内容，标题，MB_OK表示消息框会有一个“确定”按钮，MB_ICONWARNING 表示消息框会显示一个警告图标，提醒用户存在问题。)
	}else{
	   OnOK();
	   return;
	}
}
