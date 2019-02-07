#include "Font.h"

using namespace luabridge;
using namespace MakeIt;

Font::Font() : _font(nullptr)
{
}

Font::~Font()
{
	if (_font)
		delete _font;
}

bool MakeIt::Font::load(const char * filename)
{
	_font = new sf::Font();
	if (_font->loadFromFile(filename))
		return true;

	return false;
}

void MakeIt::Font::register_class(lua_State * state)
{
	getGlobalNamespace(state).beginClass<Font>("Font")
		.addConstructor<void(*)(void), RefCountedPtr<Font>>()
		.addFunction("load", &Font::load)
		.endClass();
}
