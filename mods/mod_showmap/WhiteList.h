#if !defined(AFX_WHITELIST_H__2B7D4FF7_3CD1_48AC_9D96_98AFC9020887__INCLUDED_)
#define AFX_WHITELIST_H__2B7D4FF7_3CD1_48AC_9D96_98AFC9020887__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WhiteList.h : header file
//
#include "TibiaTile.h"
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// CMapConfig dialog

class CMapConfig : public CDialog
{
// Construction
public:
	int xMem;
	int yMem;
	int currentStackPos;
	CTibiaTile *memTilesForConfig[10];
	int tileId[10];
	CMapConfig(CTibiaTile *memTilesForConfig[10], int, int, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMapConfig)
	enum { IDD = IDD_TOOL_MAPSHOW_CONFIG };
	CEdit m_TileId;
	CEdit m_Speed;\
	CButton m_AlwaysOnTop;
	CButton m_MoreAlwayOnTop;
	CButton m_Blocking;
	CButton m_Walkable;
	CButton m_GoDown;
	CButton m_GoUp;
	CButton m_Ground;
	CButton m_Container;
	CButton m_Depot;
	CButton m_Moveable;
	CButton m_RequireRope;
	CButton m_RequireShovel;
	CButton m_RequireUse;
	CButton m_Stackable;
	CButton m_Previous;
	CButton m_Next;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapConfig)
	protected:
	virtual void OnCommit();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMapConfig)
	afx_msg void OnPreviousTile();
	afx_msg void OnNextTile();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Mem2Config();
	void ConfigToMem();
	void loadTile(int, int);
	void saveTile();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHITELIST_H__2B7D4FF7_3CD1_48AC_9D96_98AFC9020887__INCLUDED_)
