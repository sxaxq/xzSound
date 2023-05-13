#include "SoundPad.h"

using namespace std;

namespace SoundPad
{
	map<string, sf::Sound*> smap;
	ostream& os = cout;
	istream& is = cin;

	void AddSound(string sound_name, sf::Sound* sound)
	{
		smap[sound_name] = sound;
		os << "Sound added" << endl;
		sf::sleep(sf::seconds(1.0f));
	}

	void SoundPlay(string sound_name)
	{
		cout << "Playing - " << sound_name << endl;
		smap[sound_name]->play();
		sf::sleep(sf::seconds(5.0f));
	}

	void DisplaySounds()
	{
		for (auto it = smap.begin(); it != smap.end(); ++it)
		{
			os << "Sound: " << it->first << endl;
		}
	}

	void DeleteSound(string sound_name)
	{
		smap.erase(sound_name);
		os << "Sound " << sound_name << " delete" << endl;
	}
}