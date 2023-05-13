#pragma once

#include <iostream>
#include <map>
#include <string>
#include <SFML/Audio.hpp>
#include <fstream>
#include <sstream>

namespace SoundPad
{
	extern std::map<std::string, sf::Sound*> smap;
	extern std::istream& is;
	extern std::ostream& os;

	void AddSound(std::string sound_name, sf::Sound* sound);
	void SoundPlay(std::string sound_name);
	void DisplaySounds();
	void DeleteSound(std::string sound_name);
	void LoadSound();
	void SaveSound(std::string sound_name, std::string sound_file);
}