EnsureSConsVersion(3, 0, 4)

makeit_sources = Glob('src/*.cpp')

excluded_lua = ['LUA/lua.c', 'LUA/luac.c']
lua_sources = [x for x in Glob('LUA/*.c') if str(x) not in excluded_lua]

box2d_sources = Glob('box2d/*.cpp')

imgui_sources = Glob('imgui/*.cpp')

general_headers = ['headers', 'LUA', 'imgui', 'SFML/include']
luabridge_headers = ['LuaBridge', 'LuaBridge/Source', 'LuaBridge/Source/LuaBridge']
# box2d_headers = ['box2d', 'box2d/Collision', 'box2d/Common', 'box2d/Dynamics', 'box2d/Rope']
box2d_headers = ['.', 'Box2D']

env = Environment(CPPPATH = general_headers + box2d_headers + luabridge_headers, CPPFLAGS = '-std=c++11')
env.Program('MakeIt', makeit_sources + lua_sources + box2d_sources + imgui_sources)