/* 
 * File:   Enemigo.hpp
 * Author: Jorge
 *
 * Created on 8 de marzo de 2015, 10:25
 */
#include <SFML/Graphics.hpp>
#include <iostream>

#include "FloatInter.hpp"

#ifndef ENEMIGO_HPP
#define	ENEMIGO_HPP

class Enemigo {
public:
    Enemigo(float x, float y);
    Enemigo(const Enemigo& orig);
    void update(float transcurrido);
    void render(sf::RenderWindow &window, float percenTick);   
    void buscar(float transcurrido);
    void colision();
    
    
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
    

    virtual ~Enemigo();
private:
    FloatInter *posInter;
    float velocidadMovimiendo;
    int vida;
    int ataque;
    float posicionX;
    float posicionY;
    int tipoEnemigo; //0=Goomba, 
    int respawn; //en segundos
    sf::Sprite *sprite;
    sf::Texture texEnemigo;
    bool buscando, atacando;
    float recorrido;
    int direccion; //0: izquierda, 1:izq-arriba, 2:arriba, 3:arriba-der, 4:derecha, 5:der-abajo, 6:abajo, 7:izq-abajo
};

#endif	/* ENEMIGO_HPP */

