#include "Lista.h"

Lista::Lista(): length(0), head(nullptr), tail(nullptr) {};

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    Nodo* it = head;
    while(it != nullptr) {
        it = it->next;
        for (int i = 0; i < length; i++){
            eliminar(i);
        }
    }
}

Lista& Lista::operator=(const Lista& aCopiar) {
    if (this != &aCopiar) {
        Nodo* it = aCopiar.head;
        while (length > 0){
            for (int i = 0; i < length; i++){
                eliminar(i);
            }
        }
        while (it != nullptr) {
            agregarAtras(it->valor);
            it = it->next;
        }
    }
    return *this;
}



void Lista::agregarAdelante(const int& elem) {
    Nodo* temp = new Nodo(elem);
    if (length == 0) {
        head = temp;
        tail = temp;
    } else {
        head->prev = temp;
        temp->next = head;
        head = temp;
        temp -> prev = nullptr;
    }
    this-> length++;
}

void Lista::agregarAtras(const int& elem) {
    Nodo* temp = new Nodo(elem);
    if (length == 0) {
        head = temp;
        tail = temp;
    } else {
        tail->next = temp;
        temp -> prev = tail;
        tail = temp;
        temp->next = nullptr;
    }
    this-> length++;
}


void Lista::eliminar(Nat i) {
    Nodo* it = head;
    for (int j = 0; j < i; j++){
        it = it->next;
    }
    if (it->prev == nullptr){
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            delete it;
        }
        else if (length > 1) {
            it->next->prev = nullptr;
            head = it->next;
            delete it;
        }
    }
    else if (it->next == nullptr){
        if (length == 1) {
            head = nullptr;
            tail = nullptr;
            delete it;
        }
        else if (length > 1) {
            it->prev->next = nullptr;
            tail = it->prev;
            delete it;
        }
    }
    else {
        it->prev->next = it->next;
        it->next->prev = it->prev;
        delete it;
    }
    this->length--;
}

int Lista::longitud() const {
    return this-> length;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* it = head;
    for (int j = 0; j < i; j++){
        it = it->next;
    }
    return it->valor;
}


int& Lista::iesimo(Nat i) {
    Nodo* it = head;
    for (int j = 0; j < i; j++){
        it = it->next;
    }
    return it->valor;

}

void Lista::mostrar(ostream& o) {
    // Completar
}

Lista::Nodo::Nodo(const int& elem) : valor(elem), next(nullptr), prev(nullptr) {};