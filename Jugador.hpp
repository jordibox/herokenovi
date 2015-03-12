/* 
 * File:   Jugador.hpp
 * Author: JORGE
 *
 * Created on 11 de marzo de 2015, 12:08
 */
#include <SFML/Graphics.hpp>
#include <iostream>

#include "FloatInter.hpp"

#ifndef JUGADOR_HPP
#define	JUGADOR_HPP

class Jugador {
public:
    Jugador(float x, float y);
    Jugador(const Jugador& orig);
    void update(float transcurrido, float arriba, float abajo, float izqueirda, float derecha);
    void render(sf::RenderWindow &window, float percenTick);
    void lanzarBumeran();
    virtual ~Jugador();
    
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
private:
    
    FloatInter *posInter;
    sf::Sprite *sprite;
    sf::Texture textura;     
    int leftTextura, topTextura;  
    int piesQuietos;
    sf::Clock *clock;
    float transcurridoGif;
    
};

#endif	/* JUGADOR_HPP */

