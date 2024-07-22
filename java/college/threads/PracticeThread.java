package college.threads;

class Counter{
    int count;
    public Counter(){
        this.count = 0;
    }

    public synchronized void increment(){
        System.out.println("Incrementing by " + Thread.currentThread().getName());
        this.count++;
        this.notifyAll();
    }

    public synchronized void decrement(){
        while(this.count == 0){
            try{
                System.out.println("Waiting to decrement " + Thread.currentThread().getName());
                this.wait();
            }catch (InterruptedException ignored){}
        }
        System.out.println("Decrementing by "+ Thread.currentThread().getName());
        this.count--;
    }

    public synchronized int getCount() {
        while(this.count == 0) {
            try {
                System.out.println("Waiting to get value " + Thread.currentThread().getName());
                this.wait();
            }catch (InterruptedException ignored){}
        }
        return this.count;
    }
}

public class PracticeThread {
    public static void main(String[] args) {
        Counter c = new Counter();
        Thread t1 = new Thread(() -> {
            for(int i = 0; i < 5; i++){
                System.out.println(c.getCount());
                c.decrement();
            }
        }, "T1");

        Thread t2 = new Thread(() -> {
            for(int i = 0; i < 5; i++){
                c.increment();
            }
        }, "T2");

        t1.start();
        t2.start();
    }
}
