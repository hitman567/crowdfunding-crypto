

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<string>
#include <map>
#define ll long long
#include "TransactionData.h"
#include "Block.h"
#include "Blockchain.h"

using namespace std;

std::map<string, double> Company;
std::map<string, double> Users;

ll power(ll a, ll b, ll p)
    {
        ll res=1;
        a=a%p;
        while(b>0)
        {
            if(b&1)
            {
                res=(res*a)%p;
            }
            b= b>>1;
            a=(a*a)%p;
        }
        return res%p;
    }
bool mink(TransactionData data)
{  ll p= 1237;
   ll g= 11;
   ll r = 700;
   cout<<"Receiver Key  "<<data.receiverKey<<endl;
   cout<<"sender Key  "<<data.senderKey<<endl;
    string toHashs=to_string(data.amount)+data.receiverKey+data.senderKey+to_string(data.timestamp);
    hash<string> tDataHash;
    ll x=(size_t)(tDataHash(toHashs));
    ll h=power(g,r,p);
    ll b=1;
    ll s=(r+b*x)%(p-1);
    ll y=power(g,s,p);
    ll z = h*power(y,b,p);
    
    while(z!=y)
    {
        srand(time(0));
        b=rand()%2;
        s=(r+b*x)%(p-1);
        h=power(g,r,p);
        y=power(g,s,p);
        z= h*power(y,b,p);
        cout<<"calculating proof...     "<<endl;
//        cout<<"z= "<<z<<" y= "<<y<<endl;
    }

    return true;
}

void usertransaction(string s,Blockchain awesomeCoin)
{
    std::vector<Block> v=awesomeCoin.chain;
    for(auto i:v)
    {
        if(i.data.senderKey==s)
        {
            cout<<"   "<<i.data.senderKey<<endl;
            cout<<" Receiver  "<<i.data.receiverKey<<endl;
            cout<<"Amount  "<<i.data.amount<<endl;
        }
    }
}
int main()
{
    // Start Blockchain
    Blockchain awesomeCoin;
     Company["Apple"]= 15000 ;
     Company["Google"] = 20000;
    Users["John"]=1500;
Users["Vivek"] =5560000 ;
Users["Mukesh"] = 5500;
Users["Srijan"] = 9500;
Users["Ayush"] =   22500;
Users["Johnyy"] = 500;
cout<<"------------"<<endl;
cout<<"Initial data"<<endl;
cout<<"------------"<<endl;
 for (auto i:Users)
    {

    cout<<i.first<<"    $"<<i.second<<endl;


    }
     for (auto i:Company)
    {

    cout<<i.first<<"    $"<<i.second<<endl;


    }

int t = 1;
while(t)
{
    time_t data1Time;
     string k,f;
     int c;
    cout<<"Enter User name "<<endl;
    cin>>k;
    cout<<"Enter Amount "<<endl;
    cin>>c;
     cout<<"Enter Company "<<endl;
    cin>>f;
    for (auto i:Users)
    {
        if(i.first == k)
        {
            if(i.second >= c)
            {
                Users[i.first]-=c;
                for (auto j:Company)
                  {
                    if(j.first == f)
                   {
                        Company[j.first]-=c;
                        TransactionData data1(c, i.first,j.first, time(&data1Time));
                        awesomeCoin.addBlock(data1);
                        cout<<"******************"<<endl;
                        cout<<"Proof of work"<<endl;
                         cout<<mink(data1)<<endl;
                         cout<<"******************"<<endl;

                   }

                  }


            }
            else
            {
                cout<<"Error Amount!!";
            }
        }

    }
cout<<"--------------------"<<endl;
cout<<"--------------------"<<endl;
cout<<"     Updated Values "<<endl;
cout<<"--------------------"<<endl;
cout<<"--------------------"<<endl;

     for (auto i:Users)
    {

    cout<<i.first<<"    $"<<i.second<<endl;


    }
     for (auto i:Company)
    {

    cout<<i.first<<"    $"<<i.second<<endl;


    }
    cout<<"want to run again"<<endl;
    cin>>t;

}

    return 0;
}
