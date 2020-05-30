#include <iostream>
#include <fstream>
#include <cmath>
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
