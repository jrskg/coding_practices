package practice;

class Super{
    public void print(){
        System.out.println("I am super");
    }
}

class Child1 extends Super{
    public void chOne(){
        System.out.println("I am child 1");
    }
}

class Child2 extends Super{
    public void chTwo(){
        System.out.println("I am child 2");
    }
}

public class External {
    public static void main(String[] args) {
        Super s = new Super();
        Child1 ch1 = new Child1();
        Child2 ch2 = new Child2();
        s.print();
        ch1.chOne();
        ch2.chTwo();
    }
}
