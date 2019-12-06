#include <SFML/Graphics.hpp>

class O_Player_Piece : public sf::circleShape
{
    public:
        O_playerPiece(float radius, const sf::color &c, sf::Vector2f &pos) : sf::circleShape(radius)
        {
            this->setFillColor(c);
            this->setPosition(pos);
        }
};

class X_Player_Piece : public sf::rectangleShape
{
    public:
    X_Player_Piece(const sf::color &c, sf::Vector2f &size, sf::Vector2f &pos) : sf::rectangleShape(size)
    {
        this->setFillColor(c);
        this->setPosition(pos);
    }
};

class Player
{
    protected:
    bool isOccuoiedSquare1;
    bool isOccuoiedSquare2;
    bool isOccuoiedSquare3;
    bool isOccuoiedSquare4;
    bool isOccuoiedSquare5;
    bool isOccuoiedSquare6;
    bool isOccuoiedSquare7;
    bool isOccuoiedSquare8;
    bool isOccuoiedSquare9;

    Player()
    {
    isOccuoiedSquare1 = false;
    isOccuoiedSquare2 = false;
    isOccuoiedSquare3 = false;
    isOccuoiedSquare4 = false;
    isOccuoiedSquare5 = false;
    isOccuoiedSquare6 = false;
    isOccuoiedSquare7 = false;
    isOccuoiedSquare8 = false;
    isOccuoiedSquare9 = false;
    }
};

int main()
{
    //double row1 = ;
    //double row2 = ;
    //double row3 = ;
    //double column1 = ;
    //double column2 = ;
    //double coulumn3 = ;
    
    sf::RenderWindow window(sf::videoMode(1000,1000), "Tic Tac Toe!")
    
    O_Player_Piece O1(100.f, sf::Color::Blue, sf::Vector2f(100,100));
    X_Player_Piece X1(sf::Color::Red, sf::Vector2f(100,100), sf::Vector(800, 800));
    
    window.draw(O1);
    window.draw(X1);  
    
    return 0;
    
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Player.h

#include <SFML/Graphics.hpp>
#include<iostream>

class Player : public sf::RectangleShape
{
public:
	Player(sf::Vector2f &size, const sf::Color &myColor, sf::Vector2f &pos);
};
	

//Player.cpp

#include"Player.h"

Player::Player(sf::Vector2f &size, const sf::Color &myColor, sf::Vector2f &pos) : sf::RectangleShape(size)
{
	
	this->setFillColor(myColor);
	this->setPosition(pos);
}


//MAIN.cpp

#include"Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1800, 1800), "TAG!!!!! THE GOAL: Is for the Green cube to touch the Blue cube");

	Player player1(*(new sf::Vector2f(window.getSize().x / 50, window.getSize().y / 50)), sf::Color::Green, *(new sf::Vector2f(0, window.getSize().y / 2)));

	Player player2(*(new sf::Vector2f(window.getSize().x / 50, window.getSize().y / 50)), sf::Color::Blue, *(new sf::Vector2f(1762, window.getSize().y / 2)));

	while (window.isOpen())
	{
		sf::Event event;

		window.clear();

		window.draw(player1);
		window.draw(player2);

		window.display();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Player 1
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			player1.move(0, -1);

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			player1.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			player1.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			player1.move(0, 1);
		}

		//Player 2
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			player2.move(0, -1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			player2.move(-1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			player2.move(1, 0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			player2.move(0, 1);
		}

		if (player1.getGlobalBounds().intersects(player2.getGlobalBounds()))
		{

			player1.setPosition(0, window.getSize().y / 2);
			player2.setPosition(1762, window.getSize().y / 2);
		}

	}
	return 0;
}

