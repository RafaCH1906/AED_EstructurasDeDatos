/******************************************************************************
Problema 1: El Contador Universal
Dado un arreglo de n enteros, procesa q consultas de tres tipos:
F x — imprime cuántas veces aparece x en el arreglo.
D — imprime la cantidad de valores distintos en el arreglo.
MAX — imprime el valor más frecuente (si hay empate, el menor).
Input: n, luego los n valores; luego q, luego las q consultas.
Constraints: 1≤n,q≤10^5, 1≤a_i,x≤10^9.
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int, int> frecuencia;
    for(int i =0;i<n;i++){
        int x;
        cin>> x;
        
        frecuencia[x]++;
    }
    
    int maxFrecuencia = 0;
    int valorMax = 0;
    for(auto par : frecuencia){
        int valor = par.first;
        int cantidad = par.second;
        
        if(cantidad > maxFrecuencia){
            maxFrecuencia = cantidad;
            valorMax = valor;
        }
        else if ( cantidad == maxFrecuencia && valor < valorMax){
            valorMax = valor;
        }
    }
    
    int q;
    cin>>q;
    
    while(q--){
        string operacion;
        cin >> operacion;
        
        if (operacion == "F"){
            int x;
            cin>>x;
            if (frecuencia.count(x)){
                cout << frecuencia[x] <<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else  if(operacion == "D"){
            cout << frecuencia.size()<<endl;
        }
        else if (operacion == "MAX"){
            cout << valorMax<<endl;
        }
        
    }
    return 0;
}
