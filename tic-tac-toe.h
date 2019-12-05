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
