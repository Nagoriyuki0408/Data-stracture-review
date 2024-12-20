#ifndef LINEARLIST_1_H
#define LINEARLIST_1_H
#include<bits/stdc++.h>
using namespace std;
template<class ElemType>
class Sqlist{
protected:
    ElemType *elems;
    int maxSize;
    int count;
public:

Sqlist(int size){
    maxSize=size;
    elems=new ElemType[maxSize];
    count=0;
}

~Sqlist(){
    delete[]elems;
}

int Length() const{
    return count;
}

bool Empty() const{
    return count==0;
}

void Clear(){
    count=0;
}

void Traverse(void(*visit)(const ElemType &)) const{
    for(int i=1;i<=count;i++)
    {
        (*visit)(elems[i-1]);
    }
}

bool GetElem(int position,ElemType &e) const{
    {
        if(position<1 || position>count)
        {
            return false;
        }
        else {
            e=elems[position-1];
            return true;
        }
}

bool SetElem(int position,const ElemType &e)
{
    if(position<1 || position>count)    
    {
        return false;
    }
    else
    {
        elems[position-1]=e;
        return true;
    }
}

bool Delete(int position,const ElemType&e){
if(position<1 || position>count)
{
    return false;
}
else{
    GetElem(position,e);
    ElemType temElem;
    for(int i=position+1;i<=count;i++)
    {
        GetElem(i,temElem);
        SetElem(i-1,temElem);
    }
    count--;
    return true;
}
}

bool Insert(int position,const ElemType &e)
{
    if(count==maxSize){
        return false;
    }
    else{
        ElemType temElem;
        for(int i=Length();i>=position;i--){
            getElem(i,temElem);
            setElem(i+1,temElem);
        }
        setElem(position,e);
        count++;
        return true;
    }
}

Sqlist(const Sqlist<ElemType>&source){
    maxSize=source.maxSize;
    count=source.count;
    elems=new ElemType[maxSize];
    for(int i=0;i<count;i++){
        elems[i]=source.elems[i];
    }
}

Sqlist<ElemType>&operator=(const Sqlist<ElemType>& source){
    if(this!=*source)
    {
        maxSize=source.maxSize;
        count=source.count;
        delete[]elems;
        elems=new ElemType[maxSize];
        for(int tempos=1;tempos<=source.Length();tempos++){
            elems[tempos-1]=source.elems[tempos-1];
        }
    }

    return *this;
};

#endif