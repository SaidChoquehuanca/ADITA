#include <bits/stdc++.h>

using namespace std;

int busqueda_lineal(vector<int> fila,int j_0, int j_isima) {
    int menor = fila[0];
    for(int i = j_0 ; i < j_isima; i++){
        if(fila[i] < menor) {
            menor= fila[i];
        }
    }
    return menor;
}

/*
int menor_fila(vector<int> fila){
    int menor = fila[0];
    for (int i=0; i<fila.size(); i++){
        if(fila[i] < menor) {
            menor= fila[i];
        }
    }
    return menor;
}

  */

void Cacanua(vector<vector<int>> matriz, vector<int> &minimos){

    if(minimos = matriz.size()){
        return;
    }
    else{
        Cacanua();
    }
}



int main() {
    std::cout << "Hello World!\n";




}

