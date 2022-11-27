#pragma once
#include <iostream>
using namespace std;
//using namespace sf;

class Grafo {
private:
    static const int dim = 11;

public:
    int matriz[dim][dim];
    Grafo() {
        // Matriz de Inicialización
        for (int i = 0; i < dim; i++) {
            for (int j = 0; j < dim; j++) {
                matriz[i][j] = 0;
            }
        }
    }

    // Crear conexiones de los nodos
    void CrearArista(int NodoOrig, int NodoDest)
    {
        matriz[NodoOrig][NodoDest] = 1;
    }

    void MostrarGrafo() {
        for (int i = 0; i < dim; i++) {

            for (int j = 0; j < dim; j++) {
                cout << matriz[i][j] << ", ";
            }
            cout << endl;
        }
    }

    bool End(int posicion) {
        for (int j = 0; j < dim; j++) {
            if (matriz[posicion][j] == 1) {
                return true;
            }
        }
        return false;
    }

    short NumCaminos (int position) {
        int i = 0;
        for (int j = 0; j < dim; j++) {
            if (matriz[position][j] == 1) {
                i++;
            }
        }
        return i;
    }

    short ObtenerAdyacente (int position, short selector) {
        int i = 0;
        for (int j = 0; j < dim; j++) {
            if (matriz[position][j] == 1) {
                i++;
                if (i == selector) {
                    return j;
                }
            }
        }
        return -1;
    }

    void Opc (int position) {
        cout << "Tus Opciones son: ";
        for (int j = 0; j < dim; j++) {
            if (matriz[position][j] == 1) {
                cout << j << ", ";
            }
        }
    }

    bool ValidarOpcion(int position, int opcion) {
        return (matriz[position][opcion] == 1) ? true : false;
    }
};

