#include <iostream>
#include "sin.h"

using namespace std;

    /*
    Tutaj mają być wywołania funckji w menu, funkcje w oddzienych plikach, niech będą od siebie niezależne, żeby nie było problemów ze scalaniem.
    */

void menu()
{
    int m;
    cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
    cout << " 1 - sinusoidalnej \n 2 - jednostkowo-liniowej" << endl;
    cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    while ((!(cin >> m)) || m>4 || m<1)
    {
        cout << "\nPODANO BLEDNA WARTOSC, PROSZE O PODANIE POPRAWNEJ WARTOSCI\n" << endl; //Podwójne przejscie do nowej linii w celu wyróżnienia komunikatu
        cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
        cout << " 1 - sinusoidalnej \n 2 - jednostkowo-liniowej" << endl;
        cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    }
    switch (m)
    {
    case 1:
        sin();
        break;
    case 2:
        //jedlin();
        break;
    case 3:
        //pul();
        break;
    case 4:
        //wyk();
        break;
    default:
        cout << "Wystapil nieoczekiwany blad nr.0000";
        break;
    }
}

int main()
{
    menu();
}