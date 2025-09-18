#include<iostream>

using namespace std;

class CartItems{
public:
    int id;
    string itemName;
    int price;
    CartItems* prev;
    CartItems* next;
    CartItems(int iD,string name,int pric){
        id=iD;
        itemName=name;
        price=pric;
        prev=nullptr;
        next=nullptr;
    }
};

void addHead(CartItems* &head,int id,string name,int price){
    if(head==nullptr){
        CartItems* temp=new CartItems(id,name,price);
        head=temp;
    }
    else{
        CartItems* temp=new CartItems(id,name,price);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}

void addTail(CartItems* &head,int id,string name,int price){
    if(head==nullptr){
        CartItems* temp=new CartItems(id,name,price);
        head=temp;
    }
    else{
        CartItems* newItem=new CartItems(id,name,price);
        CartItems* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=newItem;
        newItem->prev=temp;
    }
}

void removeHead(CartItems* &head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else{
        CartItems* temp=head;
        head=head->next;
        if(head!=nullptr){
            head->prev=nullptr;
        }
        temp->next=nullptr;
        delete temp;
    }
}

void removeTail(CartItems* &head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    else if(head->next==nullptr){
        delete head;
        head=nullptr;
        return;
    }
    else{
        CartItems* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->prev->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
}

void findByID(CartItems* &head,int id){
    CartItems* temp=head;
    while(temp!=nullptr){
        if(temp->id==id){
            cout<<"ID: "<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No item by this ID is found "<<endl;
}

void changePrice(CartItems* &head,int id,int newPrice){
    CartItems* temp=head;
    while(temp!=nullptr){
        if(temp->id==id){
            temp->price=newPrice;
            cout<<"Price updated"<<endl;
            cout<<"New price: "<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"No item by this ID is found "<<endl;
}

void showForward(CartItems* head){
    if(head==nullptr){
        cout<<"Cart is empty"<<endl;
        return;
    }
    CartItems* temp=head;
    while(temp!=nullptr){
        cout<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<"$";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

void showBackward(CartItems* head){
    if(head==nullptr){
        cout<<"Cart is empty"<<endl;
        return;
    }
    CartItems* temp=head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    while(temp!=nullptr){
        cout<<temp->id<<"-"<<temp->itemName<<"-"<<temp->price<<"$";
        temp=temp->prev;
    }
    cout<<"NULL"<<endl;
}

int countItems(CartItems* &head){
    if(head==nullptr){
        return 0;
    }
    CartItems* temp=head;
    int count=0;
    while(temp!=nullptr){
        temp=temp->next;
        count++;
    }
    return count;
}

void maxPriceItem(CartItems* &head){
    if(head==nullptr){
        cout<<"No items are there"<<endl;
        return;
    }
    else{
        CartItems* temp=head;
        CartItems* expensive=head;
        while(temp!=nullptr){
            if(temp->price>expensive->price){
                expensive=temp;
            }
            temp=temp->next;
        }
        cout<<"Most expensive item: "<<expensive->id<<"-"<<expensive->itemName<<"-"<<expensive->price<<endl;
    }
}

int main(){
    CartItems* head=nullptr;
    cout<<"Inserting at head: "<<endl;
    addHead(head,01,"Bread",30);
    addHead(head,06,"Butter",7);
    showForward(head);
    cout<<"Inserting at end: "<<endl;
    addTail(head,02,"Choclate",10);
    addTail(head,07,"Cake",30);
    showForward(head);
    cout<<"Removing first and last item: "<<endl;
    removeHead(head);
    removeTail(head);
    showForward(head);
    findByID(head,02);
    changePrice(head,02,20);
    cout<<"Cart from end to front: "<<endl;
    showBackward(head);
    cout<<"Total Items in Cart are: "<<countItems(head)<<endl;
    cout<<"Most expensive item is: "<<endl;
    maxPriceItem(head);
}
