#include "libkakhovkaflave.h"
#include <SFML/Audio.hpp>
#include <conio.h>
#include <Windows.h>
#include "SoundPad.h"

void setTextColor(string text, int color);
void UserHandleInput();
void PrintMenu();

int main()
{
	SetConsoleTitle(L"Bebra Sound");

	setTextColor("[Start]: ", FOREGROUND_GREEN);
	cout << "Loading sound..." << endl;
	SoundPad::LoadSound();

	while (true)
	{
		PrintMenu();
		UserHandleInput();
	}
}

void UserHandleInput()
{
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
		sound->setLoop(false);
		sound->setVolume(100.f);
		sound->setPlayingOffset(sf::milliseconds(0));
		sound->setPitch(1.f);
		sound->setRelativeToListener(false);
		sound->setMinDistance(0.5f);
		sound->setAttenuation(0.f);


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
	case 5:
		SoundPad::keyPadMode = true;
		cout << "KeyPad Mode ON" << endl;
		break;
	default:
		cout << "Unkown operation" << endl;
		break;
	}

	while (SoundPad::keyPadMode)
	{
		char ch = _getch();

		switch (ch)
		{
		case '1':
			SoundPad::SoundPlay(SoundPad::idmap[1]);
			break;
		case '2':
			SoundPad::SoundPlay(SoundPad::idmap[2]);
			break;
		case '3':
			SoundPad::SoundPlay(SoundPad::idmap[3]);
			break;
		case '4':
			SoundPad::SoundPlay(SoundPad::idmap[4]);
			break;
		case '5':
			SoundPad::SoundPlay(SoundPad::idmap[5]);
			break;
		case '6':
			SoundPad::SoundPlay(SoundPad::idmap[6]);
			break;
		case 'q':
			cout << "KeyPad Mode OFF" << endl;
			SoundPad::keyPadMode = false;
			break;
		}
		sf::sleep(sf::seconds(1.0f));
	}
	system("cls");
}

void PrintMenu()
{
	setTextColor("[Bebra Sound]\n", FOREGROUND_RED);
	cout << "1 - Add sound" << endl;
	cout << "2 - Play sound" << endl;
	cout << "3 - Delete sound" << endl;
	cout << "4 - Display sounds" << endl;
	cout << "5 - On KeyPad Mode" << endl;
}

void setTextColor(string text, int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	WORD savedAttributes;

	GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
	savedAttributes = consoleInfo.wAttributes;
	
	SetConsoleTextAttribute(hConsole, color);
	cout << text;
	SetConsoleTextAttribute(hConsole, savedAttributes);
}
