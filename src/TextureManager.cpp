#include "TextureManager.h"

using namespace std;
using namespace sf;

TextureManager *TextureManager::instance = nullptr;

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	for (auto texture : textures)
	{
		delete texture;
	}
}

bool TextureManager::load_texture(const char * filename)
{
	sf::Texture *texture = new sf::Texture();
	if (!texture->loadFromFile(filename))
	{
		delete texture;
		return false;
	}

	textures.push_back(texture);

	return true;
}

TextureManager * TextureManager::getInstance()
{
	if (instance == nullptr)
		instance = new TextureManager();

	return instance;
}

void TextureManager::shutdown()
{
	if (instance)
		delete instance;

	instance = nullptr;
}