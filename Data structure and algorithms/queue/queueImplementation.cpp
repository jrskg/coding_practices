#include <iostream>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int qFront;
        int rear;

    public:
        Queue(int size){
            this->size = size;
            this->arr = new int[size];
            this->rear = 0;
            this->qFront = 0;
        }

        ~Queue() {
            delete[] arr;
        }

        void enqueue(int data){
            if(rear == size){
                cout<<"Queue is full"<<endl;
                return;
            }
            arr[rear] = data;
            rear++;
        }

        int dequeue(){
            if(rear == qFront){
                return -1;
            }
            int ans = arr[qFront];
            arr[qFront] = -1;
            qFront++;

            if(qFront == rear){
                qFront = 0;
                rear = 0;
            }
            return ans;
        }

        bool empty(){
            return qFront == rear;
        }

        bool full(){
            return rear == size;
        }

        int front(){
            if(qFront == rear){
                return -1;
            }
            return arr[qFront];
        }
};

class CircularQueue{
    private:
        int * arr;
        int size;
        int front;
        int rear;

    public:
        CircularQueue(int size){
            this->size = size;
            this->arr = new int[size];
            this->front = -1;
            this->rear = -1;
        }

        ~CircularQueue(){
            delete[] arr;
        }

        void enqueue(int data){
            if((front == 0 && rear == size-1) || (rear == front-1)){
                cout<<"Queue is full"<<endl;
                return;
            }

            if(front == -1){
                front = rear = 0;
            }else if(rear == size-1 && front != 0){
                rear = 0;
            }else{
                rear++;
            }

            arr[rear] = data;
        }

        int dequeue(){
            if(front == -1){
                return -1;
            }

            int ans = arr[front];
            arr[front] = -1;

            if(front == rear){
                front = rear = -1;
            }else if(front == size-1){
                front = 0;
            }else{
                front++;
            }
            return ans;
        }
};

class Deque{
    private:
        int * arr;
        int front;
        int rear;
        int size;

    public:
        Deque(int n){
            size = n;
            arr = new int[n];
            front = -1;
            rear = -1;
        }

        bool empty(){
            return front == -1;
        }

        bool full(){
            return ((front == 0 && rear == size-1) || (rear == front - 1));
        }

        bool push_front(int data){
            if(full()){
                return false;
            }

            if(front == -1){
                front = rear = 0;
            }else if(front == 0){
                front = size-1;
            }else{
                front--;
            }

            arr[front] = data;
            return true;
        }

        int pop_front(){
            if(empty()){
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1;

            if(front == rear){
                front = rear = -1;
            }else if(front == size-1){
                front = 0;
            }else{
                front++;
            }
            return ans;
        }

        bool push_back(int data){
            if(full()){
                return false;
            }

            if(rear == -1){
                front = rear = 0;
            }else if(rear == size-1 && front != 0){
                rear = 0;
            }else{
                rear++;
            }
            arr[rear] = data;
            return true;
        }

        int pop_back(){
            if(empty()){
                return -1;
            }

            int ans = arr[rear];
            arr[rear] = -1;

            if(front == rear){
                front = rear = -1;
            }else if(rear == 0){
                rear = size-1;
            }else{
                rear--;
            }
            return ans;
        }

        int front_element(){
            if(empty()){
                return -1;
            }
            return arr[front];
        }

        int rear_element(){
            if(empty()){
                return -1;
            }
            return arr[rear];
        }
};

int main() {

    // Queue q = Queue(10);

    // cout<<q.empty()<<endl;
    // cout<<q.full()<<endl;
    // cout<<q.front()<<endl;

    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);
    // q.enqueue(6);

    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;
    // cout<<q.dequeue()<<endl;

    // cout<<q.empty()<<endl;
    // cout<<q.full()<<endl;
    // cout<<q.front()<<endl;


    Deque d = Deque(10);

    d.push_front(1);
    // d.push_front(2);
    // d.push_front(3);
    // d.push_back(12);
    // d.pop_front();
    d.pop_back();
    
    cout<<d.front_element()<<endl;
    cout<<d.rear_element()<<endl;
    
    return 0;
}