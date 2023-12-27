#include <iostream>
using namespace std;

class NQueue{
    private:
        int size;
        int numberOfQueues;
        int freeSpot;
        int *arr;
        int *front;
        int *rear;
        int *next;

    public:
        NQueue(int size, int numberOfQueues){
            this->size = size;
            this->numberOfQueues = numberOfQueues;

            front = new int[numberOfQueues];
            rear = new int[numberOfQueues];
            for(int i = 0; i < numberOfQueues; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            arr = new int[size];
            next = new int[size];
            for(int i = 0; i < size; i++){
                next[i] = i+1;
            }
            next[size-1] = -1;

            freeSpot = 0;
        }

        bool enqueue(int data, int qn){
            if(freeSpot == -1){
                //queue is full
                return false;
            }

            int index = freeSpot;
            freeSpot = next[index];

            if(front[qn-1] == -1){
                //inserting first element
                front[qn-1] = index;
            }else{
                next[rear[qn-1]] = index;
            }

            next[index] = -1;
            rear[qn-1] = index;
            arr[index] = data;
            return true;
        }

        int dequeue(int qn){
            if(front[qn-1] == -1){
                //queue is empty
                return -1;
            }

            int index = front[qn-1];
            front[qn-1] = next[index];
            next[index] = freeSpot;
            freeSpot = index;

            return arr[index];
        }

};

int main() {

    NQueue q(5, 3);

    q.enqueue(2, 1);
    q.enqueue(3, 1);
    q.enqueue(4, 2);
    q.enqueue(5, 1);
    q.enqueue(6, 2);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;
    
    return 0;
}