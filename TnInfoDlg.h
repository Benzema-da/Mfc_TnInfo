
// TnInfoDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "DataInterface.h" 


// CTnInfoDlg �Ի���
class CTnInfoDlg : public CDialogEx
{
// ����
public:
	CTnInfoDlg(CWnd* pParent = NULL);	// ��׼���캯��


	bool IsOpen;
	
// �Ի�������
	enum { IDD = IDD_TNINFO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	// �� CYourDialog ���˽�в�����ӣ�
private:
    CStatic* m_pStaticImage; // ָ��̬�ؼ���ָ��
    CBitmap m_bitmapPass;  // ��һ��ͼƬ
    CBitmap m_bitmapFail;  // �ڶ���ͼƬ	
	 CBitmap m_bitmapRunning;
    void LoadImages();       // ����ͼƬ����
    afx_msg void OnBnClickedButtonShowImage1(); // ��ʾ��һ��ͼƬ���¼�������
    afx_msg void OnBnClickedButtonShowImage2																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										(); // ��ʾ�ڶ���ͼƬ���¼�������

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
