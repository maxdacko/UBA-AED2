#include "gtest-1.8.1/gtest.h"
#include "../src/Libreta.h"
#include "../src/Truco.h"
#include <map>
#include <cmath>

using namespace std;

// Ejercicio 4
TEST(Aritmetica, suma) {
    EXPECT_EQ( 15 + 7, 22);
}

// Ejercicio 5
TEST(Aritmetica, potencia) {
    EXPECT_EQ(pow(10,2), 100);
}

// Ejercicios 6..9

TEST(Aritmetica, potencia_general) {
    for(int i = -5; i <= 5; i++){
        EXPECT_EQ(pow(i, 2), i * i);
    }
}


TEST(Diccionario, obtener) {
    pair<int,int> p;
    p.first = 3;
    p.second = 4;
    map<int, int> m;
    m.insert(p);
    EXPECT_EQ(m.at(3),4);
}

TEST(Diccionario, definir) {
    pair<int,int> p;
    p.first = 3;
    p.second = 4;
    map<int, int> m;
    bool pertenece = false;
    if (m.count(p.first)==1){
        pertenece = true;
    }
    EXPECT_FALSE(pertenece);

    m.insert(p);
    if (m.count(p.first)==1){
        pertenece = true;
    }
    EXPECT_TRUE(pertenece);
}


TEST(Truco, inicio) {
    Truco tr;
    EXPECT_EQ(tr.puntaje_j1(), 0);
    EXPECT_EQ(tr.puntaje_j2(), 0);
}

TEST(Truco, buenas) {
    Truco t;
    EXPECT_FALSE(t.buenas(1));
    for (int i = 0; i < 15; ++i) {
        t.sumar_punto(1);
    }
    EXPECT_FALSE(t.buenas(1));
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
    t.sumar_punto(1);
    t.sumar_punto(1);
    EXPECT_TRUE(t.buenas(1));
}



