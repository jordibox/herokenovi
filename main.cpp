#include <SFML/Graphics.hpp>
#include <iostream>


#include "Enemigo.hpp"
#include "Jugador.hpp"

#define UPDATE_TICK_TIME 1/15

using namespace std;

int main()
{
    srand (time(NULL));
    bool derecha=false, izquierda=false, arriba=false, abajo=false;
    sf::Clock updateClock;
    sf::Time timeElapsed;
    
    
    sf::RenderWindow window(sf::VideoMode(500, 500), "Herokenovi");   
    window.setFramerateLimit(60);
    
    Jugador *jugador = new Jugador(200,200);
      
    Enemigo *goomba = new Enemigo(400,400);
    Enemigo *goomba2 = new Enemigo(400,400);
    Enemigo *goomba3 = new Enemigo(400,400);
    Enemigo *goomba4 = new Enemigo(400,400);
    Enemigo *goomba5 = new Enemigo(400,400);
    Enemigo *goomba6 = new Enemigo(400,400);
    Enemigo *goomba7 = new Enemigo(400,400);
    Enemigo *goomba8 = new Enemigo(400,400); 
    
    while (window.isOpen()){          
        
        if(updateClock.getElapsedTime().asSeconds() > UPDATE_TICK_TIME){
                    sf::Event event;
            while (window.pollEvent(event))
            {
                  switch(event.type){
                    case sf::Event::Closed:
                        window.close();
                        break;
                }        
                derecha = sf::Keyboard::isKeyPressed(sf::Keyboard::D);                      
                izquierda = sf::Keyboard::isKeyPressed(sf::Keyboard::A);   
                arriba = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
                abajo = sf::Keyboard::isKeyPressed(sf::Keyboard::S); 
            } 
            timeElapsed = updateClock.restart();
            goomba->update(timeElapsed.asMilliseconds());
            goomba2->update(timeElapsed.asMilliseconds());
            goomba3->update(timeElapsed.asMilliseconds());
            goomba4->update(timeElapsed.asMilliseconds());
            goomba5->update(timeElapsed.asMilliseconds());
            goomba6->update(timeElapsed.asMilliseconds());
            goomba7->update(timeElapsed.asMilliseconds());
            goomba8->update(timeElapsed.asMilliseconds());
            jugador->update(timeElapsed.asMilliseconds(), arriba, abajo, izquierda, derecha);            
        }
        
        window.clear(); 
        float percentTick = std::min(1.f, (float)(updateClock.getElapsedTime().asSeconds()/UPDATE_TICK_TIME));

        goomba->render(window, percentTick);
        goomba2->render(window, percentTick);
        goomba3->render(window, percentTick);
        goomba4->render(window, percentTick);
        goomba5->render(window, percentTick);
        goomba6->render(window, percentTick);
        goomba7->render(window, percentTick);
        goomba8->render(window, percentTick);
        jugador->render(window, percentTick);

        window.display();
    }
    
return 0;
}
