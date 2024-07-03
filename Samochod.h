#pragma once
#include "Wlasciciel.h"

using namespace std;

constexpr size_t REJESTRACJA_LENGTH = 15;

class Samochod {
protected:
    char m_numerRejestracyjny[REJESTRACJA_LENGTH];
    int m_stanLicznika;
    bool m_dopuszczony;
    Wlasciciel* m_wlasciciel;
    static Samochod* wzorcowySamochod;
    static double WAR_POCZ;

public:
    Samochod();
    Samochod(const char* numerRejestracyjny, int stanLicznika, bool dopuszczony, Wlasciciel* wlasciciel);

    void setStanLicznika(int stanLicznika);
    int getStanLicznika() const;

    const char* getNumerRejestracyjny() const;
    bool isDopuszczony() const;
    Wlasciciel* getWlasciciel() const;

    virtual double obliczZasieg() const;

    operator double() const;

    bool operator!=(const Samochod& other) const;

    static void ustawWzorcowySamochod(Samochod* samochod);
    static Samochod* pobierzWzorcowySamochod();
    
};