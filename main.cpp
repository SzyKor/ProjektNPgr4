#include <iostream>
#include <fstream>
#include <string.h>
#include <math.h>
#include "puls.h"
using namespace std;

int main()
{
    //test();
    int freq=3;
    //puls_rect(freq);
    //puls_dirac(freq);
    //puls_cosin(freq);
    //test();
    puls_sinc(freq);
    system("start gnuplot -p -e \"set yrange[-1:2];plot 'file.dat' with lines\"");
    return 0;
}
