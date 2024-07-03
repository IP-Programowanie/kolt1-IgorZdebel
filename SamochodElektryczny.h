#pragma once
#include "Samochod.h"

using namespace std;

class SamochodElektryczny : public Samochod {

protected:
    int m_stanBaterii;

public:
    SamochodElektryczny(const char* numerRejestracyjny, int stanLicznika, bool dopuszczony, Wlasciciel* wlasciciel, int stanBaterii);

    void setStanBaterii(int stanBaterii);
    int getStanBaterii() const;

    double obliczZasieg() const override;
    operator double() const;
};