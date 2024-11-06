#include <lauxlib.h>
#include <lua.h>
#include <lualib.h>

#include "core.h"

int main(int argc, char **argv) {
  lua_State *L = init_plugins();
  call_plugin(L, argv[1]);

  return 0;
}
