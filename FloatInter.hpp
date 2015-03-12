/* 
 * File:   floatInter.hpp
 * Author: JORGE
 *
 * Created on 10 de marzo de 2015, 13:23
 */
#include <SFML/Graphics.hpp>
#include <iostream>

#ifndef FLOATINTER_HPP
#define	FLOATINTER_HPP

class FloatInter {
public:
    FloatInter();
    FloatInter(const FloatInter& orig);
    
    void setPos(float tx, float ty);
    sf::Vector2f* getLastPos();
    sf::Vector2f* getPos();
    
    virtual ~FloatInter();
private:
    float x;
    float y;
    float lastX;
    float lastY;

};

#endif	/* FLOATINTER_HPP */

