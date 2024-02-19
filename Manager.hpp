#pragma once

#include "Header.hpp"
//#include "Stock.hpp"

class Manager
{
public:
	Manager();

	static sf::Texture& GetTexture(std::string const& filename);
	static sf::SoundBuffer& GetSoundBuffer(std::string const& filename);
	static sf::Font& GetFont(std::string const& filename);

private:
	std::map <std::string, sf::Texture> mapTexture;
	std::map <std::string, sf::SoundBuffer> mapSoundBuffer;
	std::map <std::string, sf::Font> mapFont;

	static Manager* staticInstance;
};

