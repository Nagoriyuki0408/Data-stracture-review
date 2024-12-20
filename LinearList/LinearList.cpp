#include<iostream>
using namespace std;
template<typename ElemType>
class Sqlist{
    protected:
    ElemType *elems;
    int maxSize;
    int count;
    public:
    Sqlist(int size=DEFAULT_SIZE);//构造函数模板
    virtual ~Sqlist();//析构函数模板
    int Length() const;//求线性表的长度
    bool Empty() const;//判断线性表是否为空
    void Clear() ;//将线性表清空
    void Traverse(void(*visit)(const ElemType &)) const;//遍历线性表
    bool GetElem(void(*visit)(const ElemType &)) const;//求指定位置的元素
    bool SetElem(int position,const ElemType &e);//设置指定位置的元素的值
    bool Delete(int position),ElemType &e);//删除元素
    bool Delete(int position,const ElemType &e);//删除元素
    bool Insert(int position,const ElemType &e);//插入元素
    Sqlist(const Sqlist<ElemType>&source);//拷贝构造函数模板
    Sqlist<ElemType>&operator=(const Sqlist<ElemType>& source);//重载复制运算符
    private:
};

template<typename ElemType>
Sqlist<ElemType>::Sqlist(int size){
    maxSize=size;
    elems=new ElemType[maxSize];
    count=0;
}

template<typename ElemType>
Sqlist<ElemType>::~Sqlist(){
    delete[]elems;
}

template<typename ElemType>
int Sqlist<ElemType>::Length() const{
    return count;
}

template<typename ElemType>
bool Sqlist<ElemType>::Empty() const{
    return count==0;
}

template<typename ElemType>
void Sqlist<ElemType>::Clear(){
    count=0;
}

template<typename ElemType>
void Sqlist<ElemType>::Traverse(void(*visit)(const ElemType &)) const{
    for(int i=1;i<count;i++)
    {
        (*visit)(elems[i-1]);
    }
}

template<typename ElemType>
bool Sqlist<ElemType>::GetElem(int position,ElemType &e) const{
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

template<class ElemType>
bool Sqlist<ElemType>::SetElem(int position,const ElemType &e){
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
}

template<typename ElemType>
bool Sqlist<ElemType>::Delete(int position){
if(position<1 || position>count)
{
    return false;
}
else{
    GetElem(position,e);
    ElemType temElem;
    for(int i=position+1;i<=count;i++)
    {
        Getelem(i,temElem);
        SetElem(i-1,temElem);
    }
    count--;
    return true;
}
}

template<typename ElemType>
bool Sqlist<ElemType>::Insert(int position,const ElemType &e)
{
    if(count==maxSize){
        return false;
    }
    else{
        ElemType temElem;
        for(int i=Length();temPos>=position;i--){
            getElem(i,temElem);
            setElem(i+1,temElem);
        }
        setElem(position,e);
        count++;
        return true;
    }
}

template<typename ElemType>
Sqlist<ElemType>::Delete(int position){
    if(position<1 || position>count){
        return false;
    }
    else{
        ElemType temElem;
        for(int i=position-1;i<=count;i++){
            SetElem(i-1,temElem);
        }
        count--;
        return true;
    }
}

template<typename ElemType>
Sqlist<ElemType>::Sqlist(const Sqlist<ElemType>&source){
    maxSize=source.maxSize;
    count=source.count;
    elems=new ElemType[maxSize];
    for(int i=0;i<count;i++){
        elems[i]=source.elems[i];
    }
}

template<class ElemType>
Sqlist<ElemType>&Sqlist<elemType>::operator=(const Sqlist<ElemType>& source){
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
}