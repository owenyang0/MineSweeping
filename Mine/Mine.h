
// Mine.h : Mine Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "MineWnd.h"
// CMineApp:
// �йش����ʵ�֣������ Mine.cpp
//

class CMineApp : public CWinAppEx
{
public:
	CMineApp();
	CMineWnd *m_pMineWnd;

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
private:
	UINT m_uXMineNum;
	UINT m_uYMineNum;
};

extern CMineApp theApp;
