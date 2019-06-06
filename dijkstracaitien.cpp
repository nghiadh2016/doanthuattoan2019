#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<fstream>
using namespace std;
map<int,long long>* arr;
long long* values_arr;
multiset<pair<long long,int> >multiset_values;
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
    for(int i=1; i<=vertical; i++)
    {
        if(i!=verticalx)multiset_values.insert(make_pair<long long, int>(10e17,i));
    }
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
    set<pair<long long,int> >::iterator iit;
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
                    iit=multiset_values.find(make_pair(values_arr[it->first],it->first));
                    multiset_values.erase(iit);
                    values_arr[it->first]=values+it->second;
                    multiset_values.insert(make_pair(values_arr[it->first],it->first));
                }
            }
        }
        iit=multiset_values.begin();
        if(iit==multiset_values.end())return;
        else
        {
            verticalx=iit->second;
            values=iit->first;
            bool_arr[verticalx]=1;
            multiset_values.erase(iit);
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
