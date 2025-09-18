#include<iostream>

using namespace std;

class ShoppingCart{
public:
    string itemName;
    int price;
    ShoppingCart* next;
    ShoppingCart(string name, int p){
        itemName=name;
        price=p;
        next=nullptr;
    }
};

void addFront(ShoppingCart* &head, string item, int price){
    ShoppingCart* temp=new ShoppingCart(item,price);
    temp->next=head;
    head=temp;
}

void addEnd(ShoppingCart* &head, string item, int price){
    ShoppingCart* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    ShoppingCart* newCart= new ShoppingCart(item,price);
    temp->next=newCart;
    newCart->next=nullptr;
}

void addAtPos(ShoppingCart* &head, int pos, string item, int price){
    if(pos==1){
        addFront(head,item,price);
        return;
    }
    int count=1;
    ShoppingCart* temp=head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp->next==nullptr){
        addEnd(head,item,price);
        return;
    }
    ShoppingCart* newCart=new ShoppingCart(item,price);
    newCart->next=temp->next;
    temp->next=newCart;
}

void findItem(ShoppingCart* &head, string name){
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
    addFront(head,"headPhone",10);
    addFront(head,"tablet",400);
    addFront(head,"Phone",700);
    addFront(head,"Laptop",1000);
    addFront(head,"SmartWatch",200);
    addEnd(head,"Keyboard",80);
    addAtPos(head,4,"Monitor",300);
    findItem(head,"tablet");
    cout<<endl<<"Complete shopping cart: "<<endl;
    showCart(head);
}
