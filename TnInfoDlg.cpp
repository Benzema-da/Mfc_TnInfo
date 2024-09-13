
// TnInfoDlg.cpp : 实现文件
//
#include "stdafx.h"
#include "TnInfo.h"
#include "TnInfoDlg.h"
#include "afxdialogex.h"
#include "ChildDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CTnInfoDlg 对话框




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


// CTnInfoDlg 消息处理程序

BOOL CTnInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetWindowText(_T("TINNO信息查询"));

	m_pStaticImage = (CStatic*)GetDlgItem(IDC_STATIC_RUNNING);

    if (m_pStaticImage == nullptr)
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // 设置控件样式
    m_pStaticImage->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE, SWP_NOSIZE);

    // 加载所有图片
   // LoadImages();
	m_bitmapRunning.LoadBitmap(IDB_Running);
    m_pStaticImage->SetBitmap(m_bitmapRunning);   

    if (m_pStaticImage == nullptr)
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // 加载所有图片
    if (!m_bitmapPass.LoadBitmap(IDB_Pass))
    {
        AfxMessageBox(_T("Failed to load image 1!"));
    }
    
    if (!m_bitmapFail.LoadBitmap(IDB_Fail))
    {
        AfxMessageBox(_T("Failed to load image 2!"));
    }


	CBitmap bitmap;
    if (!bitmap.LoadBitmap(IDB_TNLog))  // IDB_TNLog 是你的图片资源ID
    {
        AfxMessageBox(_T("Failed to load bitmap!"));
        return FALSE;
    }

    // 获取静态控件的句柄
    CStatic* pStatic = (CStatic*)GetDlgItem(IDC_STATIC_TNLogo);
    if (!pStatic)  // 检查是否成功获取控件
    {
        AfxMessageBox(_T("Failed to get static control!"));
        return FALSE;
    }

    // 获取图片的尺寸
    BITMAP bm;
    bitmap.GetBitmap(&bm);
    int bitmap_width = bm.bmWidth;
    int bitmap_height = bm.bmHeight;

    // 获取静态控件的矩形区域
    CRect rect;
    pStatic->GetWindowRect(&rect);
    ScreenToClient(&rect);

    // 调整静态控件的位置和大小
    rect.right = rect.left + bitmap_width;   // 设置新的宽度
    rect.bottom = rect.top + bitmap_height;  // 设置新的高度
    pStatic->MoveWindow(&rect);

    // 设置静态控件为位图模式并加载位图
    pStatic->ModifyStyle(0xF, SS_BITMAP | SS_CENTERIMAGE, SWP_NOSIZE);
    pStatic->SetBitmap((HBITMAP)bitmap.Detach());

	// 设置列表控件的风格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT;//网格线|某行高亮
	m_list.SetExtendedStyle(dwStyle);//设置拓展风格

	// 插入列
	m_list.InsertColumn(0, _T("工号ID"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(1, _T("姓氏"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(2, _T("名字"), LVCFMT_LEFT, 150);
	m_list.InsertColumn(3, _T("职位"), LVCFMT_LEFT, 200);
	m_list.InsertColumn(4, _T("内容"), LVCFMT_LEFT, 300);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
void CTnInfoDlg::LoadImages()
{
    m_bitmapPass.LoadBitmap(IDB_Pass); // 加载第一张图片
    m_bitmapFail.LoadBitmap(IDB_Fail); // 加载第二张图片
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTnInfoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTnInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTnInfoDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	
    if (m_pStaticImage)
    {
        m_pStaticImage->SetBitmap(m_bitmapPass);
    }
	 AfxMessageBox(_T("信息录入成功!"));  // 添加调试信息
	 
}


void CTnInfoDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	 
	
    if (m_pStaticImage)
    {
        m_pStaticImage->SetBitmap(m_bitmapFail);
    } 
	AfxMessageBox(_T("信息录入失败!"));  // 添加调试信息
}


void CTnInfoDlg::OnBnClickedOpenFile	()
{
	// TODO: 在此添加控件通知处理程序代码
	 // 定义过滤器
    CString filter = _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");

    // 创建文件对话框对象，使用定义的过滤器
    CFileDialog fileDlg(TRUE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, filter);


    // 显示对话框
    if (fileDlg.DoModal() == IDOK)
    {
        // 获取用户选择的文件路径
       filePath = fileDlg.GetPathName();
		// 设置初始目录
        // fileDlg.m_ofn.lpstrInitialDir = _T("C:\\Users\\YourUsername\\Documents");
		// 使用 std::ifstream 打开文件进行读取
		DataInterface.Open(filePath);

		UpdateList();
		//IsOpen = true;

		
     /*  std::ifstream fileStream(filePath.GetString()); 
	   if (fileStream.is_open())
        {
            CString fileContent;
            std::string line;

            // 逐行读取文件内容
            while (std::getline(fileStream, line))
            {
                fileContent += CString(line.c_str()) + _T("\n");
            }

            fileStream.close();

            // 显示文件内容在消息框中
            AfxMessageBox(fileContent);
        }
        else
        {
            AfxMessageBox(_T("无法打开文件"));
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
	// TODO: 在此添加控件通知处理程序代码
	 m_list.DeleteAllItems(); // 清空 List 控件中的所有项目
}


void CTnInfoDlg::OnBnClickedFileAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	ChildDlg dlg;
	if(IDOK==dlg.DoModal()){
		//Cinfo Info(atoi(dlg.m_id),dlg.m_lastname.GetBuffer(),dlg.m_firstname.GetBuffer(),dlg.m_date.GetBuffer(),dlg.m_content.GetBuffer());
		 // 验证ID是否为有效数字
      /*  int id = atoi(dlg.m_id);
        if (id == 0 && dlg.m_id != TEXT("0")) {
            MessageBox(TEXT("无效的ID输入！"));
            return;
          }

        // 使用GetBuffer()获取字符串数据，并调用ReleaseBuffer()释放
        CString lastname = dlg.m_lastname;
        CString firstname = dlg.m_firstname;
        CString date = dlg.m_date;
        CString content = dlg.m_content;

        // 创建Cinfo对象
        Cinfo Info(id, lastname.GetBuffer(), firstname.GetBuffer(), date.GetBuffer(), content.GetBuffer());

        // ReleaseBuffer()在字符串数据使用后调用
        lastname.ReleaseBuffer();
        firstname.ReleaseBuffer();
        date.ReleaseBuffer();
        content.ReleaseBuffer();
		*/
		// 使用 CT2A 将 CString 转换为 std::string
        std::string lastname = CT2A(dlg.m_lastname);
        std::string firstname = CT2A(dlg.m_firstname);
        std::string date = CT2A(dlg.m_date);
        std::string content = CT2A(dlg.m_content);

        // 将 id 转换为整数
        int id = atoi(dlg.m_id);

        // 使用转换后的 std::string 构造 Cinfo 对象
        Cinfo Info(id, lastname, firstname, date, content);
		DataInterface.Add(Info);
		UpdateList();
	}
}


void CTnInfoDlg::OnBnClickedFileadd()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CTnInfoDlg::OnBnClickedFiledelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	if (index > -1) {
		UINT i;
		i = MessageBox(_T("确定要删除这条记录吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			DataInterface.Del(index);
			MessageBox(TEXT("删除成功！"), TEXT("提示"));
			UpdateList();

		}
		else
		{
			return;
		}
	
	}
	else {
		MessageBox(TEXT("请选择要删除的行!"),TEXT("错误提示"));
	}
	
}