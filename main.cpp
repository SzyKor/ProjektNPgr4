#include <iostream>
#include <fstream>
using namespace std;

void liniowa(){
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


int main(){
    liniowa();
    return 0;
}
