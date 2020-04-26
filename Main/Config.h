#pragma once

// Main configuration file
#define CONFIG_INI_FILE		".\\config.ini"

// Protected config
#define CONFIG_BMD_MAIN		".\\Data\\Custom\\Main.bmd"

class cConfig
{
public:
	cConfig();

	void	Load();

private:
	int		m_Port;
	char	m_Address[16];
	char	m_Version[6];
	char	m_Serial[20];
};

extern cConfig gConfig;