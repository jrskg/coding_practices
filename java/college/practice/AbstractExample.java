package college.practice;

abstract class Nice {
    abstract public void printDetails();
    abstract public void Okay();
    public void addTwo(int a, int b){
        System.out.println("Sum : " + (a+b));
    }
}

class Nice2 extends Nice{
    @Override
    public void printDetails() {
        System.out.println("Printing details");
    }
    @Override
    public void Okay() {
        System.out.println("Okay");
    }
}

public class AbstractExample {
    public static void main(String[] args) {
        Nice2 obj = new Nice2();
        obj.Okay();
        obj.printDetails();
        obj.addTwo(10, 20);
    }
}



