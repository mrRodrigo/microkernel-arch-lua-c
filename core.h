#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

lua_State *init_plugins(void);

void call_plugin(lua_State *L, const char *name);
