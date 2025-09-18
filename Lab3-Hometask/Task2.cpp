#include<iostream>

using namespace std;

class ShoppingCart{
public:
    string itemName;
    int price;
    ShoppingCart* next;
    ShoppingCart(string name, int pric){
        itemName=name;
        price=pric;
        next=nullptr;
    }
};

void addFront(ShoppingCart* &head,ShoppingCart* &tail,string item,int price){
    ShoppingCart* temp=new ShoppingCart(item,price);
    if(head==nullptr){
        head=tail=temp;
        return;
    }
    temp->next=head;
    head=temp;
}

void addEnd(ShoppingCart* &head,ShoppingCart* &tail,string item,int price){
    ShoppingCart* newCart=new ShoppingCart(item,price);
    if(tail==nullptr){
        head=tail=newCart;
        return;
    }
    tail->next=newCart;
    tail=newCart;
}

void addAtPos(ShoppingCart* &head,ShoppingCart* &tail,int pos,string item,int price){
    if(pos==1){
        addFront(head,tail,item,price);
        return;
    }
    int count=1;
    ShoppingCart* temp=head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==nullptr){
        addEnd(head,tail,item,price);
        return;
    }
    ShoppingCart* newCart=new ShoppingCart(item,price);
    newCart->next=temp->next;
    temp->next=newCart;
}

void findByName(ShoppingCart* &head,string name){
    ShoppingCart* temp=head;
    int pos=1;
    while(temp!=nullptr){
        if(temp->itemName==name){
            cout<<"Item found at position: "<<pos<<endl<<"Item name: "<<temp->itemName<<" Item Price: "<<temp->price<<endl;
            return;
        }
        pos++;
        temp=temp->next;
    }
    cout<<"Item named: "<<name<<" is not found in the list."<<endl;
}

void findByPos(ShoppingCart* head,int pos){
    if(pos<=0){
        cout<<"Invalid position!"<<endl;
        return;
    }
    ShoppingCart* temp=head;
    int count=1;
    while(temp!=nullptr && count<pos){
        temp=temp->next;
        count++;
    }
    if(temp==nullptr){
        cout<<"Position out of range!"<<endl;
    }
    else{
        cout<<"Item at position "<<pos<<": "<<temp->itemName<<" - $"<<temp->price<<endl;
    }
}

void removeFront(ShoppingCart* &head,ShoppingCart* &tail){
    if(head==nullptr){
        return;
    }
    ShoppingCart* temp=head;
    head=head->next;
    if(head==nullptr){
        tail=nullptr;
    }
    delete temp;
}

void showCart(ShoppingCart* &head){
    ShoppingCart* temp=head;
    while(temp!=nullptr){
        cout<<temp->itemName<<"- $"<<temp->price<<"->";
        temp=temp->next;
    }
    cout<<"Null"<<endl;
}

int main(){
    ShoppingCart* head=nullptr;
    ShoppingCart* tail=nullptr;
    addFront(head,tail,"headPhone",10);
    addFront(head,tail,"tablet",400);
    addFront(head,tail,"Phone",700);
    addFront(head,tail,"Laptop",1000);
    addFront(head,tail,"SmartWatch",200);
    addEnd(head,tail,"Keyboard",80);
    addAtPos(head,tail,4,"Monitor",300);
    findByName(head,"tablet");
    cout<<endl<<"Complete shopping cart: "<<endl;
    showCart(head);
    cout<<"Deleting item from front: "<<endl;
    removeFront(head,tail);
    showCart(head);
    findByPos(head,3);
}
