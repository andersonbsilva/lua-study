/*
 Example: 
   It is a C program that executes an lua script that call a function
   defined in C. 
*/
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int myadd(lua_State* L);

int main()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);

	lua_pushcfunction(L, myadd);
	/* export to lua function 'myadd' as 'add' */
	lua_setglobal(L, "add");

	luaL_dofile(L, "test.lua");

	lua_getglobal(L, "x");

	printf("result=%f\n", lua_tonumber(L, -1));

	lua_close(L);

	return 0;
}

int myadd(lua_State* L)
{
	double n1 = lua_tonumber(L, 1);	
	double n2 = lua_tonumber(L, 2);	

	lua_pushnumber(L, n1+n2);

	return 1;
}
