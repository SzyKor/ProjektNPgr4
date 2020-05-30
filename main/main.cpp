#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

struct pozycja
{
    int x;
    double wartosc;
}pozycje;

double degreetorad(double deg)
{
    double rad = (deg * M_PI) / 180;
    return rad;
}

void sin()
{
    int x = 360, px = 0;
    float py = 0;
    bool odx = 0, ody = 0, wb = 0;
    cout << "Podaj ile x chcesz wyswietlic wykres (Polecana wartosc: 360) (zaczyna sie od zera, przesuniecie dostepne jest w dalszej czesci)" << endl;
    cin >> x;
    cout << "Podaj przesuniecie wzgledem osi X (prawo-/lewo+)" << endl;
    cin >> px;
    cout << "Podaj przesuniecie wzgledem osi Y (gora+/dol-)" << endl;
    cin >> py;
    cout << "Odbicie wzgledem osi X (Tak 1/Nie 0)" << endl;
    cin >> odx;
    cout << "Odbicie wzgledem osi Y (Tak 1/Nie 0)" << endl;
    cin >> ody;
    cout << "Wartosc bezwzgledna z funkcji (Tak 1/Nie 0)" << endl;
    cin >> wb;
    pozycja* wynik = new pozycja[x];
    for (int i = 0; i < x; i++)
    {
        wynik[i].wartosc = sin(degreetorad(i)) - py;
        if (ody)
        {
            wynik[i].x = (-1 * i) + px;
        }
        else
        {
            wynik[i].x = i + px;
        }
    }
    ofstream plik;
    plik.open("file.dat");
    for (int i = 0; i < x; i++)
    {
        if (odx)
        {
            wynik[i].wartosc *= -1;
        }
        if (wb)
        {
            wynik[i].wartosc = abs(wynik[i].wartosc);
        }
        plik << wynik[i].x << " " << wynik[i].wartosc << endl;
    }
    system("start gnuplot -p -e \"plot 'file.dat' with lines\"");
}

void menu()
{
    int m;
    cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
    cout << " 1 - sinusoidalnej \n 2 - jednostkowo-liniowej" << endl;
    cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    while ((!(cin >> m)) || m > 4 || m < 1)
    {
        cout << "\nPODANO BLEDNA WARTOSC, PROSZE O PODANIE POPRAWNEJ WARTOSCI\n" << endl; //Podwójne przejscie do nowej linii w celu wyróżnienia komunikatu
        cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
        cout << " 1 - sinusoidalnej \n 2 - jednostkowo-liniowej" << endl;
        cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    }
    cout << endl;
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
