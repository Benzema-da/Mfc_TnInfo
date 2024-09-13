
// TnInfoDlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "DataInterface.h" 


// CTnInfoDlg 对话框
class CTnInfoDlg : public CDialogEx
{
// 构造
public:
	CTnInfoDlg(CWnd* pParent = NULL);	// 标准构造函数


	bool IsOpen;
	
// 对话框数据
	enum { IDD = IDD_TNINFO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	// 在 CYourDialog 类的私有部分添加：
private:
    CStatic* m_pStaticImage; // 指向静态控件的指针
    CBitmap m_bitmapPass;  // 第一张图片
    CBitmap m_bitmapFail;  // 第二张图片	
	 CBitmap m_bitmapRunning;
    void LoadImages();       // 加载图片函数
    afx_msg void OnBnClickedButtonShowImage1(); // 显示第一张图片的事件处理函数
    afx_msg void OnBnClickedButtonShowImage2																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										(); // 显示第二张图片的事件处理函数

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOpenFile();
	CListCtrl m_list;
	CDataInterface DataInterface;
	CString filePath;
	void UpdateList();
	afx_msg void OnBnClickedQuitfile();
	afx_msg void OnBnClickedFileAdd();
	afx_msg void OnBnClickedFileadd();
	afx_msg void OnBnClickedFiledelete();
};
