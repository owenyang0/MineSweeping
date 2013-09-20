#pragma once
#include "afxwin.h"



#pragma   comment(lib, "Winmm.lib ")







typedef struct 
{
	UINT uRow;         //����������ά�������
	UINT uCol;         //����������λ�������
	UINT uState;       //��ǰ״̬
	UINT uAttrib;      //��������
	UINT uOldState;    //��ʷ״̬
} MINEWND;	// �׷���ṹ��

/////////////////////////////////////////////////////////////////////////////
class CMineWnd :
	public CWnd
{
public:
	CMineWnd(void);
	~CMineWnd(void);
	// �趨���ڴ�С
	void SizeWindow(void);
protected :
	UINT		m_uXNum;				// X����С�������
	UINT		m_uYNum;				// Y����С�������
	UINT		m_uGameState;			// ��Ϸ״̬
	UINT		m_uMineNum;				// �ܵ��׸���
	UINT		m_uTimer;				// ��ʱ����ʶ
	UINT		m_uSpendTime;			// ��Ϸ��ʼ����Ŀǰ�����ѵ�ʱ��
	int 		m_nLeaveNum;			// ʣ����׸���

	UINT		m_uLevel;				// ��ǰ��Ϸ�ȼ�
	BOOL		m_bLRBtnDown;			// �Ƿ�Ϊ���Ҽ�ͬʱ����
	BOOL		m_bClickBtn;			// ������µ�ʱ������Ƿ�λ�ڰ�ť������
	UINT		m_uBtnRect[3];			// ��ť��������������
	BOOL		m_bColorful;			// �Ƿ��ɫ��ʾ
	BOOL		m_bSoundful;			// �Ƿ�������
	UINT		m_uBtnState;			// ��ť״̬
	CBitmap		m_bmpMine;				// ��������ͼ��
	RECT		m_rcClient;				// �ͻ�����
	CBrush		m_brsBG;				// ������ˢ����
	COLORREF	m_clrDark;				// ����ť����ɫ��
	CBitmap		m_bmpNumber;			// ���ֱ���ͼ��
	CBitmap		m_bmpButton;			// Ц����ť����ͼ��
	UINT		m_uNumRect[3];			// ���ֿ�������������(����ʱ����׸���)
	UINT		m_uShellRcX[2];			// �ڿ��Լ��߽������X����
	UINT		m_uShellRcY[2];			// �ڿ��Լ��߽������Y����
	CMenu*		m_pSubMenu;				// �Ӳ˵�


	MINEWND		m_pMines[100][100];		// ��ʾ�����ڵ�����С����Ķ�ά����
	MINEWND*	m_pNewMine;				// ��ǰѡ�е�С����
	MINEWND*	m_pOldMine;				// �ϴ�ѡ�е�С����


	void*		m_pSndClock;			// ʱ����ʾ��
	void*		m_pSndDead;				// ʧ����ʾ��
	void*		m_pSndVictory;			// ʤ����ʾ��
	


	BOOL		m_bMarkful;				// �Ƿ�����ʾ���

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuPrimary();
	afx_msg void OnMenuColor();
	afx_msg void OnMenuSound();
	afx_msg void OnMenuAbout();
	// ����
	void LayMines(UINT row, UINT col);

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// ��ȡ��ͼ��(x,y)���������Ϣ
	MINEWND* GetMine(long x, long y);
	// �ж��Ƿ�Ϊ��
	BOOL IsMine(UINT row, UINT col);
	// ��ȡĳ��С������������8��������׸���
	UINT GetAroundNum(UINT row, UINT col);
	// �׷������չ��������Χ���׵Ŀհ�����
	void ExpandMines(UINT row, UINT col);
	// ʤ���жϲ�����
	BOOL Victory(void);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	// ��Ϸ�ĳ�ʼ��
	void InitGame(void);
	// ʧ�ܵĴ���
	void Dead(UINT row, UINT col);
	// �ж��Ƿ�������
	BOOL IsInMineArea(UINT row, UINT col);
	void LoadBitmap(void);
	// ��������
	void DrawMineArea(CPaintDC &dc);
	afx_msg void OnPaint();
	//  ����Ц����ťͼ
	void DrawButton(CPaintDC &dc);
	// ��������
	void DrawNumber(CPaintDC &dc);
	// �������
	void DrawShell(CPaintDC &dc);

	// both button click fuctions
	void OnLRBtnDown(UINT row, UINT col);
	void OnLRBtnUp(UINT row, UINT col);
	void OpenAround(UINT row, UINT col);
	BOOL ErrorAroundFlag(UINT row, UINT col/*, UINT &errorRow, UINT &errorCol*/);
	void OpenByCheat();
	UINT GetAroundFlags(UINT row, UINT col);



	void DrawDownNum(MINEWND* mine, UINT num);
	void DrawSpecialMine(UINT row, UINT col);
	void SetCheckedLevel();

	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	// //��������
	void LoadWaveSrc(void);
	void FreeWaveSrc(void);
	afx_msg void OnMenuSecond();
	afx_msg void OnMenuAdvance();
	afx_msg void OnMenuStart();
	afx_msg void OnMenuMark();
	void SetCheckedMark(void);
	void SetCheckedCheat(void);
	afx_msg void OnInitMenu(CMenu* pMenu);
	void SetCheckedColor(void);
	void SetCheckedSound(void);
	afx_msg void OnMenuExit();
	afx_msg void OnMenuHero();
	afx_msg void OnMenuCustom();
	void SaveConfig(void);
	void GetConfig(void);
	afx_msg void OnClose();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};

