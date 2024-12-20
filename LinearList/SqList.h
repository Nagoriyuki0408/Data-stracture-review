#include<iostream>
const int DEFAULT_SIZE = 10;
using namespace std;
template<class ElemType>
class SqList{
    protected:
    ElemType *elems;
    int maxSize;
    int count;
    public:
    SqList(int size=DEFAULT_SIZE);//���캯��ģ��
    virtual ~SqList();//��������ģ��
    int Length() const;//�����Ա�ĳ���
    bool Empty() const;//�ж����Ա��Ƿ�Ϊ��
    void Clear() ;//�����Ա����
    void Traverse(void(*visit)(const ElemType &)) const;//�������Ա�
    bool GetElem(int position, ElemType &e) const;//��ָ��λ�õ�Ԫ��
    bool SetElem(int position,const ElemType &e);//����ָ��λ�õ�Ԫ�ص�ֵ
    bool Delete(int position);//ɾ��Ԫ��
    bool Delete(int position,const ElemType &e);//ɾ��Ԫ��
    bool Insert(int position,const ElemType &e);//����Ԫ��
    SqList(const SqList<ElemType>&source);//�������캯��ģ��
    SqList<ElemType>&operator=(const SqList<ElemType>& source);//���ظ��������
};

template<class ElemType>
SqList<ElemType>::SqList(int size){
    maxSize=size;
    elems=new ElemType[maxSize];
    count=0;
}

template<class ElemType>
SqList<ElemType>::~SqList(){
    delete[]elems;
}

template<class ElemType>
int SqList<ElemType>::Length() const{
    return count;
}

template<class ElemType>
bool SqList<ElemType>::Empty() const{
    return count==0;
}

template<class ElemType>
void SqList<ElemType>::Clear(){
    count=0;
}

template<class ElemType>
void SqList<ElemType>::Traverse(void(*visit)(const ElemType &)) const{
    for(int i=1;i<=count;i++)
    {
        (*visit)(elems[i-1]);
    }
}

template<class ElemType>
bool SqList<ElemType>::GetElem(int position,ElemType &e) const{
    {
        if(position<1 || position>Length())
        {
            return false;
        }
        else {
            e=elems[position-1];
            return true;
        }
}
}

template<class ElemType>
bool SqList<ElemType>::SetElem(int position,const ElemType &e){
    if(position<1 || position>Length())    
    {
        return false;
    }
    else
    {
        elems[position-1]=e;
        return true;
    }
    }

template<class ElemType>
bool SqList<ElemType>::Delete(int position,const ElemType &e){
if(position<1 || position>Length())
{
    return false;
}
else{
    GetElem(position,e);
    ElemType temElem;
    for(int i=position+1;i<=Length();i++)
    {
        Getelem(i,temElem);
        SetElem(i-1,temElem);
    }
    count--;
    return true;
}
}

template<class ElemType>
bool SqList<ElemType>::Insert(int position,const ElemType &e)
{
    if(count==maxSize){
        return false;
    }
    else if(position<1 || position>Length()+1){
        return false;
    }
    else{
        ElemType temElem;
        for(int i=Length();i>=position;i--){
            GetElem(i,temElem);
            SetElem(i+1,temElem);
        }
        SetElem(position,e);
        count++;
        return true;
    }
}

template<class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>&source){
    maxSize=source.maxSize;
    count=source.count;
    elems=new ElemType[maxSize];
    for(int i=0;i<count;i++){
        elems[i]=source.elems[i];
    }
}

template<class ElemType>
SqList<ElemType>&SqList<ElemType>::operator=(const SqList<ElemType>& source){
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