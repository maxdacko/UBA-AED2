#ifndef SISTEMADEMENSAJES_H
#define SISTEMADEMENSAJES_H

#include "ConexionJugador.h"
#include <string>
#include "vector"
#if EJ == 4 || EJ == 5
#include "Proxy.h"
#elif EJ == 6
#include "Proxy2.h"
#endif

using namespace std;

class SistemaDeMensajes {
  public:

    class Proxy;
    class Proxy{

    public:
        Proxy(ConexionJugador** conn);
        void enviarMensaje(string msg);

    private:
        ConexionJugador** _conn;

        // No puedo copiarlo
        Proxy(const Proxy&);

    };


    SistemaDeMensajes();
    // Pre: 0 <= id < 4

    ~SistemaDeMensajes();

    void registrarJugador(int id, string ip);
    // Pre: 0 <= id < 4
    bool registrado(int id) const;

    // Pre: registrado(id)
    void enviarMensaje(int id, string mensaje);

    // Pre: registrado(id)
    string ipJugador(int id) const;

    void desregistrarJugador(int id);

    Proxy* obtenerProxy(int id);

  private:
    ConexionJugador* _conns[4];
    vector<Proxy*> proxyCreados;
};

#endif
