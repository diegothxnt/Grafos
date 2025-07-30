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
int dfs(int nodo, int n) {
    visitado[nodo] = true;
    int cuenta = 1;
    for (int i = 0; i < n; i++) {
        if (grafo[nodo][i] == 1 && !visitado[i]) {
            cuenta += dfs(i, n);
        }
    }
    return cuenta;
}

int main() {
    int n, relaciones;
    cout << "Ingrese el numero de personas: ";
    cin >> n;

    cout << "Ingrese los nombres de las personas:\n";
    for (int i = 0; i < n; i++) {
        cin >> nombres[i];
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            grafo[i][j] = 0;

    cout << "Ingrese el numero de relaciones de influencia (ejemplo: Ana Luis significa que Ana influye a Luis): ";
    cin >> relaciones;

    cout << "Ingrese las relaciones:\n";
    for (int i = 0; i < relaciones; i++) {
        string a, b;
        cin >> a >> b;
        int ia = indiceDeNombre(a, n);
        int ib = indiceDeNombre(b, n);
        if (ia != -1 && ib != -1) {
            grafo[ia][ib] = 1;
        } else {
            cout << "Nombre no encontrado. Intente de nuevo.\n";
            i--; 
        }
    }

    int maxInfluencia = 0;
    int personaClave = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            visitado[j] = false;

        int alcance = dfs(i, n) - 1;
        if (alcance > maxInfluencia) {
            maxInfluencia = alcance;
            personaClave = i;
        }
    }

    cout << "La persona con mas influencia es: " << nombres[personaClave]
         << " (alcanza a " << maxInfluencia << " personas)" << endl;

    return 0;
}


