/* 
 * File:   Jugador.cpp
 * Author: JORGE
 * 
 * Created on 11 de marzo de 2015, 12:08
 */

#include "Jugador.hpp"

Jugador::Jugador(float x, float y) {
    posInter = new FloatInter();
    posInter->setPos(x,y);
    posInter->setPos(x,y);
    if (!textura.loadFromFile("sprites/jugador.png")){
        std::cerr << "Error al cargar el sprite del personaje";
        exit(0);
    }
       
     sprite = new sf::Sprite(textura);      
    sprite->setOrigin(32/2,32/2);
    sprite->setPosition(posInter->getPos()->x, posInter->getPos()->y);
    sprite->setTextureRect(sf::IntRect(32*1, 32*0, 32, 32));
    
    leftTextura = 1;
    topTextura=0;
    piesQuietos=0;
    clock = new sf::Clock();
    clock->restart();    
}

Jugador::Jugador(const Jugador& orig) {
}

Jugador::~Jugador() {
}

void Jugador::update(float transcurrido, float arriba, float abajo, float izquierda, float derecha){
    sf::Vector2f *vector = posInter->getPos();
    float vel=0.06;
    int delayMovimiento = 150;
    
    
    
    if( !arriba &&  !abajo && !izquierda && !derecha){
        leftTextura = 1;
        sprite->setTextureRect(sf::IntRect(32*leftTextura, 32*topTextura, 32, 32));
    }else{     
        transcurridoGif += clock->getElapsedTime().asMilliseconds();        
          
        clock->restart();

        if(derecha==true && arriba == true){
            topTextura=3;           
            posInter->setPos(vector->x+(vel*transcurrido)*0.75, vector->y-(vel*transcurrido)*0.75);        
        }else if(izquierda==true && arriba == true){  
            topTextura=3;           
            posInter->setPos(vector->x+(-vel*transcurrido)*0.75, vector->y-(vel*transcurrido)*0.75); 
        }else if(derecha==true && abajo == true){  
            topTextura=0;            
            posInter->setPos(vector->x+(vel*transcurrido)*0.75, vector->y+(vel*transcurrido)*0.75); 
        }else if(izquierda==true && abajo == true){  
            topTextura=0;           
            posInter->setPos(vector->x+(-vel*transcurrido)*0.75, vector->y+(vel*transcurrido)*0.75); 
        }else if(derecha==true){  
            topTextura=2;       
            posInter->setPos(vector->x+(vel*transcurrido), vector->y); 
        }else if(izquierda == true){
            topTextura=1;
            posInter->setPos(vector->x+(-vel*transcurrido), vector->y); 
        }else if(arriba == true){
            topTextura=3;
            posInter->setPos(vector->x, vector->y+(-vel*transcurrido));
        }else if(abajo == true){
            topTextura=0;
            posInter->setPos(vector->x, vector->y+vel*transcurrido);
        }   
        if(transcurridoGif >= delayMovimiento){           
            if(piesQuietos == 0){
                leftTextura=2;
                piesQuietos =1;
            }else if(piesQuietos == 1){
                leftTextura =1;
                piesQuietos =2;
            }else if(piesQuietos == 2){
                leftTextura = 0;
                piesQuietos = 4;
            }else if(piesQuietos == 4){
                leftTextura = 1;
                piesQuietos =0;
            }            
            sprite->setTextureRect(sf::IntRect(32*leftTextura, 32*topTextura, 32, 32));
            transcurridoGif=0;
        }
    }
        
}

void Jugador::render(sf::RenderWindow &window, float tick){
    float ax= posInter->getLastPos()->x*(1-tick) + posInter->getPos()->x * tick;
    float ay=posInter->getLastPos()->y*(1-tick) + posInter->getPos()->y * tick ;
    sprite->setPosition(ax, ay);
    window.draw(*sprite);
}

void Jugador::LanzarBumeran(){
    
}


