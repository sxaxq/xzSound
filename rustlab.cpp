#include "libkakhovkaflave.h"
#include <SFML/Audio.hpp>
#include <Windows.h>
#include "SoundPad.h"

int main()
{
	SetConsoleTitle(L"Bebra Sound");

	SoundPad::LoadSound();

	while (true)
	{
		cout << "1 - Add sound" << endl;
		cout << "2 - Play sound" << endl;
		cout << "3 - Delete sound" << endl;
		cout << "4 - Display sounds" << endl;
		cout << "> ";
		int userInput;
		cin >> userInput;

		switch (userInput)
		{
		case 1:
		{
			cout << "Enter name sound and file sound: ";
			string sound_name, sound_file;
			cin >> sound_name >> sound_file;

			sf::SoundBuffer* buffer = new sf::SoundBuffer;
			buffer->loadFromFile(sound_file);
			sf::Sound* sound = new sf::Sound;
			sound->setBuffer(*buffer);
			SoundPad::SaveSound(sound_name, sound_file);
			SoundPad::AddSound(sound_name, sound);
		}
		    break;
		case 2:
		{
			cout << "Enter sound name: ";
			string sound_name;
			cin >> sound_name;

			SoundPad::SoundPlay(sound_name);
		}
			break;
		case 3:
		{
			cout << "Enter sound name: ";
			string sound_name;
			cin >> sound_name;

			SoundPad::DeleteSound(sound_name);
		}
			break;
		case 4:
			SoundPad::DisplaySounds();
			break;
		}

		system("cls");
	}
}
