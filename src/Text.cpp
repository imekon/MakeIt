#include "Text.h"

using namespace luabridge;
using namespace MakeIt;

Text::Text() : _text(nullptr)
{

}

Text::~Text()
{
	if (_text)
		delete _text;
}

void Text::set_font(Font * font)
{
	_text->setFont(*font->get_font());
}

void Text::set_string(const char * text)
{
	_text->setString(text);
}

void Text::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<Text>("Text")
		.addConstructor<void(*)(void), RefCountedPtr<Text>>()
		.addFunction("set_font", &Text::set_font)
		.addFunction("set_string", &Text::set_string)
		.endClass();
}