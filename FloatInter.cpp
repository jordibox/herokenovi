/* 
 * File:   floatInter.cpp
 * Author: JORGE
 * 
 * Created on 10 de marzo de 2015, 13:23
 */

#include "FloatInter.hpp"

FloatInter::FloatInter() {
    lastX = 0;
    lastY = 0;
    x=0;
    y=0;
}

FloatInter::FloatInter(const FloatInter& orig) {
}

FloatInter::~FloatInter() {
}


void FloatInter::setPos(float tx, float ty){
    lastX = x;
    lastY = y;
    x = tx;
    y = ty;
}

sf::Vector2f* FloatInter::getLastPos(){
    sf::Vector2f *vector = new sf::Vector2f(lastX,lastY);
    return vector;

}

sf::Vector2f* FloatInter::getPos(){
    sf::Vector2f *vector = new sf::Vector2f(x,y);
    return vector;

}

