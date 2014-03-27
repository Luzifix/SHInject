enum CommandCategory
{
	CATEGORY_DEBUG = 0x0,
	CATEGORY_GRAPHICS = 0x1,
	CATEGORY_CONSOLE = 0x2,
	CATEGORY_COMBAT = 0x3,
	CATEGORY_GAME = 0x4,
	CATEGORY_DEFAULT = 0x5,
	CATEGORY_NET = 0x6,
	CATEGORY_SOUND = 0x7,
	CATEGORY_GM = 0x8,
	NUM_CMD_CATEGORIES = 0x9
};

enum COLOR_T
{
	DEFAULT_COLOR = 0x0,
	INPUT_COLOR = 0x1,
	ECHO_COLOR = 0x2,
	ERROR_COLOR = 0x3,
	WARNING_COLOR = 0x4,
	GLOBAL_COLOR = 0x5,
	ADMIN_COLOR = 0x6,
	HIGHLIGHT_COLOR = 0x7,
	BACKGROUND_COLOR = 0x8,
	NUM_COLORTYPES = 0x9,
};

typedef BOOL(*CommadHandler)(char const* cmd, char const* args);
typedef BOOL(*ConsoleCommandRegisterPtr)(char const* command, CommadHandler handler, CommandCategory category, char const* help);
typedef void(*ConsoleCommandUnregisterPtr)(char const* command);
typedef void(*ConsoleWrite)(char const* value, COLOR_T color, ...);

class GameConsole
{
public:
	static void							Enable(bool status);
	static ConsoleWrite					Write;
	static ConsoleCommandRegisterPtr	RegisterCommand;
	static ConsoleCommandUnregisterPtr	UnregisterCommand;
};