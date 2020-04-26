#include "stdafx.h"

cConfig gConfig;

cConfig::cConfig()
{
	/**/
}

void cConfig::Load()
{
	CMemScript* lpMemScript = new CMemScript;

	if(lpMemScript == NULL)
	{
		MessageBox(NULL,MEM_SCRIPT_ALLOC_ERROR,CONFIG_BMD_MAIN,MB_OK|MB_ICONERROR);
		ExitProcess(0);
		return;
	}

	if(lpMemScript->SetBuffer(CONFIG_BMD_MAIN) == false)
	{
		MessageBox(NULL,lpMemScript->GetLastError(),CONFIG_BMD_MAIN,MB_OK|MB_ICONERROR);
		ExitProcess(0);

		delete lpMemScript;
		return;
	}

	try
	{
		while(true)
		{
			if(lpMemScript->GetToken() == TOKEN_END || strcmp("end",lpMemScript->GetString()) == 0)
			{
				break;
			}

			// Load Port
			this->m_Port = lpMemScript->GetNumber();

			// Load IP Address
			memcpy(this->m_Address,lpMemScript->GetAsString(),sizeof(this->m_Address));

			// Load Version
			memcpy(this->m_Version,lpMemScript->GetAsString(),sizeof(this->m_Version));

			// Load Serial
			memcpy(this->m_Serial,lpMemScript->GetAsString(),sizeof(this->m_Serial));
		}

		// Set Port
		g_MainServerPort = this->m_Port;

		// Set Address
		gToolKit.WriteMemory(g_MainAddress,this->m_Address,sizeof(this->m_Address));

		// Set Version
		gToolKit.WriteMemory(g_MainVersion,this->m_Version,sizeof(this->m_Version));

		// Set Serial
		gToolKit.WriteMemory(g_MainSerial,this->m_Serial,sizeof(this->m_Serial));
	}
	catch(...)
	{
		MessageBox(NULL,lpMemScript->GetLastError(),CONFIG_BMD_MAIN,MB_OK|MB_ICONERROR);
		ExitProcess(0);
	}

	delete lpMemScript;
}