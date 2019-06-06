#include<iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>
using namespace std;
main()
{
    srand(time(NULL));
    ofstream fo("test7.inp");
    int vertical=100000;
    int edge=500000;
    int mod=vertical;
    int verticalx=rand()%mod+1;
    int verticaly=verticalx;
    while(verticalx==verticaly)
    {
        verticaly=rand()%mod+1;
    }
    fo<<vertical<<" "<<edge<<" "<<verticalx<<" "<<verticaly<<endl;
    int numberx,numbery,values;
    for(int i=1; i<=edge; i++)
    {
        numberx=rand()%mod+1;
        numbery=numberx;
        while(numberx==numbery)
        {
            numbery=rand()%mod+1;
        }
        values=rand()%mod+1;
        fo<<numberx<<" "<<numbery<<" "<<values<<endl;
    }
}
