#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
map<int,long long>* arr;
long long* values_arr;
bool* bool_arr;

void init_arr(int vertical)
{
    arr=new map<int,long long> [vertical+1];
    values_arr=new long long [vertical+1];
    bool_arr=new bool [vertical+1];
    for(int i=1; i<=vertical; i++)
    {
        bool_arr[i]=0;
        values_arr[i]=10e17;
    }
}
void input_file(int &vertical,int &verticalx,int &verticaly)
{
    ifstream fi("test2.inp");
    int edge;
    fi>>vertical>>edge>>verticalx>>verticaly;
    int numberx,numbery;
    long long values;
    init_arr(vertical);
    for(int i=1; i<=edge; i++)
    {
        fi>>numberx>>numbery>>values;
        if(arr[numberx][numbery]!=0)arr[numberx][numbery]=min(arr[numberx][numbery],values);
        else arr[numberx][numbery]=values;
    }

}
void printf_arr(int vertical)
{
    for(int i=1; i<=vertical; i++)
    {
        if(values_arr[i]==10e17)cout<<"oo\t";
        else cout<<values_arr[i]<<"\t";
    }
    cout<<endl<<"--------------------------------------------------------"<<endl;
}
void Dijkstra(int vertical,int verticalx)
{
    map<int,long long>::iterator it;
    long long values=0;
    bool_arr[verticalx]=1;
    while(true)
    {
        for(it=arr[verticalx].begin(); it!=arr[verticalx].end(); it++)
        {
            if(!bool_arr[it->first])
            {
                if(values+it->second<values_arr[it->first])
                {
                    values_arr[it->first]=values+it->second;
                }
            }
        }
        long long temp_vertical=verticalx,temp_values=10e17;
        for(int i=1; i<=vertical; i++)
        {
            if(!bool_arr[i] && temp_values>values_arr[i])
            {
                temp_vertical=i;
                temp_values=values_arr[i];
            }
        }
        if(temp_vertical==verticalx)return;
        else
        {
            verticalx=temp_vertical;
            values=temp_values;
            bool_arr[verticalx]=1;
        }


    }
}
main()
{

    int vertical,edge,verticalx,verticaly;
    input_file(vertical, verticalx,verticaly);
    Dijkstra(vertical,verticalx);
    if(values_arr[verticaly]==10e17)cout<<"khong ton tai duong di tu dinh "<<verticalx<<" sang dinh "<<verticaly;
    else cout<<"duong di ngan nhat tu dinh "<<verticalx<<" sang dinh "<<verticaly<<" la: "<<values_arr[verticaly];

}
