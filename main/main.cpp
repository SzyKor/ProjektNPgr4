#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//#################################################################
// Początek funkcji liniowej

float liniowa(){
    float a, b, x, mp;
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

//Koniec funkcji liniowej
//#######################################################################

void zapisz(float x[], float y[])
{
    ofstream file;
    file.open("file.dat");
    for(int j=0;j<90;j++){
        file<<x[j]<<" "<<y[j]<<endl;
        }
    file.close();
    system("start gnuplot -p -e \"plot 'file.dat' with lines \"");
}

void wykladnicza()
{
 cout << "Funkcja wykladnicza ma wzor:"<<endl;
    cout << "f(x)=a^x"<<endl<<"gdzie a>0"<<endl<<endl;

    cout<<"Podaj a: ";
    float a;
    float x[90],x2[90];
    int i;
    float y[90],y2[90];
    cin>>a;
    if(a!=0){
        for(i=0; i<90;i++)
        {
            float k=i;
            x[i]=(k-50)/10;
            x2[i]=x[i]; //do odbicia wykresu
            y[i]=pow(a,(x[i]));
            y2[i]=y[i]; //do odbicia wykresu
        }
    }else
    cout<<"Bledna liczba";

    int wybor=0;
    float ile=0;
    while(wybor!=7)
    {
    cout<<endl<<endl<<"Menu: "<<endl<<endl;
    cout<<"1) Wyswietl wykres"<<endl;
    cout<<"2) Przesun wykres w dol lub w gore"<<endl;
    cout<<"3) Przesun wykres w lewo lub w prawo"<<endl;
    cout<<"4) Odbij wykres wzgledem osi OX"<<endl;
    cout<<"5) Odbij wykres wzgledem osi OY"<<endl;
    cout<<"6) Wyswietl wykres z wartoscia bezwzgledna"<<endl;
    cout<<"7) Wyjscie"<<endl;
    cin >> wybor;
        switch(wybor)
        {
        case 1: // wyswietlanie wykresu
            zapisz(x,y);
            break;
        case 2: // przesuniecie na osi OY
            cout<<"O ile chcesz przesunac wykres? ";cin>>ile;
            for(i=0; i<90;i++)
            y[i]=y[i]+ile;

            zapisz(x,y);
            break;
        case 3: // przesuniecie na osi OX
            cout<<"O ile chcesz przesunac wykres? ";cin>>ile;
            for(i=0; i<90;i++)
            x[i]=x[i]+ile;

            zapisz(x,y);
            break;
        case 4: // odbicie wzgledem osi OX
            for(i=0; i<90;i++)
            y2[i]=y[i];

            for(i=0; i<90;i++)
            y[i]=-y2[i];

            zapisz(x,y);
            break;
        case 5: // odbicie wzg;edem osi OY
            for(i=0; i<90;i++)
            x2[i]=x[i];

            for(i=0; i<90;i++)
            x[i]=x2[89-i];

            zapisz(x,y);
            break;
        case 6: // odbicie wzgledem osi OX
            for(i=0; i<90;i++)
            y2[i]=y[i];

            for(i=0; i<90;i++)
            {
                if(y[i]<0)
                y[i]=y[i]*(-1);
            }
            zapisz(x,y);
            break;
        case 7: // koniec
            break;
        default:
            cout<<"Nie ma takiego wyboru. Wybierz liczbe od 1 do 7"<<endl;
            break;
        }
    }
}

//Początek fragmentu odpowiedzialnego za rysownie funkcji sinusoidalnej
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
    while ((!(cin >> x)) && x > 0)
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc x, podaj wartosc x ponownie" << endl;
    }
    cout << "Podaj przesuniecie wzgledem osi X (prawo-/lewo+)" << endl;
    while (!(cin >> px))
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc przesuniecia, podaj wartosc przesuniecia x ponownie" << endl;
    }
    cout << "Podaj przesuniecie wzgledem osi Y (gora+/dol-)" << endl;
    while (!(cin >> py))
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc przesuniecia, podaj wartosc przesuniecia y ponownie" << endl;
    }
    cout << "Odbicie wzgledem osi X (Tak 1/Nie 0)" << endl;
    while (!(cin >> odx))
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc odbicia, podaj jescze raz" << endl;
    }
    cout << "Odbicie wzgledem osi Y (Tak 1/Nie 0)" << endl;
    while (!(cin >> ody))
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc odbicia, podaj jescze raz" << endl;
    }
    cout << "Wartosc bezwzgledna z funkcji (Tak 1/Nie 0)" << endl;
    while (!(cin >> wb))
    {
        cin.clear();
        cin.ignore();
        cout << "Podana bledna wartosc, podaj jescze raz" << endl;
    }
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
//Koniec fragmentu odpowiedzialnego za rysowanie funkcji sinusoidalnej

//##################################################

//Poczatek Pulsacyjne
void puls_rect(float freq,int END)
{
    int separator=END/freq;
    ofstream file("file.dat");
    int j=0;
    for(int i=0;i<END;i++)
    {
            if(j==separator-1) j=0;

            if(j>=separator/4&&j<=(separator*3)/4)
                {

                    if(j==separator/4)
                    {
                        file<<i<<"\t"<<0<<"\n";
                        file<<i<<"\t"<<1<<"\n";
                    }else
                    if(j==(separator*3)/4)
                    {
                        file<<i<<"\t"<<1<<"\n";
                        file<<i<<"\t"<<0<<"\n";
                    }else
                    file<<i<<"\t"<<1<<"\n";
                }else
                file<<i<<"\t"<<0<<"\n";
            j++;

    }
    file.close();
}



void puls_dirac(float freq,int END)
{
    int separator=END/freq;
    ofstream file("file.dat");
    int j=0;
    for(int i=0;i<END;i++)
    {
            if(j==separator-1) j=0;

            if(j==separator/2)
            {
                file<<i<<"\t"<<0<<"\n";
                file<<i<<"\t"<<1<<"\n";
                file<<i<<"\t"<<0<<"\n";
            }

            else
            file<<i<<"\t"<<0<<"\n";

            j++;

    }
    file.close();
}

void puls_sinc(float freq,int END)
{
    int separator=END/freq;
    ofstream file("file.dat");
    float podzial=360/float(separator);
    float incr=-180;
    for(int i=0;i<END;i++)
    {
            if(incr>=180) incr=-180;


                    file<<i<<"\t"<<(sin(incr)/incr)<<"\n";
                    incr=incr+podzial;
    }
    file.close();
}

void puls_menu()
{
    float freq;
    int END;
    cout<<"Podaj czestotliwiosc i dlugosc osi x\n";
    cout<<"Czestotliwosc dowolna(polecam 3),";
    cout<<"Dlugosc osi x wplywa na dokladnosc, im wieksza liczba tym lepeiej (polecam 1000)\n";
    cout<<"Podaj Czestotliwosc: "; cin>>freq;cout<<endl;
    cout<<"Podaj dlugosc osi x: ";cin>>END;cout<<endl;

    int sw;
    do{
        cout<<"\nDostepne sa 3 funkcje pulsacyjne:\n";
        cout<<"1. Prostokatna \n2. Dirac delta \n3. Sinus cardinalis\n";
        cout<<"Wybierz funkcje (1-3)\n";
        cin>>sw;
        switch(sw)
        {
            case(1):puls_rect(freq,END);system(("start gnuplot -p -e \"set yrange[-1:2];plot 'file.dat' with lines\""));break;
            case(2):puls_dirac(freq,END);system("start gnuplot -p -e \"set yrange[-1:2];plot 'file.dat' with lines\"");break;
            case(3):puls_sinc(freq,END);system("start gnuplot -p -e \"set yrange[-1:2];plot 'file.dat' with lines\"");break;
            default:sw=0;
        }
    }while(sw==0);

}
// Koniec Pulsacyjne
//##################################################
void menu()
{
    int m;
    cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
    cout << " 1 - sinusoidalnej \n 2 - liniowa" << endl;
    cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    while ((!(cin >> m)) || m>4 || m<1)
    {
        cout << "\nPODANO BLEDNA WARTOSC, PROSZE O PODANIE POPRAWNEJ WARTOSCI\n" << endl; //Podwójne przejscie do nowej linii w celu wyróżnienia komunikatu
        cout << "Wybierz, ktorej funkcji chcesz namalowac wykres" << endl;
        cout << " 1 - sinusoidalnej \n 2 - liniowa" << endl;
        cout << " 3 - pulsacyjnej \n 4 - wykladniczej" << endl;
    }
    switch (m)
    {
    case 1:
        sin();
        break;
    case 2:
        liniowa();
        break;
    case 3:
        puls_menu();
        break;
    case 4:
        wykladnicza();
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
