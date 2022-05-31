#include <iostream>
#include <vector>
#include <array>
#include <math.h>
using namespace std;

//Miguel
int busqueda_lineal(vector<int> fila,int j_0, int j_isima) {
    int menor = fila[0];
    for(int i = j_0 ; i < j_isima; i++){
        if(fila[i] < menor) {
            menor= fila[i];
        }
    }
    return menor;
}


int buscar_position(vector<int>fila,int j_0, int j_iesima){
    int bus = busqueda_lineal(fila,j_0,j_iesima);
    for (int i = 0; i<fila.size(); i++){
        if (fila[i]==bus)
        {
            return i;
        }
    }
    return 0;
}

int get_minimo(const vector<vector<int>> &ME, int n_filas0, int &m_columnas0 , int n_filase , int &m_colmanase,bool direc)
{
    int numero = busqueda_lineal(ME[int(n_filas0/n_filase)],m_columnas0,m_colmanase);

    int pos = buscar_position(ME[int(n_filas0/n_filase)],m_columnas0,m_colmanase);

    if (direc){
        m_colmanase=pos;
    } else{
        m_columnas0=pos;
    }
    return numero;
}

void cacahuasi(const vector<vector<int>> &ME, int n_filas0, int &m_columnas0 , int n_filase , int &m_colmanase, vector<int> &minimos,bool dir){
    int fila_mid;
    int *ptr_coli=&m_columnas0;
    int *ptr_cole=&m_colmanase;
    if (n_filas0 < n_filase){
        fila_mid = int((n_filas0+n_filase)/2);
        cacahuasi(ME,fila_mid,*ptr_coli,fila_mid,*ptr_cole,minimos,true);
        cacahuasi(ME,(fila_mid+1),*ptr_coli,n_filase,*ptr_cole,minimos,false);
        auto a = get_minimo(ME,n_filas0,*ptr_coli,n_filase,*ptr_cole,dir);
        minimos.push_back(a);
    }

}


int main() {
    vector<vector<int>> matrix = {
            {1,2,3},
            {4,3,5},
            {6,5,4}
    };
    /*
    for (size_t i = 0; i < fila.size(); ++i) {
        cout << fila[i] << "; ";
    }
    cout << endl;
    cout << busqueda_lineal(fila, 5, 11);
    cout << endl;

    cout << buscar_position(fila,5,11);
    */
    vector<int> min;
    int f0= 0;
    int ff = 3;
    cacahuasi(matrix,0,f0,3,ff,min,false);
    for (int i = 0; i < min.size(); ++i) {
        cout<<min[i]<<" ";
    }

    return 0;
}