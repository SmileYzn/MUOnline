#pragma once

class cCrack
{
public:
	void Load();

	// Fix TAB key on login
	static void AllowTabSwitchLogin();
};

extern cCrack gCrack;