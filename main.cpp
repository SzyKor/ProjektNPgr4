#include <iostream>
#include <fstream>
#include <string.h>
#include "puls.h"
using namespace std;

int main()
{
    //test();
    rect();
    system("start gnuplot -p -e \"plot 'file.dat' with lines\"");
    return 0;
}
