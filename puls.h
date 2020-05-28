using namespace std;

#define END 30
#define HALF END/2
void rect()
{
    int X[END];
    int Y[END];
    ofstream file("file.dat");
    for(int i=0;i<END;i++)
    {
        if(i>=HALF/2&&i<=(HALF*3)/2)
        {
            //file<<i<<"\t"<<1;
            if(i==HALF/2)
                file<<i<<"\t"<<0<<"\n";
            if(i==(HALF*3)/2)
            {
                file<<i<<"\t"<<1<<"\n";
                file<<i<<"\t"<<0<<"\n";
                continue;
            }

            file<<i<<"\t"<<1<<"\n";
        }
        else file<<i<<"\t"<<0<<"\n";
    }
    file.close();
}
