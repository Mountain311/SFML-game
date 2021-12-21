#include "Classes.h"

int main(){

	sf::RenderWindow window(sf::VideoMode(1224, 882), "THE SHOOTING RANGE", sf::Style::Close | sf::Style::Titlebar | sf::Style::Default);
	window.setMouseCursorVisible(false);

	soundeffects effects;

	sf::RectangleShape cursor(sf::Vector2f(30.0f, 30.0f));
	cursor.setOrigin(15.0f, 15.0f);
	sf::Texture aim;
	aim.loadFromFile("aim.png");
	cursor.setTexture(&aim);

	beginnig:

	bool hit = false;
	bool play = false;
	bool gameover = false;

	float difficulty = 2;

	int count = 0;

	int score = 0;

	backgrd b1;

	Targets t1;

	Texts alltext;

	std::vector<sf::RectangleShape> Target;

	Target.clear();

	sf::Clock timer;
	sf::Time elapsed;
	elapsed = timer.getElapsedTime();

	timer.restart();

	effects.playbgmusic();

	while (window.isOpen())
	{

		hit = false;

		window.clear();

		if (play == false) {
			
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1)) {
			
				difficulty = 2.0;
				play = true;
			
			}
			
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2)) {

				difficulty = 1.5;
				play = true;

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3)) {

				difficulty = 1.0;
				play = true;

			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4)) {

				difficulty = 0.5;
				play = true;

			}
		
		}

		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
				break;

			}

		}
		if (play == true && gameover==false) {

			std::string scoredisp = "Score : ";
			scoredisp += std::to_string(score);
			scoredisp += "\nTargets Hit : ";
			scoredisp += std::to_string(count);

			alltext.setscore(scoredisp);

			elapsed = timer.getElapsedTime();


			if (elapsed.asSeconds() >= difficulty) {

				Target.clear();

				t1.SetLocation();

				Target.push_back(t1.player);

				timer.restart();
			}

			cursor.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));

			if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && Target.size() >= 1) {

				effects.playsoundeff();

				sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
				auto target_pos1 = Target[0].getGlobalBounds();

				sf::FloatRect target_pos2;

				if (Target.size() >= 2) {

					sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
					target_pos2 = Target[1].getGlobalBounds();

				}

				sf::Vector2i mousePos = sf::Mouse::getPosition(window);

				if (target_pos1.contains((float)mouse_pos.x, (float)mouse_pos.y)) {

					hit = true;

					count++;

					score += (100*(4-difficulty));

					if (Target.size() >= 1 && hit == true) {

						Target.clear();

					}

					if (count % 10 == 0) {

						difficulty = difficulty * 0.75;

					}

				}

				else if (hit == false) {

					effects.playsoundeff();

					Target.clear();

					gameover = true;
					
				}

			}

		}

		if (gameover == true) {

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {

				goto beginnig;
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {

				window.close();

			}

		}	

		window.clear();

		window.draw(b1.getbackground());
		window.draw(alltext.getscoretext());

		if (play == false) {

			window.draw(alltext.getmenutext());

		}

		if (gameover == true) {

			window.draw(alltext.getovertext());

		}

		if (Target.size() >= 1) {

			window.draw(Target[0]);

		}

		window.draw(cursor);
		window.display();

	}

	return 0;
}