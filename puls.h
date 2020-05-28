using namespace std;

#define END 1000
#define HALF END/2
#define PI 3.14

void test()
{
    ofstream file("file.dat");
    for(int i=0;i<=180;i++)
        file<<i<<"\t"<<cos(i*PI/180)*cos(i*PI/180)<<"\n";
    file.close();
}

//  Ma dzia³aæ na tej zasadzie
//freq=3
//33=100/freq
//0-33 34-66 67-100
//|^^^^|___|^^^^|
//
void puls_rect(int freq)
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


void puls_cosin(int freq)
{
    int separator=END/freq;
    ofstream file("file.dat");
    int j=0;
    int obszar=((separator*3)/4)-(separator/4);
    float podzial=180/float(obszar);
    float incr=0;

    for(int i=0;i<END;i++)
    {
            if(j==separator-1) j=0;
            if(incr>=180) incr=0;

            if(j>=0&&j<=(separator*4)/4)
                {
                    cout<<incr<<"\t"<<(incr*PI/180)<<"\t"<<cos(incr*PI/180)<<"\t"<<podzial<<"\n";
                    file<<i<<"\t"<<cos(incr*PI/180)*cos(incr*PI/180)<<"\n";
                    incr=incr+podzial;

                }else   file<<i<<"\t"<<0<<"\n";


            j++;

    }
    file.close();
}
void puls_dirac(int freq)
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

void puls_sinc(int freq)
{
    int separator=END/freq;
    ofstream file("file.dat");
    float podzial=360/float(separator);
    float incr=-180;
    for(int i=0;i<END;i++)
    {
        //if(j>=180) j=-1*180;
        //file<<i<<"\t"<<sin(j)/j<<"\n";
        //j++;
            if(incr>=180) incr=-180;


                    file<<i<<"\t"<<sin(incr)/incr<<"\n";
                    incr=incr+podzial;
    }
    file.close();
}
