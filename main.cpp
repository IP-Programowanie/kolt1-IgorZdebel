#include "Samochod.h"
#include "SamochodElektryczny.h"
#include <iostream>


using namespace std;





int main()
{
    Wlasciciel wlasciciel1;
    Samochod wzorcowy("ABC123", 5021, true, &wlasciciel1);
    Samochod::ustawWzorcowySamochod(&wzorcowy);

    Samochod samochod1;
    cout << "Samochod 1 " << endl;
    cout << "Numer rejestracyjny: " << samochod1.getNumerRejestracyjny() << endl;
    cout << "Stan licznika: " << samochod1.getStanLicznika() << endl;
    cout << "Dopuszczony: " << (samochod1.isDopuszczony() ? "Tak" : "Nie") << endl;
    cout << "Zasieg: " << samochod1.obliczZasieg() << " km" << endl;
    cout << "---------------------------" << endl;

    SamochodElektryczny samochodElek1("XYZ789", 5000, true, &wlasciciel1, 80);
    cout << "Samochod Elektryczny 1" << endl;
    cout << "Numer rejestracyjny: " << samochodElek1.getNumerRejestracyjny() << endl;
    cout << "Stan licznika: " << samochodElek1.getStanLicznika() << endl;
    cout << "Stan baterii: " << samochodElek1.getStanBaterii() << endl;
    cout << "Dopuszczony: " << (samochodElek1.isDopuszczony() ? "Tak" : "Nie") << endl;
    cout << "Zasieg: " << samochodElek1.obliczZasieg() << " km" << endl;

    double wartosc = static_cast<double>(samochodElek1);
    cout << "Wartosc: " << wartosc << " PLN" << endl;
    cout << "---------------------------" << endl;

    if (samochod1 != samochodElek1) {
        cout << "Samochody sa rozne" << endl;
    }
    else {
        cout << "Samochody sa takie same" << endl;
    }

    return 0;
}

