using namespace std;

void rysowanie(int spacje, int stan)
{
    cout << "|";
    for (int i = 0; i < spacje; i++)
    {
        cout << " ";
    }
    switch (stan)
    {
    case 0:
        cout << "-";
        break;
    case 1:
        cout << "/";
        break;
    case -1:
        cout << "\\";
        break;
    default:
        cout << "?";
        break;
    }
}

double degreetorad(double deg)
{
    //double rad = (deg * M_PI) / 180;
}

void sin()
{
    float px = 0, py = 0;
    bool odx = 0, ody = 0, wb = 0;
    /*
    cout << "Podaj przesuniecie wzgledem osi X (prawo-/lewo+)" << endl;
    cin >> px;
    cout << "Podaj przesuniecie wzgledem osi Y (gora+/dol-)" << endl;
    cin >> py;
    cout << "Odbicie wzgledem osi X (Tak 1/Nie 0)" << endl;
    cin >> odx;
    cout << "Odbicie wzgledem osi Y (Tak 1/Nie 0)" << endl;
    cin >> ody;
    cout << "Wartosc bezwzgledna z funkcji" << endl;
    cin >> wb;
    */

}