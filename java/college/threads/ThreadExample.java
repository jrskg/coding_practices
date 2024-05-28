package college.threads;

class CustomThread extends Thread{
    public CustomThread(String tName){
        super(tName);
    }

    @Override
    public void run(){
        for(int i = 0; i < 5; i++){
            System.out.println("My thread " + this.getName() + " " + i);
        }
    }
}

class ThreadUsingRunnable implements Runnable{
    @Override
    public void run() {
        for(int i = 0; i < 5; i++){
            System.out.println("My thread " + Thread.currentThread().getName() + " " + i);
        }
    }
}

public class ThreadExample {
    public static void main(String[] args) {
        System.out.println("Main starting");
        CustomThread th = new CustomThread("Thread_skg");
        //th.setDaemon(true);
        th.start();

        //Thread th2 = new Thread(new ThreadUsingRunnable(), "Thread_skg2");

        //using lambda expressions
        Thread th2 = new Thread(() -> {
            System.out.println(Thread.currentThread().getName());
        }, "Thread_skg2");
        th2.start();

        System.out.println("Main is ending");
    }
}

