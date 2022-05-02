#include <vector>
#include "algobot.h"
#include <algorithm>
using namespace std;

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s) {
    set <int> v(s.begin(), s.end());
    vector <int> w;
    w.assign(v.begin(), v.end());
    return w;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s) {
    set <int> v(s.begin(), s.end());
    vector <int> w;
    w.assign(v.begin(), v.end());
    return w;

}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b) {
    set<int> s(a.begin(), a.end());
    set<int> w(b.begin(), b.end());
    return s == w;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b) {
        set<int> s(a.begin(), a.end());
        set<int> w(b.begin(), b.end());
        return s == w;
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s) {
    map<int,int> m;
    for(int i = 0; i < s.size(); i++){
        if(m.count(s[i]) == 0){
            m[(s[i])] = 1;
        }
        else{
            m[(s[i])] += 1;
        }
    }
    return m;
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s) {
    vector<int> v;
    map<int,int> cant = contar_apariciones(s);
    for(pair<int,int> p : cant){
        if(p.second == 1){
            v.push_back(p.first);
        }
    }
    return v;
}




// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b) {
    set<int> res;
    for(int i = 0; i < a.size(); i++){
        if(b.count(i) == 1){
            res.insert(i);
        }
    }
    return res;
}


// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s) {
    map<int, set<int>> res;
    for(int i : s){
        if(res.count(i % 10) == 0){
            set<int> set_0;
            set_0.insert(i);
            res[(i % 10)] = set_0;
        } else{
            set<int> set_1;
            set_1 = res[(i % 10)];
            set_1.insert(i);
            res[(i % 10)] = set_1;
        }
    }
    return res;
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str) {
    map<char, char> dicc;
    for (int i = 0; i < tr.size(); i++) {
        dicc[tr[i].first] = tr[i].second;
    }
    for (int i = 0; i < str.size(); i++) {
        if (dicc.count(str[i]) == 1) {
            str[i] = dicc[str[i]];
        }
    }
    return str;
}


// Ejercicio 10

set<string> integrantes(string grupo) {
    set<string> set_integrantes;
    int j=0;
    int i=0;
    while(i<grupo.length()){
        if(grupo[i] == ';'){
            set_integrantes.insert(grupo.substr(j,i-j));
            j = i+1;
        }
        i++;
    }
    set_integrantes.insert(grupo.substr(j,i-j));
    return (set_integrantes);
}

set<string> interseccion_string(set<string> a, set<string> b) {
    set<string> res;
    for(string i:a){
        if(b.count(i) == 1){
            res.insert(i);
        }
    }
    return res;
}

bool integrantes_repetidos(vector<Mail> s) {
    vector<set<string>> vector_set_grupos;
    for(Mail m:s){
        vector_set_grupos.push_back(integrantes(m.asunto()));
    }

    int suma_interseccion = 0;
    for(int i=0;i<vector_set_grupos.size()-1;i++){
        for(int j=i+1;j<vector_set_grupos.size();j++){
            int interseccion_size = (interseccion_string(vector_set_grupos[i],vector_set_grupos[j])).size();
            if(interseccion_size != 0 && !(vector_set_grupos[i] == vector_set_grupos[j])){
                suma_interseccion += interseccion_size;
            }
        }
    }
    bool res = suma_interseccion != 0;
    return res;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s) {
    map<set<LU>, Mail> res;
    for(Mail m:s){
        if(m.adjunto()) { // Si tiene adjunto el mail
            if (res.count(m.libretas()) == 1) { // Si esta la libreta en el mapa
                if(m.fecha() > (res[m.libretas()]).fecha()){
                    res[m.libretas()] = m;
                }
            } else { // Si no esta la libreta en el mapa
                res[m.libretas()] = m;
            }
        }
    }
    return res;
}

