#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <ctime>
using namespace std;


typedef long long int tipo;

int obtener_menor_pos(const vector<tipo> &fila){
    int menor = 0;
    for (int i = 0; i < fila.size(); ++i) {
        if (fila[i] < fila[menor]){
            menor = i;
        }
    }
    return menor;
}

//Miguel
vector<vector<tipo>> MATRIZESPECIAL(int m , int n, vector<int> &posicion){
    vector<vector<tipo>> ME;
    int actual_menor = 0;
    for (int i = 0; i < m; ++i) {
        vector<tipo> vec;
        do {
            vec = {};
            for (int j = 0; j < n; ++j) {
                tipo numero_random = rand()%(900000000-10000000+1) + 10000000;
                vec.push_back(numero_random);
            }
        } while (actual_menor>obtener_menor_pos(vec));
        actual_menor = obtener_menor_pos(vec);
        posicion.push_back(actual_menor);
        ME.push_back(vec);
    }
    return ME;
}

bool comprobar_ascendencia(const vector<int> &asas){
    for (int i = 0; i < asas.size()-1; ++i) {
        if (asas[i]>asas[i+1]){
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> posicionesl;
    srand(time(NULL));
    vector<vector<tipo>> matrix = MATRIZESPECIAL(1000,1000,posicionesl);
    /*for (int i = 0; i < posicionesl.size(); ++i) {
        cout<<posicionesl[i]<<endl;
    }*/
    cout<<comprobar_ascendencia(posicionesl);
    return 0;
}