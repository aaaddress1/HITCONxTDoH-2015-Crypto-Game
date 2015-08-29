#include "stdafx.h"
#include <string>
#define db(n) _asm{__emit n}
char InputData[100] = {0};
char FailMessage[] = "Sorry, password isn't correct. :(\n";
char SucessMessage[] = "Geek! password is correct! :D\n";


void __declspec(naked)CryptoKey()
{
	db(127); db('X'); db('O'); db('R');
}
void __declspec(naked)KeyCryptoData()
{
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
	db('a'); db('d'); db('r'); db('k'); db('_'); db('a'); db('d'); db('r'); db('k'); db('_');
}

void __declspec(naked)FailMessageReal()
{
	db('S'); db('o'); db('r'); db('r'); db('y'); db(','); db(' '); db('p'); db('a'); db('s'); db('s'); db('w'); 
	db('o'); db('r'); db('d'); db(' '); db('i'); db('s'); db('n'); db('\''); db('t'); db('c'); db('o'); db('r');
	db('r'); db('e'); db('c'); db('t'); db('.'); db(':'); db('('); db('\n'); db(0);
}

void __declspec(naked)SucessMessageReal()
{
	db('G'); db('e'); db('e'); db('k'); db('!'); db('p'); db('a'); db('s'); db('s'); db('w'); db('o'); db('r');
	db('d'); db('i'); db('s'); db('c'); db('o'); db('r'); db('r'); db('e'); db('c'); db('t'); db('!'); db(':');
	db('D'); db('\n'); db(0);
}
int __declspec(naked)Func()
{
	_asm
	{
		pop eax
	}

	for (int i = 0;; i++)
	{
		char TempA = *(char*)((int)KeyCryptoData+i);
		if (TempA == 0) break;
		char TempB = InputData[i];
		TempA ^= *(char*)CryptoKey;
		if (TempA != TempB)
		{
			printf((char*)(FailMessageReal));
			_tsystem(L"PAUSE");
			goto LeaveFunc;
		}
	}
		
SucessedStep:
	printf((char*)(SucessMessageReal));
	_tsystem(L"PAUSE");

LeaveFunc:
	_asm
	{
		mov esp,ebp
		pop ebp
		ret
	}
}

/*=======================================Juke-Trick-Start=======================================*/

/* 
ror eax, 02 = \xC1\xc8\x02 
ror ecx, 02 = \xC1\xc9\x02
ror edx, 02 = \xC1\xca\x02
ror ebx, 02 = \xC1\xcb\x02

scasd = \xAF
stosb = \xAA
lodsb = \xAC

ret = \x5D\xC3
*/
void JunkCode()
{
	int Var = 0;

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	db('a'); db('a'); db('a'); db('d'); db('d'); db('r'); db('e'); db('s'); db('s'); db('1');
	db('_'); db('s'); db('m'); db('a'); db('r'); db('t'); db('_'); db('a'); db('n'); db('d');
	db('_'); db('h'); db('a'); db('n'); db('d'); db('s'); db('o'); db('m'); db('e'); db('!');

	for (int i = 0; i < strlen(InputData); i++)
	{
		InputData[i] = InputData[i] ^ 2 * (InputData[i] >> 2) + 7;
		for (int j = i + 1; j < strlen(InputData); j++)
		{
			InputData[i] = InputData[j] * 2 * (InputData[j] + 2) + 5;
			for (int k = j + 1; k < strlen(InputData); k++)
			{
				InputData[k] = InputData[k] * 2 * (InputData[j] + 2) + 3;
				Var -= InputData[k];
			}
		}
	}
	printf(Var == 1 ? SucessMessage : FailMessage);
	_tsystem(L"PAUSE");
}


/*=======================================Juke-Trick-End =======================================*/

int _tmain(int argc, _TCHAR* argv[])
{
	try
	{
		printf("##### #####         ###  ### \n");
		printf("# # #  #   #         #    #  \n");
		printf("  #    #    #  ###   #    #  \n");
		printf("  #    #    # #   #  ######  \n");
		printf("  #    #    # #   #  #    #  \n");
		printf("  #    #   #  #   #  #    #  \n");
		printf(" ###  #####    ###  ###  ### \n\n");
		printf("Welcome to play TDoH Game!\n");
		printf("I'm aaaddress1(ADR) :D\n");
		printf("\nNeed some hints?\nJoin my talk \"IDA Pro Hex-Rays Decompiler Cheat(R4)\" HITCON Day1 at 16:10\n\n");
		printf("Please input your password to get a gift(limited offer).\nPassword: ");
		scanf_s ("%s", &InputData,100);
		Func();
		_asm
		{
			push 00
			mov eax, [esp]
			mov eax, [eax]
			add esp,04
			jmp JunkCode
		}
	}
	catch (...)
	{
		Func();
	}
	return 0;
}

