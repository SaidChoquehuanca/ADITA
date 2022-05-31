//
// Created by USER on 5/30/2022.
//

#include "MatrixEspecial.h"

MatrixEspecial::MatrixEspecial(const vector<vector<int>> &matriz) : matriz(matriz) {}

MatrixEspecial::~MatrixEspecial() {

}

const vector<vector<int>> &MatrixEspecial::getMatriz() const {
    return matriz;
}

void MatrixEspecial::setMatriz(const vector<vector<int>> &matriz) {
    MatrixEspecial::matriz = matriz;
}

ostream &MatrixEspecial::operator<<(MatrixEspecial &m) {
    for (int i = 0; i < matriz.size(); ++i) {
        for (int j = 0; j < matriz[i].size(); ++j) {
            cout<<setw(4)<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
}




