
// MineView.h : CMineView ��Ľӿ�
//

#pragma once


class CMineView : public CView
{
protected: // �������л�����
	CMineView();
	DECLARE_DYNCREATE(CMineView)

// ����
public:
	CMineDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CMineView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MineView.cpp �еĵ��԰汾
inline CMineDoc* CMineView::GetDocument() const
   { return reinterpret_cast<CMineDoc*>(m_pDocument); }
#endif

