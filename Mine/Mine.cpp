
// Mine.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "Mine.h"
#include "MainFrm.h"
#include "MineDef.h"
#include "MineDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMineApp

BEGIN_MESSAGE_MAP(CMineApp, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMineApp::OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
END_MESSAGE_MAP()


// CMineApp ����

CMineApp::CMineApp()
{
	m_bHiColorIcons = TRUE;

	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// ���Ӧ�ó��������ù�����������ʱ֧��(/clr)�����ģ���:
	//     1) �����д˸������ã�������������������֧�ֲ�������������
	//     2) ��������Ŀ�У������밴������˳���� System.Windows.Forms ������á�
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: ������Ӧ�ó��� ID �ַ����滻ΪΨһ�� ID �ַ�����������ַ�����ʽ
	//Ϊ CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("Mine.AppID.NoVersion"));

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}

// Ψһ��һ�� CMineApp ����

CMineApp theApp;


// CMineApp ��ʼ��
const CString className=_T("MineClass");
BOOL CMineApp::InitInstance()
{
	//����ע��MineWnd����
	m_pMineWnd=new CMineWnd();
	WNDCLASS wc;
	ZeroMemory(&wc,sizeof(wc));
	wc.hInstance=AfxGetInstanceHandle();
	wc.lpfnWndProc=DefWindowProcA;
	wc.hbrBackground=NULL;
	wc.hCursor=LoadCursor(IDC_ARROW);
	wc.hIcon=LoadIcon(IDR_MAINFRAME);
	wc.lpszClassName=className;
	wc.lpszMenuName=MAKEINTRESOURCE(IDR_MENU);
	if(!AfxRegisterClass(&wc))
	{
		AfxMessageBox(_T("ע����ʧ��"));
		return FALSE;
	}
	UINT uWidth=150;
	UINT uHeight=250;
	UINT uXPos=GetSystemMetrics(SM_CXSCREEN)/2-uWidth/2;
	UINT uYPos=GetSystemMetrics(SM_CYSCREEN)/2-uHeight/2;
	if (!m_pMineWnd->CreateEx(NULL,className,_T("ɨ��"),
		WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX,
		uXPos,uYPos,uWidth,uHeight,
		NULL,NULL))
	{
		AfxMessageBox(_T("����������ʧ��"));
		return FALSE;
	}
	//�󶨸ô���Ϊ������
	m_pMainWnd=m_pMineWnd;
	//��ʾ
	m_pMainWnd->ShowWindow(SW_NORMAL);
	return TRUE;
	
}

// CMineApp ��Ϣ�������


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
public:
	afx_msg void OnMenuAbout();
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

// �������жԻ����Ӧ�ó�������
void CMineApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMineApp �Զ������/���淽��

void CMineApp::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	//GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
}

void CMineApp::LoadCustomState()
{
}

void CMineApp::SaveCustomState()
{
}

// CMineApp ��Ϣ�������

