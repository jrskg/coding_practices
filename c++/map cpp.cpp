#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<string, int>marksMap;
    marksMap["Suraj"] = 98;
    marksMap["Manish"] = 99;
    marksMap["Sagar"] = 89;
    marksMap["Arun"] = 50;

    marksMap.insert({{"Subham", 78}, {"Ramesh", 79}});

    map<string, int> :: iterator iter;
    for(iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout<<(*iter).first<<" = "<<(*iter).second<<"\n";
    }
    cout<<"The max size is "<<marksMap.max_size()<<endl;

    return 0;
}