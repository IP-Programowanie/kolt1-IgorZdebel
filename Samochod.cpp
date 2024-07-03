#define _CRT_SECURE_NO_WARNINGS
#include "Samochod.h"
#include <cstring>
#include <stdexcept>
#include <cmath>

using namespace std;


Samochod* Samochod::wzorcowySamochod = nullptr;
double Samochod::WAR_POCZ = 10000.0;  

Samochod::Samochod() {
    if (!wzorcowySamochod) {
        throw runtime_error("Brak wzorcowej instancji samochodu");
    }
    strncpy(m_numerRejestracyjny, wzorcowySamochod->m_numerRejestracyjny, REJESTRACJA_LENGTH);
    m_stanLicznika = wzorcowySamochod->m_stanLicznika;
    m_dopuszczony = wzorcowySamochod->m_dopuszczony;
    m_wlasciciel = wzorcowySamochod->m_wlasciciel;
}

Samochod::Samochod(const char* numerRejestracyjny, int stanLicznika, bool dopuszczony, Wlasciciel* wlasciciel)
    : m_dopuszczony(dopuszczony), m_wlasciciel(wlasciciel) {
    strncpy(m_numerRejestracyjny, numerRejestracyjny, REJESTRACJA_LENGTH);
    setStanLicznika(stanLicznika);
}

void Samochod::setStanLicznika(int stanLicznika) {
    if (stanLicznika < 0) {
        throw invalid_argument("Stan licznika nie mo¿e byc ujemny");
    }
    m_stanLicznika = stanLicznika;
}

int Samochod::getStanLicznika() const {
    return m_stanLicznika;
}

const char* Samochod::getNumerRejestracyjny() const {
    return m_numerRejestracyjny;
}

bool Samochod::isDopuszczony() const {
    return m_dopuszczony;
}

Wlasciciel* Samochod::getWlasciciel() const {
    return m_wlasciciel;
}

double Samochod::obliczZasieg() const {
    if (!m_dopuszczony) {
        throw runtime_error("Samochod niedopuszczony do jazdy");
    }
    return 800.0;
}

Samochod::operator double() const {
    double WSP_SPARW = m_dopuszczony ? 1.0 : 0.2;
    double wartosc = (WAR_POCZ - 0.2 * m_stanLicznika) * WSP_SPARW;
    return wartosc < 400.0 ? 400.0 : wartosc;
}

bool Samochod::operator!=(const Samochod& other) const {
    return abs(m_stanLicznika - other.m_stanLicznika) > 20 || m_dopuszczony != other.m_dopuszczony;
}

void Samochod::ustawWzorcowySamochod(Samochod* samochod) {
    wzorcowySamochod = samochod;
}

Samochod* Samochod::pobierzWzorcowySamochod() {
    return wzorcowySamochod;
}
