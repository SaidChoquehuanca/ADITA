//
// Created by USER on 5/30/2022.
//

#ifndef ADITA_MATRIXESPECIAL_H
#define ADITA_MATRIXESPECIAL_H

#include <bits/stdc++.h>

using namespace std;

class MatrixEspecial {
private:
    vector<vector<int>> matriz;
public:
    MatrixEspecial(const vector<vector<int>> &matriz);

    virtual ~MatrixEspecial();

    const vector<vector<int>> &getMatriz() const;

    void setMatriz(const vector<vector<int>> &matriz);

    ostream& operator<<(MatrixEspecial &m);

};




#endif //ADITA_MATRIXESPECIAL_H
