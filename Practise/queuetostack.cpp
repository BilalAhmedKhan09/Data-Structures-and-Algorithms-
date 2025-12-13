#include<iostream>

using namespace std;

class queue{
    public:
        int arr[5];
        int front;
        int rear;
        int size;
        queue(){
            size = 0;
            front = 0;
            rear = -1;
        }
        void enqueue(int val){
            if(size == 5){
                cout<<"queue is full"<<endl;
                return;
            }
            else{
                rear++;
                arr[rear] = val;
                size++;
            }
        }
        void dequeue(){
            if(size == 0){
                cout<<"Empty queue"<<endl;
                return;
            }
            else{
                front++;
                size--;
            }
        }
        int peek(){
            return arr[front];
        }
};

int queuesTostack(queue &q1){
    queue q2;
    while(q1.size > 1){
        int top = q1.peek();
        q1.dequeue();
        q2.enqueue(top);
    }
    int top = q1.peek();
    q1.dequeue();
    swap(q1,q2);
    return top;
}

int main(){
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    int top = queuesTostack(q1);
    cout<<"Popped: "<<top<<endl;
    top = queuesTostack(q1);
    cout<<"Popped: "<<top<<endl;
    top = queuesTostack(q1);
    cout<<"Popped: "<<top<<endl;
    top = queuesTostack(q1);
    cout<<"Popped: "<<top<<endl;
    top = queuesTostack(q1);
    cout<<"Popped: "<<top<<endl;
}