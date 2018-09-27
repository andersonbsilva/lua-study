/*
  Simple command line interpreter.
*/
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

int main (void) 
{
	char buff[256]; int error;
	/* create new state */
	lua_State *L = luaL_newstate();
	/* open system libraries */
	luaL_openlibs(L);
	printf("> ");
	while (fgets(buff, sizeof(buff), stdin) != NULL) {
		/* load buffer, execute and leave the result at the stack */
		error = luaL_loadstring(L, buff) || lua_pcall(L, 0, 0, 0); if (error) {
			fprintf(stderr, "%s\n", lua_tostring(L, -1));
			lua_pop(L, 1); /* pop error message from the stack */ }
		printf("> ");
	}
	lua_close(L);
	return 0; 
}
