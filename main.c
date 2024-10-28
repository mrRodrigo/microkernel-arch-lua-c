#include <lua.h>                                
#include <lauxlib.h>                            
#include <lualib.h>                             
                                                

#include <stdlib.h>                             
#include <stdio.h>                              

void bail(lua_State *L, char *msg){
	fprintf(stderr, "\nFATAL ERROR:\n  %s: %s\n\n",
		msg, lua_tostring(L, -1));
	exit(1);
}

int main(void)
{
    lua_State *L;

    L = luaL_newstate();                        
    luaL_openlibs(L);                           

    if (luaL_loadfile(L, "src/core/lua/plugin_registry.lua")) 
        bail(L, "luaL_loadfile() failed");      

    if (lua_pcall(L, 0, 0, 0))                  
        bail(L, "lua_pcall() failed");          

    printf("In C, calling Lua->LoadPlugins()\n");

    lua_getglobal(L, "LoadPlugins");                 
    if (lua_pcall(L, 0, 0, 0))
      bail(L, "lua_pcall() failed");          

    lua_getglobal(L, "RunPlugin");
    lua_pushstring(L, "hello");
    
    if (lua_pcall(L, 1, 0, 0))
      bail(L, "lua_pcall() failed");

    lua_close(L);                               
    return 0;
}
