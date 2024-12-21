#include<bits/stdc++.h>
#include"SimpleCircLinkList.h"
using namespace std;
void Josephus(int n,int m){
    SimpleCircLinkList<int> la;
    int Pos=0;
    int out,winner;
    for(int i=1;i<n;i++) la.Insert(i,i);
    cout<<"出列";
    for(int i=1;i<n;i++){
        for(int j=1;j<=m;j++){
            Pos++;
            if(Pos>la.Length())
                Pos=1;
            la.Delete(Pos--,out);
            cout<<out<<" ";
        }
    }
    la.GetElem(1,winner);
    cout<<"\n胜利者:"<<winner<<endl;
}
