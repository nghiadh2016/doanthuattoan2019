#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;
map<pair<int,int>,long long> arr;
long long* values_arr;
bool* bool_arr;
void init_arr(int vertical)
{
    values_arr=new long long [vertical+1];
    bool_arr=new bool[vertical+1];
    for(int i=1; i<=vertical; i++)
    {
        values_arr[i]=10e17;
        bool_arr[i]=0;
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
    values_arr[verticalx]=0;
    for(int i=1; i<=edge; i++)
    {
        fi>>numberx>>numbery>>values;
        if(arr[make_pair(numberx,numbery)]!=0)arr[make_pair(numberx,numbery)]=min(arr[make_pair(numberx,numbery)],values);
        else arr[make_pair(numberx,numbery)]=values;
    }

}
void printf_arr(int vertical)
{
    for(int i=1; i<=vertical; i++)
    {
        if(values_arr[i]==10e17)cout<<"oo\t";
        else if(bool_arr[i])cout<<"chu trình âm\t";
        else cout<<values_arr[i]<<"\t";
    }
    cout<<endl<<"--------------------------------------------------------"<<endl;
}
void Bellman_Flord(int vertical)
{
    map<pair<int,int>, long long>::iterator it;
    bool check=1;
    for(int i=1; i<vertical; i++)
    {
        check=1;
        for(it=arr.begin();it!=arr.end();it++)
        {
            if(values_arr[it->first.first]+it->second<values_arr[it->first.second])
            {
                values_arr[it->first.second]=values_arr[it->first.first]+it->second;
                check=0;
            }
        }
        if(check)return;
    }
    for(it=arr.begin();it!=arr.end();it++)
    {
        if(values_arr[it->first.first]+it->second<values_arr[it->first.second])
        {
            values_arr[it->first.second]=values_arr[it->first.first]+it->second;
            bool_arr[it->first.second]=1;
        }
    }
}
main()
{

    int vertical,edge,verticalx,verticaly;
    input_file(vertical, verticalx,verticaly);
    Bellman_Flord(vertical);
    if(values_arr[verticaly]==10e17)cout<<"khong ton tai duong di tu dinh "<<verticalx<<" sang dinh "<<verticaly;
    else if(bool_arr[verticaly])cout<<"có chu trình âm\t";
    else cout<<"duong di ngan nhat tu dinh "<<verticalx<<" sang dinh "<<verticaly<<" la: "<<values_arr[verticaly];

}
