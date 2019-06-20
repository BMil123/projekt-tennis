#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


class Ball : public sf::CircleShape {
public:
    Ball(float radius) : sf::CircleShape(radius) {radius_ = radius;}
    void set_v(float v_x, float v_y) {v_x_ = v_x; v_y_ = v_y;}
    float v_x() {return v_x_;}
    float v_y() {return v_y_;}
    void step(sf::RenderWindow window, float delta_t) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {


            float liczba = sf::Mouse::getPosition(window).x/sf::Mouse::getPosition(window).y;
            v_x_ = liczba* v_y_;

            if(sf::Mouse::getPosition(window).x<getPosition().x)
            {
                v_x_ = -v_x_;
            }
            if(sf::Mouse::getPosition(window).y<getPosition().y)
            {
                v_y_ = -v_y_;
            }
            move(v_x_*delta_t, v_y_*delta_t);



        }

    }
private:
    float radius_;
    float v_x_ = 120, v_y_ = 120;
};

class Player : public sf::Sprite {
public:
    Player(sf::Texture texture){sf::Sprite sprite;
                                sprite.setTexture(texture);}





private:
    float v_x = 300;
    float v_y = 300;


};



int main() {
   sf::RenderWindow window(sf::VideoMode(400, 800), "Tennis");
   int licznik=1;



   sf::RectangleShape rectangle1(sf::Vector2f(140.0, 200.0));
   rectangle1.setPosition(70.0, 400.0);
   rectangle1.setOutlineColor(sf::Color::White);
   rectangle1.setOutlineThickness(5);
   rectangle1.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle2(sf::Vector2f(140.0, 200.0));
   rectangle2.setPosition(200.0, 400.0);
   rectangle2.setOutlineColor(sf::Color::White);
   rectangle2.setOutlineThickness(5);
   rectangle2.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle3(sf::Vector2f(140.0, 200.0));
   rectangle3.setPosition(70.0, 200.0);
   rectangle3.setOutlineColor(sf::Color::White);
   rectangle3.setOutlineThickness(5);
   rectangle3.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle4(sf::Vector2f(140.0, 200.0));
   rectangle4.setPosition(200.0, 200.0);
   rectangle4.setOutlineColor(sf::Color::White);
   rectangle4.setOutlineThickness(5);
   rectangle4.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle5(sf::Vector2f(270.0, 160.0));
   rectangle5.setPosition(70.0, 35.0);
   rectangle5.setOutlineColor(sf::Color::White);
   rectangle5.setOutlineThickness(5);
   rectangle5.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle6(sf::Vector2f(270.0, 160.0));
   rectangle6.setPosition(70.0, 600.0);
   rectangle6.setOutlineColor(sf::Color::White);
   rectangle6.setOutlineThickness(5);
   rectangle6.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle7(sf::Vector2f(335.0, 10.0));
   rectangle7.setPosition(35.0, 395.0);
   rectangle7.setFillColor(sf::Color::Black);

   Ball ball(7.0);
   ball.setPosition(150.0, 500.0);
   ball.setFillColor(sf::Color(192, 215, 39));
   ball.setOutlineColor(sf::Color::Black);
   ball.setOutlineThickness(1);




   sf::Texture texture;
   texture.loadFromFile("player1.png");
   sf::Sprite sprite;
   sprite.setTexture(texture);
   sprite.setPosition(170.0, 700.0);


   sf::Texture texture2;
   texture2.loadFromFile("player2.png");
   sf::Sprite sprite2;
   sprite2.setTexture(texture2);
   sprite2.setPosition(10.0, 50.0);

   Player player1(texture);



   float v_x = 300;
   float v_y = 300;





   sf::Clock clock;


   while (window.isOpen()) {
       float delta = float(clock.getElapsedTime().asSeconds());
       clock.restart();


       sf::Event event;
       while (window.pollEvent(event)) {

           if (event.type == sf::Event::Closed)
               window.close();
       }




       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
       {
           licznik++;
       }


       if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
           float x = 120;
           float y = 120;
           float liczba = (abs(sf::Mouse::getPosition(window).x-ball.getPosition().x))/abs((sf::Mouse::getPosition(window).y-ball.getPosition().y));

           x = y*liczba;





           x = x*0.01*licznik;
           y = y*0.01*licznik;


           if(sf::Mouse::getPosition(window).x<ball.getPosition().x)
           {
               x = -x;
           }
           if(sf::Mouse::getPosition(window).y<ball.getPosition().y)
           {
               y = -y;
           }
           ball.move(x*delta, y*delta);





       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
       {
           sprite.move(-v_x*delta,0);
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
       {
           sprite.move(v_x*delta,0);
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
       {
           sf::FloatRect bounds = sprite.getGlobalBounds();
           if(bounds.top>330) {
          sprite.move(0, -v_y*delta);
           }
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
       {
          sprite.move(0, v_y*delta);

       }

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       {
           sprite2.move(-v_x*delta,0);
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       {
           sprite2.move(v_x*delta,0);
       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       {
          sprite2.move(0, -v_y*delta);

       }
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       {
           sf::FloatRect bounds2 = sprite2.getGlobalBounds();
           if(bounds2.top < 320)
           {
          sprite2.move(0, v_y*delta);
           }

       }




       window.clear(sf::Color::Green);



       window.draw(rectangle1);
        window.draw(rectangle2);
         window.draw(rectangle3);
          window.draw(rectangle4);
           window.draw(rectangle5);
            window.draw(rectangle6);
            window.draw(rectangle7);
            window.draw(ball);
            window.draw(sprite);
            window.draw(sprite2);




       window.display();
   }



   return 0;
}

