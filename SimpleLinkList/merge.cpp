#include"SimpleLinkList.h"
#include<bits/stdc++.h>
using namespace std;
template<class T>
void merge(const SimpleLinkList<T>& la,const SimpleLinkList<T>& lb,SimpleLinkList<T>& lc){
    lc.Clear();
    T aT,bT;
    int aLength=la.Length(),bLength=lb.Length();
    int aPos=1,bPos=1;
    la.GetElem(aPos,aT);
    lb.GetElem(bPos,bT);
    while(aPos<=aLength&&bPos<=bLength){
        if(aT<=bT){
            lc.Insert(lc.Length()+1,aT);
            aPos++;
        }
        else{
            lc.Insert(lc.Length()+1,bT);
            bPos++;
        }
    }
    while(aPos<=aLength){
        lc.Insert(lc.Length()+1,aT);
        aPos++;
    }
    while(bPos<=bLength){
        lc.Insert(lc.Length()+1,bT);
        bPos++;
    }
}
