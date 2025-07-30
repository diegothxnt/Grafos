#include <iostream>
#include <string>
using namespace std;

const int MAX = 10;
int grafo[MAX][MAX];
bool visitado[MAX];
string nombres[MAX];

// funcion para buscar el indice de una persona por su nombre
int indiceDeNombre(string nombre, int n) {
    for (int i = 0; i < n; i++) {
        if (nombres[i] == nombre) return i;
    }
    return -1; 
}

