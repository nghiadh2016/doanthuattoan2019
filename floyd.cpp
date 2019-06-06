#include<iostream>
#include<fstream>
using namespace std;
long long** arr;

void init_memory(int vertical)
{
    arr=new long long*[vertical+1];
    for(int i=1; i<=vertical; i++)
    {
        arr[i]=new long long[vertical+1];
    }
}
void init_valuesarr(int vertical)
{
    for(int i=1; i<=vertical; i++)
    {
        for(int j=1; j<= vertical; j++)arr[i][j]=10e17;
    }
}
void print_arr(int vertical)
{
    for(int i=1; i<=vertical; i++)
    {
        for(int j=1; j<= vertical; j++)
        {
            if(arr[i][j]==10e17)cout<<"oo\t";
            else cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"------------------------------------------------------"<<endl;
}
void input_file(int &vertical,int &verticalx,int &verticaly)
{
    ifstream fi("test2.inp");
    int edge;
    fi>>vertical>>edge>>verticalx>>verticaly;
    int numberx,numbery;
    long long values;
    init_memory(vertical);
    init_valuesarr(vertical);
    for(int i=1; i<=edge; i++)
    {
        fi>>numberx>>numbery>>values;
        arr[numberx][numbery]=min(arr[numberx][numbery],values);
    }
}
void floyd(int vertical)
{
    for(int k=1; k<=vertical; k++)
    {
        for(int i=1; i<=vertical; i++)
        {
            for(int j=1; j<=vertical; j++)
            {
                if(arr[i][j]>arr[i][k]+arr[k][j])
                {
                    arr[i][j]=arr[i][k]+arr[k][j];
                }
            }
        }
    }
}

main()
{
    int vertical,edge,verticalx,verticaly;
    input_file(vertical,verticalx,verticaly);
    floyd(vertical);
    if(arr[verticalx][verticaly]==10e17)cout<<"khong ton tai duong di tu dinh "<<verticalx<<" sang dinh "<<verticaly;
    else cout<<"duong di ngan nhat tu dinh "<<verticalx<<" sang dinh "<<verticaly<<" la: "<<arr[verticalx][verticaly];
}
