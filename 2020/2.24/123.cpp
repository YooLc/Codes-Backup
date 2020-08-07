#include<iostream>
#include<iterator>
#include<map>
using namespace std;
 
int main()
{
   map <int,int> test;
   test[0]=0;
   test[1]=1;
   test[2]=2;
   map<int,int>::iterator iter = test.begin();
   while(iter != test.end())
   {
        (int&)(iter->first) = iter->first+10;//gcc能过，vc木有试，但最好不要修改key
        iter++;
   }
   iter = test.begin();
   while(iter != test.end())
   {
        cout<<iter->first<<endl;
        iter++;
   }
 
}