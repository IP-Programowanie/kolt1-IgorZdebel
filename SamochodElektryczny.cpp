#define _CRT_SECURE_NO_WARNINGS
#include "SamochodElektryczny.h"
#include <stdexcept>

using namespace std;

SamochodElektryczny::SamochodElektryczny(const char* numerRejestracyjny, int stanLicznika, bool dopuszczony, Wlasciciel* wlasciciel, int stanBaterii)
    : Samochod(numerRejestracyjny, stanLicznika, dopuszczony, wlasciciel) {
    setStanBaterii(stanBaterii);
}

void SamochodElektryczny::setStanBaterii(int stanBaterii) {
    if (stanBaterii < 0 || stanBaterii > 100) {
        throw invalid_argument("Zly przedzial stanu baterii musi byc w przedziale 0-100%");
    }
    m_stanBaterii = stanBaterii;
}

int SamochodElektryczny::getStanBaterii() const {
    return m_stanBaterii;
}

double SamochodElektryczny::obliczZasieg() const {
    if (!isDopuszczony()) {
        throw runtime_error("Samochod niedopuszczony do jazdy");
    }
    return 2.5 * m_stanBaterii;
}

SamochodElektryczny::operator double() const {
    double WSP_SPARW = isDopuszczony() ? 1.0 : 0.2;
    double wartosc = (Samochod::WAR_POCZ - 0.2 * getStanLicznika()) * WSP_SPARW * 0.7;
    return wartosc < 400.0 ? 400.0 : wartosc;
}