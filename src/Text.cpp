#include "Engine.h"
#include "Colour.h"
#include "Text.h"

using namespace luabridge;
using namespace MakeIt;

Text::Text()
{
	ENGINE_CONSTRUCTOR(this);
	_text = new sf::Text();
}

Text::~Text()
{
	if (_text)
		delete _text;

	ENGINE_DESTRUCTOR(this);
}

void Text::set_font(Font * font)
{
	_text->setFont(*font->get_font());
}

void Text::set_string(const char * text)
{
	_text->setString(text);
}

void Text::set_character_size(int size)
{
	_text->setCharacterSize(size);
}

void Text::set_fill_colour(Colour *colour)
{
	_text->setFillColor(colour->get_colour());
}

void Text::draw(sf::RenderWindow * window)
{
	if (_visible)
	{
		Node2D::draw(window);
		window->draw(*_text);
	}
}

void Text::set_position(const Vector2 *vector)
{
	Node2D::set_position(vector);

	_text->setPosition(vector->get_x(), vector->get_y());
}

void Text::register_class(lua_State *state)
{
	getGlobalNamespace(state).deriveClass<Text, Node2D>("Text")
		.addConstructor<void(*)(void), RefCountedPtr<Text>>()
		.addFunction("set_font", &Text::set_font)
		.addFunction("set_string", &Text::set_string)
		.addFunction("set_character_size", &Text::set_character_size)
		.addFunction("set_fill_colour", &Text::set_fill_colour)
		.endClass();
}