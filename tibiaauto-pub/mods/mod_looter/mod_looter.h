// mod_looter.h : main header file for the MOD_LOOTER DLL
//

#if !defined(AFX_MOD_LOOTER_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_)
#define AFX_MOD_LOOTER_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif // ifndef __AFXWIN_H__

#include "resource.h"           // main symbols
#include <IModuleInterface.h>
#include "ConfigDialog.h"

/////////////////////////////////////////////////////////////////////////////
// CMod_looterApp
// See mod_looter.cpp for the implementation of this class
//

struct Item {
	Item()
	{
	}
};

struct Corpse
{
	char name[40];
	int x, y, z;
	int timeOfDeath;
	int itemId;
	int pos;//position from end of array as this is usually static
	Corpse *prev;
	Corpse *nxt;
	void push(Corpse *pred)
	{
		pred->insertNodeAfter(prev);
	}

	void insertNodeAfter(Corpse *pred)
	{
		//remove node
		prev->nxt = nxt;
		nxt->prev = prev;
		//insert node
		nxt       = pred->nxt;
		prev      = pred;
		pred->nxt = this;
		if (pred->nxt != NULL)
			pred->nxt->prev = this;
	}

	int distance(int x, int y)
	{
		return max(abs(this->x - x), abs(this->y - y));
	}

	Corpse()
	{
		timeOfDeath = itemId = x = y = z = pos = 0;
		memset(name, 0, 40);
		nxt = prev = this;
	}
};

class CMod_looterApp : public IModuleInterface
{
public:
	CMod_looterApp();
	~CMod_looterApp();
public:
	void getNewSkin(CSkin);
	int validateConfig(int showAlerts);
	// functions from IModuleInterface
	char * getName();
	int isStarted();
	void start();
	void stop();
	void showConfigDialog();
	void configToControls();
	void controlsToConfig();
	void disableControls();
	void enableControls();
	char *getVersion();
	void resetConfig();
	void loadConfigParam(const char *paramName, char *paramValue);
	char *saveConfigParam(const char *paramName);
	const char **getConfigParamNames();
private:
	int m_started;
	CConfigDialog * m_configDialog;
	CConfigData *m_configData;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOD_LOOTER_H__D1220A19_D7FC_4B51_900D_224C2CAC1CB8__INCLUDED_)
