// SFML_first.cpp : Defines the entry point for the console application.

#include "stdafx.h" // dla visuala
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "Paint App", sf::Style::Close | sf::Style::Titlebar);

	//rectangle
	sf::RectangleShape kwadrat(sf::Vector2f(40.0f, 40.0f));
	kwadrat.setPosition(100.0f, 100.0f);
	kwadrat.setOrigin(20.0f, 20.0f);

	sf::CircleShape kolo(10.0f);
	kolo.setFillColor(sf::Color(100, 250, 50));
	kolo.setOrigin(5.0f, 5.0f);

	/*sf::Texture texture;
	if (!texture.loadFromFile("trawa.jpg"));
	sf::Sprite sprite;
	sprite.setTexture(texture);
	sprite.setColor(sf::Color(255, 255, 255, 128));*/

	int color = 0;


	while (window.isOpen())
	{

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				std::cout << "\n\nOkno zamkniete poprawnie!\n\n";
				window.close();
				break;
				/*case sf::Event::Resized:
				std::cout << "Wysokosc: " << ev.size.height << " Szerokosc: " << ev.size.width << std::endl;
				break;*/
			case sf::Event::TextEntered:
				if (ev.text.unicode < 128)
				{
					std::cout << "Wcisniety klawisz: " << ev.text.unicode << std::endl;
				}
			} //switch


		} //event while0

		  // POZYCJA Z KLAWIATURY

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			kwadrat.move(-0.1f, 0.0f);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			kwadrat.move(0.0f, -0.1f);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			kwadrat.move(0.0f, 0.1f);


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			kwadrat.move(0.1f, 0.0f);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C))
			window.clear();

		// POZYCJA Z MYSZKI
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			std::cout << "\nLewy";
			//kwadrat.setFillColor(sf::Color::Red);
			sf::Vector2i mousePos = sf::Mouse::getPosition(window);
			kwadrat.setPosition(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{

			std::cout << color << " Prawy\n";
			window.clear();
			/*
			color++;
			if (color > 100)
				kwadrat.setFillColor(sf::Color::Yellow);
			else if (color > 200)
				kwadrat.setFillColor(sf::Color::Green);
			else if (color > 300)
				kwadrat.setFillColor(sf::Color::Red);
			else if (color > 400)
				kwadrat.setFillColor(sf::Color::Blue);
			else if (color > 500)
				kwadrat.setFillColor(sf::Color::Cyan);

			switch (color)
			{
			case 0:
				kwadrat.setFillColor(sf::Color::White);
				break;
			}
			*/

		}

		//		window.clear();
		//    	window.draw(kolo);
		//      window.draw(sprite);
		window.draw(kwadrat);
		window.display();

	} // game while

	return 0;
}
