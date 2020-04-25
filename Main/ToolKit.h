#pragma once

namespace ASM
{
	enum T
	{
		EAX		= 0x50,
		JMP		= 0xE9,
		JMPS	= 0xEB,
		JE		= 0x74,
		JNE		= 0x75,
		JGE		= 0x7D,
		NOP		= 0x90,
		CALL	= 0xE8,
		CALLD	= 0xFF,
		PUSH	= 0x68,
		RETN	= 0xC3
	};
};

class cToolKit
{
public:
	void SetNop(DWORD offset,int size);
	void SetByte(DWORD offset,BYTE value);
	void SetWord(DWORD offset,WORD value);
	void SetDword(DWORD offset,DWORD value);
	void SetFloat(DWORD offset,float value);
	void SetRange(LPVOID offset,USHORT count,BYTE value);
	void SetHook(BYTE head,DWORD offset,...);
	void SetMemory(DWORD offset,DWORD value,DWORD size);
	void WriteMemory(DWORD offset,LPVOID value,DWORD size);
	bool FileExists(PCHAR File);
};

extern cToolKit gToolKit;