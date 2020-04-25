#include "stdafx.h"

cToolKit gToolKit;

void cToolKit::SetNop(DWORD offset,int size)
{
	for(int i = 0;i < size;i++)
	{
		*(BYTE*)(offset + i) = ASM::NOP;
	}
};

void cToolKit::SetByte(DWORD offset,BYTE value)
{
	*(BYTE*)(offset) = value;
};

void cToolKit::SetWord(DWORD offset,WORD value)
{
	*(WORD*)(offset) = value;
};

void cToolKit::SetDword(DWORD offset,DWORD value)
{
	*(DWORD*)(offset) = value;
};

void cToolKit::SetFloat(DWORD offset,float value)
{
	*(float*)(offset) = value;
};

void cToolKit::SetRange(LPVOID offset,USHORT count,BYTE value)
{
	LPBYTE lpBuf = new BYTE[count];

	memset(lpBuf,value,count);
	memcpy(offset,lpBuf,count);
}

void cToolKit::SetHook(BYTE head,DWORD offset,...)
{
	if(head != ASM::CALLD)
	{
		*(BYTE*)(offset) = head;
	}

	DWORD* function = &offset + 1;

	*(DWORD*)(offset + 1) = (*function) - (offset + 5);
};

void cToolKit::SetMemory(DWORD offset,DWORD value,DWORD size)
{
	memset((void*)offset,value,size);
};

void cToolKit::WriteMemory(DWORD offset,LPVOID value,DWORD size)
{
	memcpy((void*)offset,value,size);
};

bool cToolKit::FileExists(PCHAR File)
{
	struct stat Buff;
	return stat(File,&Buff) == 0;
};