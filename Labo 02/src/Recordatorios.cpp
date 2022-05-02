#include <iostream>
#include <list>
using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
            // ene, feb, mar, abr, may, jun
            31, 28, 31, 30, 31, 30,
            // jul, ago, sep, oct, nov, dic
            31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
public:
    Fecha(uint mes, uint dia);

    uint mes();

    uint dia();

    string toString();

    void incrementar_dia();

#if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
#endif

private:
    uint mes_;
    uint dia_;
};
Fecha::Fecha(uint mes, uint dia): mes_(mes), dia_(dia) {};

uint Fecha::mes(){
    return mes_;
}

uint Fecha::dia(){
    return dia_;
}

string Fecha::toString() {
    return to_string(dia_) + "/" + to_string(mes_);
}

void Fecha::incrementar_dia() {
    if (dia_ < dias_en_mes(mes_)){
        dia_ += 1;
    } else {
        mes_ += 1;
        dia_ = 1;
    }
}

#if EJ >= 9

bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

ostream& operator<<(ostream& os, Fecha f) {
    os <<  f.dia() << "/" << f.mes();
    return os;
}

// Ejercicio 11, 12

// Clase Horario

class Horario{
public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator==(Horario o);
    bool operator<(Horario h);

private:
    uint hora_;
    uint min_;
};
Horario::Horario(uint hora, uint min): hora_(hora), min_(min) {};

uint Horario::hora(){
    return hora_;
}

uint Horario::min(){
    return min_;
}

ostream& operator<<(ostream& os, Horario h) {
    os <<  h.hora() << ":" << h.min();
    return os;
}

bool Horario::operator==(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool igual_min = this->min() == o.min();
    return igual_hora && igual_min;
}


bool Horario::operator<(Horario o) {
    bool igual_hora = this->hora() == o.hora();
    bool menor_min = this->min() < o.min();
    bool menor_hora = this->hora() < o.hora();
    return ((igual_hora && menor_min) || (menor_hora));
}

// Ejercicio 13

class Recordatorio{
public:
    Recordatorio(Fecha fecha, Horario horario, string mensaje);
    string mensaje();
    Fecha fecha();
    Horario horario();

private:
    string mensaje_;
    Fecha fecha_;
    Horario horario_;
};

Recordatorio::Recordatorio(Fecha fecha, Horario horario, string mensaje): fecha_(fecha), horario_(horario), mensaje_(mensaje)  {};


string Recordatorio::mensaje(){
    return mensaje_;
}

Fecha Recordatorio::fecha(){
    return fecha_;
}

Horario Recordatorio::horario(){
    return horario_;
}

ostream& operator<<(ostream& os, Recordatorio h) {
    os <<  h.mensaje() << " @ " << h.fecha() << " " << h.horario();
    return os;
}


// Ejercicio 14

class Agenda {
public:
    Agenda(Fecha fecha_inicial);

    void agregar_recordatorio(Recordatorio r);

    void incrementar_dia();

    list<Recordatorio> recordatorios_de_hoy();

    Fecha hoy();

private:
    Fecha _hoy;
    map<string, list<Recordatorio>> _recordatorios;
};

Agenda::Agenda(Fecha fecha_inicial) : _hoy(fecha_inicial) {}

void Agenda::agregar_recordatorio(Recordatorio r) {
    auto rs = _recordatorios[r.fecha().toString()];
    auto o = rs.begin();
    while (o != rs.end()) {
        if (r.horario() < o->horario()) {
            rs.insert(o, r);
            break;
        }
        o++;
    }
    if (o == rs.end()) rs.push_back(r);
    _recordatorios[r.fecha().toString()] = rs;
}

void Agenda::incrementar_dia() {
    _hoy.incrementar_dia();
}

list<Recordatorio> Agenda::recordatorios_de_hoy() {
    return _recordatorios[_hoy.toString()];
}

Fecha Agenda::hoy() {
    return _hoy;
}

ostream &operator<<(ostream &os, Agenda a) {
    os << a.hoy() << endl;
    os << "=====" << endl;
    for (Recordatorio r: a.recordatorios_de_hoy()) {
        os << r << endl;
    }
    return os;
}