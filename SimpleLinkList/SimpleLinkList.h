template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node();
    Node(const T& e,Node<T>* n=nullptr);
};

template<class T>
Node<T>::Node(){
    next=nullptr;
}

template<class T>
Node<T>::Node(const T& e,Node<T>* link){
    data=e;
    next=link;
}

template<class T>
class SimpleLinkList {
private:
    Node<T>* head;
    Node<T>* GetElemPtr(int position) const;
public:
    SimpleLinkList();
    virtual~SimpleLinkList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void(*visit)(const T&))const;
    bool GetElem(int position,T& e) const;
    bool SetElem(int position,const T& e);
    bool Delete(int position,const T& e);
    bool Delete(int position);
    bool Insert(int position,const T& e);
    SimpleLinkList<T>& operator=(const SimpleLinkList<T>& source);
    SimpleLinkList(const SimpleLinkList<T>& source);
};

template<class T>
Node<T>* SimpleLinkList<T>::GetElemPtr(int position) const {
    Node<T>* temPtr=head;
    int temPos=0;
    while(temPtr != nullptr && temPos< position){
        temPtr=temPtr->next;
        temPos++;
    }
    if(temPos==position&&temPtr!=nullptr)
    return temPtr;
    else return nullptr;
}

template<class T>
SimpleLinkList<T>::SimpleLinkList(){
    head=new Node<T>;
}

template<class T>
SimpleLinkList<T>::~SimpleLinkList(){
    Clear();
    delete head;
}

template<class T>
int SimpleLinkList<T>::Length() const{
    int len=0;
    Node<T>* temPtr=head->next;
    while(temPtr!=nullptr){
        len++;
        temPtr=temPtr->next;
    }
    return len;
}

template<class T>
bool SimpleLinkList<T>::Empty() const{
    return head->next==nullptr;
}

template<class T>
void SimpleLinkList<T>::Clear(){
    while(!Empty()){
        Delete(1);
    }
}

template<class T>
void SimpleLinkList<T>::Traverse(void(*visit)(const T&))const{
    for(Node<T>* temPtr=head->next;temPtr!=nullptr;temPtr=temPtr->next){
        (*visit)(temPtr->data);
    }
}

template<class T>
bool SimpleLinkList<T>::GetElem(int position,T& e) const{
    if(position<1 || position>Length()) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position);
        e=temPtr->data;
        return true;
    }
}

template<class T>
bool SimpleLinkList<T>::SetElem(int position,const T& e){
    if(position<1 || position>Length()) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position);
        temPtr->data=e;
        return true;
    }
}

template<class T>
bool SimpleLinkList<T>::Delete(int position,const T& e){
    if(position<1 || position>Length()) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position-1);
        Node<T>* nextPtr=temPtr->next;
        temPtr->next=nextPtr->next;
        delete nextPtr;
        return true;
    }
}

template<class T>
bool SimpleLinkList<T>::Insert(int position,const T& e){
    if(position<1 || position>Length()+1) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position-1);
        Node<T>* newNode=new Node<T>(e,temPtr->next);
        temPtr->next=newNode;
        return true;
    }
}
