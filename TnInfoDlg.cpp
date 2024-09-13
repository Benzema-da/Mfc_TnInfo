
// TnInfoDlg.cpp : ʵ���ļ�
//
#include "stdafx.h"
#include "TnInfo.h"
#include "TnInfoDlg.h"
#include "afxdialogex.h"
#include "ChildDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTnInfoDlg �Ի���




CTnInfoDlg::CTnInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTnInfoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTnInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CTnInfoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CTnInfoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTnInfoDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_OpenFile, &CTnInfoDlg::OnBnClickedOpenFile)
	ON_BN_CLICKED(IDC_QuitFile, &CTnInfoDlg::OnBnClickedQuitfile)
	ON_BN_CLICKED(IDC_FileAdd, &CTnInfoDlg::OnBnClickedFileAdd)
	ON_BN_CLICKED(IDC_FileAdd, &CTnInfoDlg::OnBnClickedFileadd)
	ON_BN_CLICKED(IDC_FileDelete, &CTnInfoDlg::OnBnClickedFiledelete)
END_MESSAGE_MAP()


// CTnInfoDlg ��Ϣ�������

BOOL CTnInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	SetWindowText(_T("TINNO��Ϣ��ѯ"));

	m_pStaticImage = (CStatic*)GetDlgItem(IDC_STATIC_RUNNING);

    if (m_pStaticImage == nullptr)
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // ���ÿؼ���ʽ
    m_pStaticImage->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE, SWP_NOSIZE);

    // ��������ͼƬ
   // LoadImages();
	m_bitmapRunning.LoadBitmap(IDB_Running);
    m_pStaticImage->SetBitmap(m_bitmapRunning);   

    if (m_pStaticImage == nullptr)
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // ��������ͼƬ
    if (!m_bitmapPass.LoadBitmap(IDB_Pass))
    {
        AfxMessageBox(_T("Failed to load image 1!"));
    }
    
    if (!m_bitmapFail.LoadBitmap(IDB_Fail))
    {
        AfxMessageBox(_T("Failed to load image 2!"));
    }


	CBitmap bitmap;
    if (!bitmap.LoadBitmap(IDB_TNLog))  // IDB_TNLog �����ͼƬ��ԴID
    {
        AfxMessageBox(_T("Failed to load bitmap!"));
        return FALSE;
    }

    // ��ȡ��̬�ؼ��ľ��
    CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TNLogo);
    if (!pStatic)  // ����Ƿ�ɹ���ȡ�ؼ�
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // ��ȡͼƬ�ĳߴ�
    BITMAP bm;
    bitmap.GetBitmap(&bm);
    int bitmap_width = bm.bmWidth;
    int bitmap_height = bm.bmHeight;

    // ��ȡ��̬�ؼ��ľ�������
    CRect rect;
    pStatic->GetWindowRect(&rect);
    ScreenToClient(&rect);

    // ������̬�ؼ���λ�úʹ�С
    rect.right = rect.left + bitmap_width;   // �����µĿ��
    rect.bottom = rect.top + bitmap_height;  // �����µĸ߶�
    pStatic->MoveWindow(&rect);

    // ���þ�̬�ؼ�Ϊλͼģʽ������λͼ
    pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE, SWP_NOSIZE);
    pStatic->SetBitmap((HBITMAP)bitmap.Detach());

	// �����б�ؼ��ķ��
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;//������|ĳ�и���
	m_list.SetExtendedStyle(dwStyle);//������չ���

	// ������
	m_list.InsertColumn(0, _T("����ID"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, _T("����"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, _T("ְλ"), LVCFMT_LEFT, 200);
	m_list.InsertColumn(4, _T("����"), LVCFMT_LEFT, 300);



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}
void CTnInfoDlg::LoadImages()
{
    m_bitmapPass.LoadBitmap(IDB_Pass); // ���ص�һ��ͼƬ
    m_bitmapFail.LoadBitmap(IDB_Fail); // ���صڶ���ͼƬ
}

void CTnInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTnInfoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTnInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTnInfoDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
    if (m_pStaticImage)
    {
        m_pStaticImage->SetBitmap(m_bitmapPass);
    }
	 AfxMessageBox(_T("��Ϣ¼��ɹ�!"));  // ��ӵ�����Ϣ
	 
}


void CTnInfoDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 
	
    if (m_pStaticImage)
    {
        m_pStaticImage->SetBitmap(m_bitmapFail);
    } 
	AfxMessageBox(_T("��Ϣ¼��ʧ��!"));  // ��ӵ�����Ϣ
}


void CTnInfoDlg::OnBnClickedOpenFile	()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 // ���������
    CString filter = _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");

    // �����ļ��Ի������ʹ�ö���Ĺ�����
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter);


    // ��ʾ�Ի���
    if (fileDlg.DoModal() == IDOK)
    {
        // ��ȡ�û�ѡ����ļ�·��
       filePath = fileDlg.GetPathName();
		// ���ó�ʼĿ¼
        // fileDlg.m_ofn.lpstrInitialDir = _T("C:\\Users\\YourUsername\\Documents");
		// ʹ�� std::ifstream ���ļ����ж�ȡ
		DataInterface.Open(filePath);

		UpdateList();
		//IsOpen = true;

		
     /*  std::ifstream fileStream(filePath.GetString()); 
	   if (fileStream.is_open())
        {
            CString fileContent;
            std::string line;

            // ���ж�ȡ�ļ�����
            while (std::getline(fileStream, line))
            {
                fileContent += CString(line.c_str()) + _T("\n");
            }

            fileStream.close();

            // ��ʾ�ļ���������Ϣ����
            AfxMessageBox(fileContent);
        }
        else
        {
            AfxMessageBox(_T("�޷����ļ�"));
       }*/ 
	}
 }

void  CTnInfoDlg::UpdateList(){
		m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DataInterface.Info.size(); i++)
	{
		str.Format(TEXT("%d"),DataInterface.Info[i].m_id);
		m_list.InsertItem(i, str);
		str.Format(TEXT("%s"), DataInterface.Info[i].m_lastname.c_str());
		m_list.SetItemText(i, 1, str);
		str.Format(TEXT("%s"), DataInterface.Info[i].m_firstname.c_str());
		m_list.SetItemText(i, 2, str);
		str.Format(TEXT("%s"), DataInterface.Info[i].m_date.c_str());
		m_list.SetItemText(i, 3, str);
		str.Format(TEXT("%s"), DataInterface.Info[i].m_content.c_str());
		m_list.SetItemText(i, 4, str);
	}
}



void CTnInfoDlg::OnBnClickedQuitfile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 m_list.DeleteAllItems(); // ��� List �ؼ��е�������Ŀ
}


void CTnInfoDlg::OnBnClickedFileAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ChildDlg dlg;
	if(IDOK==dlg.DoModal()){
		//Cinfo Info(atoi(dlg.m_id),dlg.m_lastname.GetBuffer(),dlg.m_firstname.GetBuffer(),dlg.m_date.GetBuffer(),dlg.m_content.GetBuffer());
		 // ��֤ID�Ƿ�Ϊ��Ч����
      /*  int id = atoi(dlg.m_id);
        if (id == 0 && dlg.m_id != TEXT("0")) {
            MessageBox(TEXT("��Ч��ID���룡"));
            return;
          }

        // ʹ��GetBuffer()��ȡ�ַ������ݣ�������ReleaseBuffer()�ͷ�
        CString lastname = dlg.m_lastname;
        CString firstname = dlg.m_firstname;
        CString date = dlg.m_date;
        CString content = dlg.m_content;

        // ����Cinfo����
        Cinfo Info(id, lastname.GetBuffer(), firstname.GetBuffer(), date.GetBuffer(), content.GetBuffer());

        // ReleaseBuffer()���ַ�������ʹ�ú����
        lastname.ReleaseBuffer();
        firstname.ReleaseBuffer();
        date.ReleaseBuffer();
        content.ReleaseBuffer();
		*/
		// ʹ�� CT2A �� CString ת��Ϊ std::string
        std::string lastname = CT2A(dlg.m_lastname);
        std::string firstname = CT2A(dlg.m_firstname);
        std::string date = CT2A(dlg.m_date);
        std::string content = CT2A(dlg.m_content);

        // �� id ת��Ϊ����
        int id = atoi(dlg.m_id);

        // ʹ��ת����� std::string ���� Cinfo ����
        Cinfo Info(id, lastname, firstname, date, content);
		DataInterface.Add(Info);
		UpdateList();
	}
}


void CTnInfoDlg::OnBnClickedFileadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CTnInfoDlg::OnBnClickedFiledelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int index = m_list.GetSelectionMark();
	if (index > -1) {
		UINT i;
		i = MessageBox(_T("ȷ��Ҫɾ��������¼��"), _T("��ʾ"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			DataInterface.Del(index);
			MessageBox(TEXT("ɾ���ɹ���"), TEXT("��ʾ"));
			UpdateList();

		}
		else
		{
			return;
		}
	
	}
	else {
		MessageBox(TEXT("��ѡ��Ҫɾ������!"),TEXT("������ʾ"));
	}
	
}