package college.threads;

class Stack{
    int [] arr;
    int stackTop;

    public Stack(int capacity) {
        this.arr = new int[capacity];
        this.stackTop = -1;
    }

    boolean isEmpty(){
        return stackTop == -1;
    }
    boolean isFull(){
        return stackTop == this.arr.length;
    }

    synchronized boolean push(int data){
        if(isFull()){
            return false;
        }
        stackTop++;
        try{Thread.sleep(100);} catch (Exception ignored){}    
        arr[stackTop] = data;
        return true;
    }

    synchronized boolean pop(){
        if(isEmpty()) {
            return false;
        }
        stackTop--;
        try{Thread.sleep(100);} catch (Exception ignored){}
        return true;
    }
}

public class SynchronizedExample {
    public static void main(String[] args) {
        System.out.println("Main started");
        Stack st = new Stack(10);

        new Thread(()->{
            for(int i = 0; i < 10; i++){
                System.out.println("Push " + st.push(i));
            }
        }).start();

        new Thread(()->{
            for(int i = 0; i < 10; i++){
                System.out.println("Pop " + st.pop());
            }
        }).start();

        System.out.println("Main ended");
    }
}
