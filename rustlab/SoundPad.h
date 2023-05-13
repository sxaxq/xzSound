#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SFML/Audio.hpp>

namespace SoundPad
{
	extern std::map<std::string, sf::Sound*> smap;
	extern std::istream& is;
	extern std::ostream& os;

	void AddSound(std::string sound_name, sf::Sound* sound);
	void SoundPlay(std::string sound_name);
	void DisplaySounds();
	void DeleteSound(std::string sound_name);
}