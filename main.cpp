#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball : public sf::CircleShape {
public:
    Ball(float radius) : sf::CircleShape(radius) {radius_ = radius;}

    void punkty (sf::Sprite s1, sf::Sprite s2)
    {
        int p_c=0, p_f=0;
        int g_c=0, g_f=0;
        int s_c=0, s_f=0;

        if(kolej(s1,s2)==false)
        {

            if (klik()%2==1)
            {
                std::cout << "Czerwony" << std::endl;

                if((getPosition().x>70.0 && getPosition().x<340)&&(getPosition().y>35 && getPosition().y<395))
                {
                   p_c+=15;

                   std::cout << "Czerwony:Fioletowy" << std::endl;
               std::cout << "Punkty: " << p_c << ":" << p_f << std::endl;
               std::cout << "Gemy: " << g_c << ":" << g_f << std::endl;
               std::cout << "Sety: " << s_c << ":" << s_f << std::endl;

               float schowek = s1.getPosition().x;
               s1.setPosition(s2.getPosition().x, s1.getPosition().y);
               s2.setPosition(schowek, s2.getPosition().y);



                   if(p_c>45 && p_c-p_f>=30)
                   {
                       g_c++;
                       p_c=0;
                       p_f=0;

                   }
                   if(g_c>=6 && g_c-g_f>=2)
                   {
                       s_c++;
                       g_c=0;
                       g_f=0;
                   }
                   if(s_c==3)
                   {
                       std::cout << "Wygrał czerwony!" << std::endl;

                   }
                }
                   else{
                       p_f+=15;
                       std::cout << "Czerwony:Fioletowy" << std::endl;
                   std::cout << "Punkty: " << p_c << ":" << p_f << std::endl;
                   std::cout << "Gemy: " << g_c << ":" << g_f << std::endl;
                   std::cout << "Sety: " << s_c << ":" << s_f << std::endl;
                   float schowek = s1.getPosition().x;
                   s1.setPosition(s2.getPosition().x, s1.getPosition().y);
                   s2.setPosition(schowek, s2.getPosition().y);
                   }
            }


                if (klik()%2==0)
                {
                    std::cout << "Fioletowy" << std::endl;

                    if((getPosition().x>70.0 && getPosition().x<340)&&(getPosition().y>395 && getPosition().y<765))
                    {
                       p_f+=15;
                       std::cout << "Czerwony:Fioletowy" << std::endl;
                   std::cout << "Punkty: " << p_c << ":" << p_f << std::endl;
                   std::cout << "Gemy: " << g_c << ":" << g_f << std::endl;
                   std::cout << "Sety: " << s_c << ":" << s_f << std::endl;
                   float schowek = s1.getPosition().x;
                   s1.setPosition(s2.getPosition().x, s1.getPosition().y);
                   s2.setPosition(schowek, s2.getPosition().y);
                       if(p_f>45 && p_f-p_c>=30)
                       {
                           g_f++;
                           p_c=0;
                           p_f=0;
                       }
                       if(g_f>=6 && g_f-g_c>=2)
                       {
                           s_f++;
                           g_c=0;
                           g_f=0;
                       }
                       if(s_f==3)
                       {
                           std::cout << "Wygrał fioletowy!" << std::endl;

                       }
                    }
                       else
                    {
                         p_c+=15;
                         std::cout << "Czerwony:Fioletowy" << std::endl;
                     std::cout << "Punkty: " << p_c << ":" << p_f << std::endl;
                     std::cout << "Gemy: " << g_c << ":" << g_f << std::endl;
                     std::cout << "Sety: " << s_c << ":" << s_f << std::endl;
                     float schowek = s1.getPosition().x;
                     s1.setPosition(s2.getPosition().x, s1.getPosition().y);
                     s2.setPosition(schowek, s2.getPosition().y);
                    }

                }

        }


    }

    bool kolej(sf::Sprite sprite, sf::Sprite sprite2)
    {
        sf::FloatRect bounds = sprite.getGlobalBounds();
        sf::FloatRect bounds2 = sprite2.getGlobalBounds();
        sf::FloatRect bounds3 = getGlobalBounds();
        if(bounds.intersects(bounds3)==true)
        {
            setPosition(sprite.getPosition().x-20, sprite.getPosition().y-10);

            return true;

        }
        if(bounds2.intersects(bounds3)==true)
        {
            setPosition(sprite2.getPosition().x+bounds2.width+10, sprite2.getPosition().y+bounds2.height);

            return true;
        }
        else {
            return false;
        }
    }


   int klik()
   {
       return klik_;
   }

    void step(sf::RenderWindow &window, float delta_t, int licznik) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            float v_x = 120;
            float v_y = 120;
            float liczba = (abs(sf::Mouse::getPosition(window).x-getPosition().x))/abs((sf::Mouse::getPosition(window).y-getPosition().y));

            v_x = v_y*liczba;

            v_x = v_x*0.02*licznik;
            v_y = v_y*0.02*licznik;


            if(sf::Mouse::getPosition(window).x<getPosition().x)
            {
                v_x = -v_x;
            }
            if(sf::Mouse::getPosition(window).y<getPosition().y)
            {
                v_y = -v_y;
            }
            move(v_x*delta_t, v_y*delta_t);



        }

    }

private:
    float radius_;
    int klik_ = 0;

};


float czas(Ball ball, sf::Sprite s1, sf::Sprite s2)
{
    sf::Clock clock;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        float delta = float(clock.getElapsedTime().asSeconds());
        if(ball.kolej(s1, s2)==true)
        {
        return delta;
        }
    }
}


int main() {
   sf::RenderWindow window(sf::VideoMode(400, 800), "Tennis");
   int licznik=1;


   std::cout << "Czerwony:Fioletowy" << std::endl;
std::cout << "Punkty: " << "0:0" << std::endl;
std::cout << "Gemy: " << "0:0" << std::endl;
std::cout << "Sety: " << "0:0" << std::endl;



   sf::RectangleShape rectangle1(sf::Vector2f(140.0, 200.0)); //3 od góry z lewej
   rectangle1.setPosition(70.0, 400.0);
   rectangle1.setOutlineColor(sf::Color::White);
   rectangle1.setOutlineThickness(5);
   rectangle1.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle2(sf::Vector2f(140.0, 200.0)); //3 od góry z prawej
   rectangle2.setPosition(200.0, 400.0);
   rectangle2.setOutlineColor(sf::Color::White);
   rectangle2.setOutlineThickness(5);
   rectangle2.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle3(sf::Vector2f(140.0, 200.0)); // 2 od góry z lewej
   rectangle3.setPosition(70.0, 200.0);
   rectangle3.setOutlineColor(sf::Color::White);
   rectangle3.setOutlineThickness(5);
   rectangle3.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle4(sf::Vector2f(140.0, 200.0)); // 2 od góRy z prawej
   rectangle4.setPosition(200.0, 200.0);
   rectangle4.setOutlineColor(sf::Color::White);
   rectangle4.setOutlineThickness(5);
   rectangle4.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle5(sf::Vector2f(270.0, 160.0)); // 1 od góry
   rectangle5.setPosition(70.0, 35.0);
   rectangle5.setOutlineColor(sf::Color::White);
   rectangle5.setOutlineThickness(5);
   rectangle5.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle6(sf::Vector2f(270.0, 160.0)); // 4 od góry
   rectangle6.setPosition(70.0, 600.0);
   rectangle6.setOutlineColor(sf::Color::White);
   rectangle6.setOutlineThickness(5);
   rectangle6.setFillColor(sf::Color(0, 180, 247));
   sf::RectangleShape rectangle7(sf::Vector2f(335.0, 10.0)); // siatka
   rectangle7.setPosition(35.0, 395.0);
   rectangle7.setFillColor(sf::Color::Black);

   Ball ball(7.0);
   ball.setPosition(220.0, 760.0);
   ball.setFillColor(sf::Color(192, 215, 39));
   ball.setOutlineColor(sf::Color::Black);
   ball.setOutlineThickness(1);


   sf::Texture texture;
   texture.loadFromFile("player1cz.png");
   sf::Sprite sprite;
   sprite.setTexture(texture);
   sprite.setPosition(250.0, 750.0);


   sf::Texture texture2;
   texture2.loadFromFile("player2fi.png");
   sf::Sprite sprite2;
   sprite2.setTexture(texture2);
   sprite2.setPosition(100.0, 50.0);

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


       if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
       {
           licznik++;


       }

       if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
       {
           licznik--;

       }

       ball.step(window, delta, licznik);


       ball.punkty(sprite, sprite2);


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
           if(bounds.top>400) {
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
           if(bounds2.top < 350)
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



