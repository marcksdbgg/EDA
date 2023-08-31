#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
using namespace std;

//Estructura de un punto con d dimensiones
struct Punto{
    int d;
    float *coordenadas;
};

//Funcion para calcular la distancia euclidiana entre dos puntos de d dimensiones
float distanciaEuclidiana(Punto p1, Punto p2){
    float distancia = 0;
    for (int i = 0; i < p1.d; i++) {
        distancia += (p1.coordenadas[i] - p2.coordenadas[i]) * (p1.coordenadas[i] - p2.coordenadas[i]);
    }
    distancia = sqrt(distancia);
    return distancia;
}

// Funcion para crear 100 puntos con d dimensiones y coordenadas aleatorias
Punto *crearPuntos(int d){
    auto *puntos = new Punto[100];
    for(int i = 0; i < 100; i++){
        puntos[i].d = d;
        puntos[i].coordenadas = new float[d];
        for(int j = 0; j < d; j++){
            puntos[i].coordenadas[j] = (float)rand() / RAND_MAX;
        }
    }
    return puntos;
}

int main() {
    srand(time(NULL));
    //Declaracion del mapa de puntos con d dimensiones
    Punto *mapa = crearPuntos(5000);
    vector<float> distancias;
    for(int i=0; i < 100; i++){
        for(int j=0; j < 100; j++){
            if(i != j){
                distancias.push_back(distanciaEuclidiana(mapa[i], mapa[j]));
            }
        }
    }
    for (int i = 0; i < distancias.size(); i++) {
        cout << distancias[i] << endl;
    }
}
