#include "header.h"

//Functions
void Wow::PatchTLS() {
	// patch TLS to be able to access data from WoW's main thread
	// buggy
	_asm {
		mov eax, dword ptr fs:[0x2c] 
		mov eax, dword ptr ds:[eax]
		add eax, 8
		mov ebx, dword ptr ds:[0x012705b0]
		mov ebx, dword ptr ds:[eax + 0x00002d94]
		mov [eax], ebx
	}
};