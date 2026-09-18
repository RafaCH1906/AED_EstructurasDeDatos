/******************************************************************************
 Problema 2: Elementos que sobreviven
 Un elemento "sobrevive" si aparece exactamente una vez en el arreglo. 
 Imprime dos números: cuántos elementos sobreviven, 
 y el menor valor entre los que sobreviven (si ninguno sobrevive, 
 imprime -1 en su lugar).
*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    
    unordered_map<int, int> frecuencia;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        frecuencia[x]++;
    }
    
    int cantidad = 0;
    int menor = 0;
    
    for(auto par : frecuencia){
        int valor = par.first;
        int veces = par.second;
        if(veces ==1){
            cantidad++;
            
            if (cantidad == 1 || valor < menor){
                menor = valor;
            }
        }
    }
    if (cantidad == 0){
            cout<<0<<" -1"<<endl;
        }
        else{
            cout << cantidad<<" "<<menor<<endl;
        }
    

    return 0;
}
