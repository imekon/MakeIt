#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	bool load_texture(const char *filename);

	static TextureManager *getInstance();
	static void shutdown();

private:
	static TextureManager *instance;

	std::vector<sf::Texture *> textures;
};