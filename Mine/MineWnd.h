#pragma once
#include "afxwin.h"



#pragma   comment(lib, "Winmm.lib ")







typedef struct 
{
	UINT uRow;         //所在雷区二维数组的行
	UINT uCol;         //所在雷区二位数组的列
	UINT uState;       //当前状态
	UINT uAttrib;      //方块属性
	UINT uOldState;    //历史状态
} MINEWND;	// 雷方块结构体

/////////////////////////////////////////////////////////////////////////////
class CMineWnd :
	public CWnd
{
public:
	CMineWnd(void);
	~CMineWnd(void);
	// 设定窗口大小
	void SizeWindow(void);
protected :
	UINT		m_uXNum;				// X方向小方块个数
	UINT		m_uYNum;				// Y方向小方块个数
	UINT		m_uGameState;			// 游戏状态
	UINT		m_uMineNum;				// 总的雷个数
	UINT		m_uTimer;				// 定时器标识
	UINT		m_uSpendTime;			// 游戏开始击到目前所花费的时间
	int 		m_nLeaveNum;			// 剩余的雷个数

	UINT		m_uLevel;				// 当前游戏等级
	BOOL		m_bLRBtnDown;			// 是否为左右键同时按下
	BOOL		m_bClickBtn;			// 左键按下的时候鼠标是否位于按钮区域内
	UINT		m_uBtnRect[3];			// 按钮框区域坐标数组
	BOOL		m_bColorful;			// 是否彩色显示
	BOOL		m_bSoundful;			// 是否有声音
	UINT		m_uBtnState;			// 按钮状态
	CBitmap		m_bmpMine;				// 雷区背景图像
	RECT		m_rcClient;				// 客户区域
	CBrush		m_brsBG;				// 背景画刷对象
	COLORREF	m_clrDark;				// 各按钮的深色调
	CBitmap		m_bmpNumber;			// 数字背景图像
	CBitmap		m_bmpButton;			// 笑脸按钮背景图像
	UINT		m_uNumRect[3];			// 数字框区域坐标数组(包括时间和雷个数)
	UINT		m_uShellRcX[2];			// 内框以及边界的坐标X方向
	UINT		m_uShellRcY[2];			// 内框以及边界的坐标Y方向
	CMenu*		m_pSubMenu;				// 子菜单


	MINEWND		m_pMines[100][100];		// 表示雷区内的所有小方块的二维数组
	MINEWND*	m_pNewMine;				// 当前选中的小方块
	MINEWND*	m_pOldMine;				// 上次选中的小方块


	void*		m_pSndClock;			// 时钟提示音
	void*		m_pSndDead;				// 失败提示音
	void*		m_pSndVictory;			// 胜利提示音
	


	BOOL		m_bMarkful;				// 是否能显示标记

public:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMenuPrimary();
	afx_msg void OnMenuColor();
	afx_msg void OnMenuSound();
	afx_msg void OnMenuAbout();
	// 布雷
	void LayMines(UINT row, UINT col);

	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	// 获取体图中(x,y)区域的雷信息
	MINEWND* GetMine(long x, long y);
	// 判断是否为雷
	BOOL IsMine(UINT row, UINT col);
	// 获取某个小方块区域相信8个区域的雷个数
	UINT GetAroundNum(UINT row, UINT col);
	// 雷方块的拓展（对于周围无雷的空白区域）
	void ExpandMines(UINT row, UINT col);
	// 胜利判断并处理
	BOOL Victory(void);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	// 游戏的初始化
	void InitGame(void);
	// 失败的处理
	void Dead(UINT row, UINT col);
	// 判断是否在雷区
	BOOL IsInMineArea(UINT row, UINT col);
	void LoadBitmap(void);
	// 绘制雷区
	void DrawMineArea(CPaintDC &dc);
	afx_msg void OnPaint();
	//  绘制笑脸按钮图
	void DrawButton(CPaintDC &dc);
	// 绘制数字
	void DrawNumber(CPaintDC &dc);
	// 绘制外壳
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
	// //导入声音
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

