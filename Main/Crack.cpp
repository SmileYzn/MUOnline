#include "stdafx.h"

cCrack gCrack;

void __declspec(naked) cCrack::AllowTabSwitchLogin()
{
	_asm
	{
		PUSH 0
		MOV EAX, DWORD PTR SS:[EBP-0x38]
		MOV ECX, DWORD PTR DS:[EAX+0x350]
		MOV EDX, DWORD PTR SS:[EBP-0x38]
		MOV EAX, DWORD PTR DS:[EDX+0x350]
		MOV EDX, DWORD PTR DS:[EAX]
		CALL DWORD PTR DS:[EDX+0x30]
		MOV EAX, DWORD PTR SS:[EBP-0x38]
		MOV ECX, DWORD PTR DS:[EAX+0x354]
		PUSH ECX
		MOV EDX, DWORD PTR SS:[EBP-0x38]
		MOV ECX, DWORD PTR DS:[EDX+0x350]
		MOV EAX, DWORD PTR SS:[EBP-0x38]
		MOV EDX, DWORD PTR DS:[EAX+0x350]
		MOV EAX, DWORD PTR DS:[EDX]
		CALL DWORD PTR DS:[EAX+oFixTabKeyLogin_Byte]
		MOV ECX, DWORD PTR SS:[EBP-0x38]
		MOV EDX, DWORD PTR DS:[ECX+0x350]
		PUSH EDX
		MOV EAX, DWORD PTR SS:[EBP-0x38]
		MOV ECX, DWORD PTR DS:[EAX+0x354]
		MOV EDX, DWORD PTR SS:[EBP-0x38]
		MOV EAX, DWORD PTR DS:[EDX+0x354]
		MOV EDX, DWORD PTR DS:[EAX]
		CALL DWORD PTR DS:[EDX+oFixTabKeyLogin_Byte]
		MOV EDX, oAllowTabSwithLoginJMP
		JMP EDX
	}
}

void cCrack::Load()
{
	// Bypass MU.exe Call
	gToolKit.SetByte(oMainCrack1,ASM::JMPS);

	// Bypass Config.ini Read Error
	gToolKit.SetByte(oMainCrack2,ASM::JMPS);

	// Bypass ResourceGuard Error!!(%s)
	gToolKit.SetByte(oMainCrack_4_1,ASM::JMPS);
	gToolKit.SetByte(oMainCrack_4_2,ASM::JMPS);
	gToolKit.SetByte(oMainCrack_4_3,ASM::JMPS);
	gToolKit.SetByte(oMainCrack_4_4,ASM::JMPS);

	// Disable Game Guard Call
	gToolKit.SetMemory(oMainCrack_5_1,ASM::NOP,5);
	gToolKit.SetMemory(oMainCrack_5_2,ASM::NOP,5);
	gToolKit.SetMemory(oMainCrack_5_3,ASM::NOP,5);
	gToolKit.SetMemory(oMainCrack_5_4,ASM::NOP,5);

	// Bypass GG init read Error
	gToolKit.SetByte(oMainCrack3_1,0xE9);
	gToolKit.SetByte(oMainCrack3_2,0x8B);
	gToolKit.SetByte(oMainCrack3_3,0x00);
	gToolKit.SetByte(oMainCrack3_4,0x90);

	// Fix TAB key on login screen
	gToolKit.SetHook(ASM::JMP,oFixTabKeyLogin,this->AllowTabSwitchLogin);

	// Enable account field
	gToolKit.SetByte(oAccountField,0x00);

	// Disable Web Check
	gToolKit.SetByte(oWebCheck,ASM::JMPS);

	// Disable CMS Starter
	gToolKit.SetWord(oCMStarterA,0x350);	
	gToolKit.SetWord(oCMStarterB,0x350);
	gToolKit.SetByte(oCMStarterC,0x18);

	// Bypass terrain files error
	gToolKit.SetByte(oFixTerrainFiles_1,ASM::JMPS);
	gToolKit.SetByte(oFixTerrainFiles_2,ASM::JMPS);
	gToolKit.SetByte(oFixTerrainFiles_3,ASM::JMPS);
	gToolKit.SetByte(oFixTerrainFiles_4,ASM::JMPS);
	gToolKit.SetByte(oFixTerrainFiles_5,ASM::JMPS);
	gToolKit.SetByte(oFixTerrainFiles_6,ASM::JMPS);

	// Bypass Text.bmd limit
	gToolKit.SetByte(oFixTextBMD,0xEB);
}