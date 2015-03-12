
#include "Enemigo.hpp"



Enemigo::Enemigo( float x, float y) {
    posInter = new FloatInter();
    posInter->setPos(x,y);
    tipoEnemigo=0;
    vida=100;
    ataque=10;
    respawn=120;
    recorrido=0;
    direccion=-1;
    velocidadMovimiendo=5;
    if (!texEnemigo.loadFromFile("sprites/fantasma.png")){
        std::cerr << "Error al cargar el sprite del personaje";
        exit(0);
    } 

    sprite = new sf::Sprite(texEnemigo);
    sprite->setOrigin(32/2,32/2);
    sprite->setTextureRect(sf::IntRect(0, 0, 32, 32));
    buscando=true;
}

void Enemigo::update(float transcurrido){
    if(buscando == true){        
        buscar(transcurrido);
    }
}

void Enemigo::render(sf::RenderWindow &window, float tick){
    float lx= posInter->getLastPos()->x*(1-tick) + posInter->getPos()->x * tick;
    float ly=posInter->getLastPos()->y*(1-tick) + posInter->getPos()->y * tick ;
    sprite->setPosition(posInter->getLastPos()->x*(1-tick) + posInter->getPos()->x * tick, posInter->getLastPos()->y*(1-tick) + posInter->getPos()->y * tick );
    window.draw(*sprite);
}

void Enemigo::buscar(float transcurrido){
    if(recorrido <= 0){
           recorrido=(rand()%50) + 100;
           direccion = rand()%8;
       }
    sf::Vector2f *vector = posInter->getPos();
    switch(direccion){
        case 0:
            posInter->setPos(vector->x+(-0.01*velocidadMovimiendo*transcurrido), vector->y); 
            break;
        case 1:
            posInter->setPos(vector->x+(-0.01*velocidadMovimiendo/2*transcurrido), vector->y+(-0.01*velocidadMovimiendo/2*transcurrido));
            break;
        case 2:
            posInter->setPos(vector->x, vector->y+(-0.01*velocidadMovimiendo*transcurrido));
            break;
        case 3: 
            posInter->setPos(vector->x+(0.01*velocidadMovimiendo/2*transcurrido), vector->y+(-0.01*velocidadMovimiendo/2*transcurrido));
            break; 
        case 4: 
            posInter->setPos(vector->x+(0.01*velocidadMovimiendo*transcurrido), vector->y);
            break; 
        case 5: 
            posInter->setPos(vector->x+(0.01*velocidadMovimiendo/2*transcurrido), vector->y+(0.01*velocidadMovimiendo/2*transcurrido));
            break; 
        case 6: 
            posInter->setPos(vector->x, vector->y+(0.01*velocidadMovimiendo*transcurrido));
            break; 
        case 7: 
            posInter->setPos(vector->x+(-0.01*velocidadMovimiendo/2*transcurrido), vector->y+(0.01*velocidadMovimiendo/2*transcurrido));
            break;      
    }
       colision();

    recorrido -=(0.01*transcurrido);  
     
    
}

void Enemigo::colision(){
    if(posInter->getPos()->x > 500 - texEnemigo.getSize().x/2 || posInter->getPos()->x < 0){
        recorrido=0;
        direccion=-1;
    }else if(posInter->getPos()->y < 0  || posInter->getPos()->y > 500 - texEnemigo.getSize().y/2){
        recorrido =0;
        direccion=-1;
    }

  
    //CODIGO DE CLAUDIA DE LAS COLISIONES    
    
}


Enemigo::Enemigo(const Enemigo& orig) {
}


float Enemigo::getX(){
    return posicionX;
}

float Enemigo::getY(){
    return posicionY;
}

void Enemigo::setX(float x){
    posicionX = x;
}

void Enemigo::setY(float y ){
    posicionY = y;
}
Enemigo::~Enemigo() {
}

