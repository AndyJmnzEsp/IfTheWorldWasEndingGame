#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vertice.h"
#include "Grafo.h"
using namespace std;
using namespace sf;

class InputManager {
public: 
	InputManager() {}

    void Run() {
        bool backInTime = false, inicio = false;
        char resp;
        string res;

        RenderWindow window(VideoMode(1100, 920), "If the world was ending");

        window.setVerticalSyncEnabled(true);

        window.setKeyRepeatEnabled(true);

        Texture textura;
        textura.loadFromFile("img/A.png");

        Sprite sprite;
        sprite.setTexture(textura);
        sprite.setScale(1000.f / sprite.getTexture()->getSize().x, 920.F / sprite.getTexture()->getSize().y);

        int ver = 0, posicionTemp = 0;
        short adyacents = 0;
        short aristas[2];
        Vertice* Vertices[11];

        Vertices[0] = new Vertice("A", "img/A.png");
        Vertices[1] = new Vertice("B", "img/B.png");
        Vertices[2] = new Vertice("C", "img/C.png");
        Vertices[3] = new Vertice("D", "img/D.png");
        Vertices[4] = new Vertice("E", "img/E.png");
        Vertices[5] = new Vertice("F", "img/F.png");
        Vertices[6] = new Vertice("G", "img/G.png");
        Vertices[7] = new Vertice("H", "img/H.png");
        Vertices[8] = new Vertice("I", "img/I.png");
        Vertices[9] = new Vertice("J", "img/J.png");
        Vertices[10] = new Vertice("K", "img/K.png");

        Grafo grafo = Grafo();
        

        cout << "********************************" << endl;
        cout << "IF THE WORLD WAS ENDING \n\n\n";
        grafo.CrearArista(0, 1);
        grafo.CrearArista(1, 2);
        grafo.CrearArista(1, 3);
        grafo.CrearArista(2, 4);
        grafo.CrearArista(2, 8);
        grafo.CrearArista(3, 5);
        grafo.CrearArista(3, 7);
        grafo.CrearArista(4, 6);
        grafo.CrearArista(5, 7);
        grafo.CrearArista(6, 10);
        grafo.CrearArista(7, 10);
        grafo.CrearArista(8, 9);
        grafo.CrearArista(9, 10);
        


        while (window.isOpen()) {
            if (grafo.End(ver)) {

                window.clear();
                window.draw(Vertices[ver]->getSprite());
                window.display();
                cout << "Que deseas hacer?\n";
                cin >> resp;

                if (grafo.NumCaminos(ver) == 1) {
                    ver = grafo.ObtenerAdyacente(ver, 1);
                }
                else {
                    for (int i = 0; i < grafo.NumCaminos(ver); i++) {
                        if (Vertices[grafo.ObtenerAdyacente(ver, i+1)]->getNombre() == resp) {
                            ver = grafo.ObtenerAdyacente(ver, i+1);
                        }
                    }
                }
            }
            else {
                cout << "Deseas reiniciar el juego?\n";
                cin >> res;
                if (res == "si" || res == "Si" || res == "SI" || res == "sI") {
                    ver = 0;
                    system("CLS");
                }
                else {
                    cout << " Bueno pero antes... checa la matriz de adyacensia  ->\n";
                    grafo.MostrarGrafo();
                    break;
                }

            }
            
        }
	}
};
