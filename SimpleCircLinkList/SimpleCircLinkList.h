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
class SimpleCircLinkList {
private:
    Node<T>* head;
    Node<T>* GetElemPtr(int position) const;
public:
    SimpleCircLinkList();
    virtual~SimpleCircLinkList();
    int Length() const;
    bool Empty() const;
    void Clear();
    void Traverse(void(*visit)(const T&))const;
    bool GetElem(int position,T& e) const;
    bool SetElem(int position,const T& e);
    bool Delete(int position,const T& e);
    bool Delete(int position);
    bool Insert(int position,const T& e);
    SimpleCircLinkList<T>& operator=(const SimpleCircLinkList<T>& source);
    SimpleCircLinkList(const SimpleCircLinkList<T>& source);
};

template<class T>
Node<T>* SimpleCircLinkList<T>::GetElemPtr(int position) const {
    if(position==0) return head;
    Node<T>* temPtr=head->next;
    int temPos=1;
    while(temPos<position && temPtr!=nullptr){
        temPtr=temPtr->next;
        temPos++;
    }
    if(temPos==position&&temPtr!=head) return temPtr;
    else return nullptr;
}

template<class T>
SimpleCircLinkList<T>::SimpleCircLinkList(){
    head=new Node<T>;
}

template<class T>
SimpleCircLinkList<T>::~SimpleCircLinkList(){
    Clear();
    delete head;
}

template<class T>
int SimpleCircLinkList<T>::Length() const{
    int len=0;
    for(Node<T>* temPtr=head->next;temPtr!=head;temPtr=temPtr->next){
        len++;
    }
    return len;
}

template<class T>
bool SimpleCircLinkList<T>::Empty() const{
    return head->next==head;
}

template<class T>
void SimpleCircLinkList<T>::Clear(){
    while(!Empty()){
        Delete(1);
    }
}

template<class T>
void SimpleCircLinkList<T>::Traverse(void(*visit)(const T&))const{
    for(Node<T>* temPtr=head->next;temPtr!=head;temPtr=temPtr->next){
        (*visit)(temPtr->data);
    }
}

template<class T>
bool SimpleCircLinkList<T>::GetElem(int position,T& e) const{
    if(position<1 || position>Length()) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position);
        e=temPtr->data;
        return true;
    }
}

template<class T>
bool SimpleCircLinkList<T>::SetElem(int position,const T& e){
    if(position<1 || position>Length()) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position);
        temPtr->data=e;
        return true;
    }
}

template<class T>
bool SimpleCircLinkList<T>::Delete(int position,const T& e){
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
bool SimpleCircLinkList<T>::Insert(int position,const T& e){
    if(position<1 || position>Length()+1) return false;
    else {
        Node<T>* temPtr=GetElemPtr(position-1);
        Node<T>* newNode=new Node<T>(e,temPtr->next);
        temPtr->next=newNode;
        return true;
    }
}
