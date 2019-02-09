#include "Colour.h"

using namespace luabridge;
using namespace MakeIt;

Colour::Colour()
{
}

void MakeIt::Colour::set_rgba(int red, int green, int blue, int alpha)
{
	_colour.r = red;
	_colour.g = green;
	_colour.b = blue;
	_colour.a = alpha;
}

void MakeIt::Colour::set_rgb(int red, int green, int blue)
{
	_colour.r = red;
	_colour.g = green;
	_colour.b = blue;
}

void MakeIt::Colour::set_red(int red)
{
	_colour.r = red;
}

void MakeIt::Colour::set_green(int green)
{
	_colour.g = green;
}

void MakeIt::Colour::set_blue(int blue)
{
	_colour.b = blue;
}

void MakeIt::Colour::set_alpha(int alpha)
{
	_colour.a = alpha;
}

Colour *Colour::from_rgba(int red, int green, int blue, int alpha)
{
	auto colour = new Colour();
	colour->_colour.r = red;
	colour->_colour.g = green;
	colour->_colour.b = blue;
	colour->_colour.a = alpha;
	return colour;
}

Colour *Colour::from_rgb(int red, int green, int blue)
{
	auto colour = new Colour();
	colour->_colour.r = red;
	colour->_colour.g = green;
	colour->_colour.b = blue;
	colour->_colour.a = 255;
	return colour;
}

Colour *Colour::from_name(const char *name)
{
	static struct
	{
		const char *name;
		sf::Color colour;
	} colours[] =
	{
		"black",			sf::Color::Black,
		"white",			sf::Color::White,
		"red",				sf::Color::Red,
		"green",			sf::Color::Green,
		"blue",				sf::Color::Blue,
		"yellow",			sf::Color::Yellow,
		"magenta",			sf::Color::Magenta,
		"cyan",				sf::Color::Cyan,
		"transparent",		sf::Color::Transparent,

		nullptr,			sf::Color::Black
	};

	for (int i = 0; colours[i].name; i++)
	{
		if (strcmp(name, colours[i].name) == 0)
		{
			auto colour = new Colour();
			colour->_colour = colours[i].colour;
			return colour;
		}
	}

	return new Colour();
}

void Colour::register_class(lua_State *state)
{
	getGlobalNamespace(state).beginClass<Colour>("Colour")
		.addFunction("red", &Colour::red)
		.addFunction("green", &Colour::green)
		.addFunction("blue", &Colour::blue)
		.addFunction("alpha", &Colour::alpha)
		.addFunction("set_rgba", &Colour::set_rgba)
		.addFunction("set_rgb", &Colour::set_rgb)
		.addFunction("set_red", &Colour::set_red)
		.addFunction("set_green", &Colour::set_green)
		.addFunction("set_blue", &Colour::set_blue)
		.addFunction("set_alpha", &Colour::set_alpha)
		.addStaticFunction("from_rgba", from_rgba)
		.addStaticFunction("from_rgb", from_rgb)
		.addStaticFunction("from_name", from_name)
		.endClass();
}
