#include "Header.h"

void(*GameConsole::Write)(char const* value, COLOR_T color, ...) = reinterpret_cast<ConsoleWrite>(ConsoleWriteAddr);
BOOL(*GameConsole::RegisterCommand)(char const* command, CommadHandler handler, CommandCategory category, char const* help) = reinterpret_cast<ConsoleCommandRegisterPtr>(ConsoleRegisterCommandAddr);
void(*GameConsole::UnregisterCommand)(char const* command) = reinterpret_cast<ConsoleCommandUnregisterPtr>(ConsoleUnregisterCommandAddr);

void GameConsole::Enable(bool status) {
	if (status) {
		*reinterpret_cast<DWORD*>(ConsoleStatusAddr) = 1;
	}
	else {
		*reinterpret_cast<DWORD*>(ConsoleStatusAddr) = 0;
	}
}