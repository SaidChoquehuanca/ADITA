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

int busqueda_lineal(vector<tipo> fila,int j_0, int j_isima) {
    tipo menor = fila[j_0];
    int pos_menor = j_0;
    for(int i = j_0 ; i <= j_isima; i++){
        if(fila[i] < menor) {
            menor = fila[i];
            pos_menor = i;
        }
    }
    return pos_menor;
}

s
int buscar_position(const vector<tipo> &fila,int j_0, int j_iesima){
    return busqueda_lineal(fila,j_0,j_iesima);

}

void get_minimo(const vector<vector<tipo>> &ME,int fila_mid, int *columna_sup , int *columna_inf,vector<int> &minimos,bool direc)
{

    int pos = buscar_position(ME[fila_mid],*columna_sup,*columna_inf);
    //cout<<endl<<fila_mid<<" | "<<*columna_sup<<" - "<<*columna_inf<<"| "<<pos<<" | "<<ME[fila_mid][pos]<<endl;
    //cout<<endl<<fila_mid + 1 <<" | "<<*columna_sup + 1<<" a "<<*columna_inf + 1 <<" | "<<direc<<" | "<<"\n";
    if (!direc){
        *columna_inf=pos;
    } else{
        *columna_sup=pos;
    }
    minimos[fila_mid] = pos+1;
}

void cacahuasi(const vector<vector<tipo>> &ME, int fila_sup, int columna_sup , int fila_inf , int columna_inf, vector<int> &minimos,bool dir){
    int fila_mid = int((fila_sup+fila_inf)/2);
    if (fila_sup < fila_inf){
        int *ptr_columna_sup=&columna_sup;
        int *ptr_columna_inf=&columna_inf;
        cacahuasi(ME,fila_sup,*ptr_columna_sup,fila_mid,*ptr_columna_inf,minimos,true);
        cacahuasi(ME,(fila_mid+1),*ptr_columna_sup,fila_inf,*ptr_columna_inf,minimos,false);
        get_minimo(ME,fila_mid,ptr_columna_sup,ptr_columna_inf,minimos,dir);
    }
    else{
        return;
    }
}


bool iguales(vector<int> a , vector<int> b){
    for (int i = 0; i < a.size(); ++i) {
        if (a[i]!=(b[i]-1)){
            return false;
        }
    }
    return true;
}

int main() {
    //pipipipi
    vector<int> posicionesl;
    srand(time(NULL));
    vector<vector<tipo>> matrix = MATRIZESPECIAL(1000,1000,posicionesl);
    cout<<"\nCreado\n";
    /*
    int fil,col;
    tipo num;
    cin>>fil>>col;
    for(int i = 0 ; i < fil; i++){
        vector<tipo> owo;
        for(int j=0; j < col ; j++){
            cin>>num;
            owo.push_back(num);
        }
        matrix.push_back(owo);
    }
    */
    vector<int> min(matrix.size());
    int fila_sup = 0;
    int fila_inf = matrix.size();
    int columna_sup = 0;
    int columna_inf = matrix[0].size()-1;



    cacahuasi(matrix,fila_sup,columna_sup,fila_inf,columna_inf,min,false);
    for (int i = 0; i < min.size(); ++i) {
       // cout<<min[i]<<" ";
    }
    cout<< "\n";
    if (iguales(posicionesl,min)){
        cout<<"Excelente\n";
    }
    return 0;
}