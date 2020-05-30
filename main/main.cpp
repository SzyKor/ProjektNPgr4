#include <iostream>
#include <fstream>
using namespace std;

void liniowa(float a, float b, float x, float mp){
    int tabX[8],i;
    int tabY[8];
    cout << "Funkcja liniowa"<<endl;
    cout << "f(x) = ax + b\n\n";
    cout << "Podaj a: ";
    cin >> a;
    cout << "Podaj b: ";
    cin >> b;
    cout << "\n\n";
    if (a==0 && b==0) cout << "Nieskonczenie wiele rozwiazan\n";
    else if (a==0 && b!=0) cout << "Brak rozwiazan\n";
    else{
        if(b<0)cout << "f(x) = " << a << "x " << "+ (" << b << ")" << endl;
        else cout << "f(x) = " << a << "x " << "+ " << b << endl;
        x=-b/a;
        cout << "Miejsce zerowe = " << x <<endl;
        mp = a*0+b;
        cout << "Miejsce przeciecia osi Y = " << mp << "\n\n";
        for(i=0; i<8;i++){
            tabX[i]=i;
            tabY[i]=(a*i+b);
        }
    }

    if(b<0)cout << "f(x) = " << a << "x " << "+ (" << b << ")" << endl;
    else cout << "f(x) = " << a << "x " << "+ " << b << endl;
    cout <<"____________"<<endl;

    for(i=0; i<8;i++){
        if(i<8)cout<<tabX[i]<<" | "<<tabY[i]<<endl;
        else cout<<" "<<tabX[i]<<" | "<<tabY[i]<<endl;
    }
    ofstream file;
    file.open("file.dat");
    for(int j=0;j<8;j++) file<<tabX[j]<<" "<<tabY[j]<<endl;
    file.close();
    system("start gnuplot -p -e \"plot 'file.dat' with lines\"");
}

//##################################################
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
        //sin();
        break;
    case 2:
        float a,b,x,mp;
        liniowa(a,b,x,mp);
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
