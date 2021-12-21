#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>

class backgrd {

private:

	sf::Texture range;
	sf::RectangleShape background;

public:

	backgrd() {

		range.loadFromFile("range.png");
		background.setSize(sf::Vector2f(1224.0f, 882.0f));
		background.setTexture(&range);
		background.setOrigin(612.0f, 441.0f);
		background.setPosition(612.0f, 441.0f);

	}

	sf::RectangleShape getbackground() {

		return background;
	}

};

class soundeffects {

private:

	sf::SoundBuffer shot;
	sf::Sound fire;
	sf::Music backgroundmusic;

public:

	soundeffects() {

		shot.loadFromFile("shot.wav");
		fire.setBuffer(shot);
		backgroundmusic.openFromFile("background.wav");
	}

	void playsoundeff() {

		fire.play();

	}

	void playbgmusic() {

		backgroundmusic.play();

	}

};

class Targets {

public:

	sf::RectangleShape player;
	sf::Texture target;
	

	Targets() {

		player.setSize(sf::Vector2f(100.0f, 100.0f));
		target.loadFromFile("target.png");
		player.setTexture(&target);
		player.setOrigin(50.0f, 50.0f);

	}

	void SetLocation() {

		srand((unsigned)time(0));
	
		float LocationX = 0.0;

		float LocationY = 0.0;

		LocationX = ((rand() % 15)*65) + 49;
		LocationY = ((rand() % 13)*52) + 50;

		player.setPosition(LocationX,LocationY);

	}

};

class Texts {

private:

	sf::Font startfont;
	sf::Text Select;
	sf::Text ScoreText;
	sf::Text overText;

public:

	Texts() {

		startfont.loadFromFile("Pixellettersfull-BnJ5.ttf");

		Select.setFont(startfont);
		Select.setStyle(sf::Text::Style::Bold);
		Select.setFillColor(sf::Color::White);
		Select.setOutlineColor(sf::Color::Black);
		Select.setOutlineThickness(5);
		Select.setString("Press 1 for Easy \nPress 2 for Medium \nPress 3 for Hard \nPress 4 for Ultra Hard ");
		Select.setCharacterSize(125);
		Select.setPosition(150.0f, 175.0f);

		ScoreText.setFont(startfont);
		ScoreText.setStyle(sf::Text::Style::Bold);
		ScoreText.setFillColor(sf::Color::White);
		ScoreText.setOutlineColor(sf::Color::Black);
		ScoreText.setOutlineThickness(5);
		ScoreText.setCharacterSize(50);

		overText.setFont(startfont);
		overText.setStyle(sf::Text::Style::Bold);
		overText.setString("GAME OVER!!! \nPress Space To PLAY AGAIN \nPress Escape to EXIT ");
		overText.setCharacterSize(100);
		overText.setPosition(150.0f, 250.0f);
		overText.setOutlineColor(sf::Color::Black);
		overText.setOutlineThickness(5);

	}

	void setscore(std::string x) {

		ScoreText.setString(x);

	}

	sf::Text getmenutext() {

		return Select;

	}

	sf::Text getscoretext() {

		return ScoreText;

	}

	sf::Text getovertext() {

		return overText;

	}

};