#include "SistemaDeMensajes.h"

SistemaDeMensajes ::SistemaDeMensajes() {
    for(int i = 0; i < 4 ; i++){
        _conns[i] = nullptr;
    }
}

SistemaDeMensajes::~SistemaDeMensajes(){
    for(int i = 0 ; i < 4 ; i++){
        delete _conns[i];
    }

    for (Proxy* p : proxyCreados){
        delete p;
    }
}

void SistemaDeMensajes ::registrarJugador(int id, string ip) {
    if(registrado(id)){
        desregistrarJugador(id);
    }
    _conns[id]=new ConexionJugador(ip);
}


void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje); //= a decir (*_conns[id]).enviarMensaje(mensaje)
}

bool SistemaDeMensajes::registrado(int id) const {
    if(_conns[id] == nullptr) {
        return false;
    } else {
        return true;
    }
}

string SistemaDeMensajes::ipJugador(int id) const{
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id){
    delete _conns[id];
    _conns[id]= nullptr;
}


SistemaDeMensajes:: Proxy* SistemaDeMensajes::obtenerProxy(int id){
    Proxy* P = new Proxy(&_conns[id]);
    proxyCreados.push_back(P);
    return P;
}

SistemaDeMensajes::Proxy::Proxy (ConexionJugador** conn) : _conn(conn) {}

void SistemaDeMensajes::Proxy:: enviarMensaje(string msg) {
    (*_conn)->enviarMensaje(msg);
}

