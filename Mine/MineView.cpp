
// MineView.cpp : CMineView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "Mine.h"
#endif

#include "MineDoc.h"
#include "MineView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMineView

IMPLEMENT_DYNCREATE(CMineView, CView)

BEGIN_MESSAGE_MAP(CMineView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMineView ����/����

CMineView::CMineView()
{
	// TODO: �ڴ˴���ӹ������

}

CMineView::~CMineView()
{
}

BOOL CMineView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CMineView ����

void CMineView::OnDraw(CDC* /*pDC*/)
{
	CMineDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}

void CMineView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMineView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMineView ���

#ifdef _DEBUG
void CMineView::AssertValid() const
{
	CView::AssertValid();
}

void CMineView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMineDoc* CMineView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMineDoc)));
	return (CMineDoc*)m_pDocument;
}
#endif //_DEBUG


// CMineView ��Ϣ�������
