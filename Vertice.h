#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Vertice {
private:
    string nombre;
    Texture textura;
    Sprite sprite;

public:
    Vertice(){}

    Vertice(string _nombre, string _imag) {
        nombre = _nombre;
        textura.loadFromFile(_imag);

        sprite.setTexture(textura);
        sprite.setScale(1100.f / sprite.getTexture()->getSize().x, 920.f / sprite.getTexture()->getSize().y);
    }

    string getNombre()
    {
        return nombre;
    }

    Sprite getSprite() {
        return sprite;
    }
};

