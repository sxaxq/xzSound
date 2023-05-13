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
		sf::sleep(sf::seconds(5.0f));
	}

	void DeleteSound(string sound_name)
	{
		smap.erase(sound_name);
		os << "Sound " << sound_name << " delete" << endl;
	}

	void LoadSound()
	{
		fstream file("sounds.txt");
		
		if (file.is_open())
		{
			string line;
			while (getline(file, line))
			{
				stringstream lines(line);
				string word1, word2;
				lines >> word1 >> word2;

				sf::SoundBuffer* buffer = new sf::SoundBuffer;
				buffer->loadFromFile(word2);
				sf::Sound* sound = new sf::Sound;
				sound->setBuffer(*buffer);

				AddSound(word1, sound);
			}
		}
	}

	void SaveSound(std::string sound_name, std::string sound_file)
	{
		ofstream file("sounds.txt", std::ios::app);

		if (file.is_open())
		{
			file << sound_name + " " + sound_file << endl;
			file.close();
		}
	}
}