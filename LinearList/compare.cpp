#include"SqList.h"
#include<bits/stdc++.h>
template<class ElemType>
void Difference(const SqList<ElemType>&la,const SqList<ElemType>&lb, SqList<ElemType>&lc){
    ElemType aElem,bElem;
    lc.Clear();
    for(int aPos=1;aPos<=la.Length();aPos++){
        la.GetElem(aPos,aElem);
        bool isExist=false;
        for(int bPos=1;bPos<=lb.Length();bPos++){
            lb.GetElem(bPos,bElem);
            if(aElem==bElem){
                isExist=true;
                break;
            }
        }
        if(!isExist)
        {
            lc.Insert(lc.Length()+1,aElem);
        }
    }
}
int main() {
    // 创建三个顺序表
    SqList<int> la(5);
    SqList<int> lb(5);
    SqList<int> lc(5);

    // 测试 Insert 函数
    la.Insert(1, 1);
    la.Insert(2, 2);
    la.Insert(3, 3);
    la.Insert(4, 4);
    la.Insert(5, 5);

    lb.Insert(1, 2);
    lb.Insert(2, 3);
    lb.Insert(3, 4);
    lb.Insert(4, 5);
    lb.Insert(5, 6);
    Difference(la, lb, lc);
    //遍历lc
    for(int i=1;i<=lc.Length();i++){
        int temp;
        lc.GetElem(i,temp);
        cout<<temp<<" ";
    }
    cout<<endl;
    return 0;
}
