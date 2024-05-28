package college.threads;

import java.util.LinkedList;
import java.util.Queue;

class MyRunnable implements Runnable{
    public void run(){
        for(int i = 0; i < 5; i++){
            System.out.println("BCA");
            try{
                Thread.sleep(1000);
            }catch (Exception ignored){}
        }
    }
}

class MyQueue{
    private Queue<Integer>q;
    private final int capacity;

    public MyQueue(int capacity){
        this.capacity = capacity;
        q = new LinkedList<>();
    }

    public synchronized boolean add(int data){
        while (q.size() == capacity){
            try {
                System.out.println("Waiting to add " + Thread.currentThread().getName());
                this.wait();
            }catch (InterruptedException ignored){}
        }
        System.out.println("Adding to queue " + Thread.currentThread().getName());
        q.add(data);
        this.notifyAll();
        return true;
    }

    public synchronized int remove(){
        while(q.isEmpty()){
            try {
                System.out.println("Waiting to remove " + Thread.currentThread().getName());
                this.wait();
            }catch (InterruptedException ignored){}
        }

        int element = q.poll();
        System.out.println("Removing from queue " + Thread.currentThread().getName());
        this.notifyAll();
        return element;
    }
}

public class RunnableExample {
    public static void main(String[] args) {
        MyQueue q = new MyQueue(5);
        q.add(10);
        q.add(20);
        q.add(30);
        q.add(40);
        q.add(50);
        Thread thread1 = new Thread(()->{
            System.out.println("The removed element : " + q.remove());
        }, "Thread-one");
        //thread1.start();

        Thread thread2 = new Thread(()->{
            q.add(10);
        }, "Thread-two");
        thread2.start();

        try{
            Thread.sleep(3000);
        }catch (Exception ignored){}

        thread1.start();
    }
}
