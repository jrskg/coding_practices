package college.oopsInCollege.Interface;

import java.util.ArrayList;

interface Algos{
    void factorial(int num);
    void maximum(ArrayList<Integer> numbers);
}

class Prime{
    int min, max;
    public Prime(int min, int max){
        this.min = Math.min(min, max);
        this.max = Math.max(min, max);
    }

    void printAllPrimes(){
        boolean isPrime = true;
        for(int i = this.min; i <= this.max; i++){
            for(int j = 2; j * j <= i; j++){
                if(i%j == 0){
                    isPrime = false;
                    System.out.println("inside");
                    break;
                }
            }
            if (isPrime){
                System.out.print(i + " ");
            }
        }
    }
}

class Okay extends Prime implements Algos{

    public Okay(int num1, int num2){
        super(num1,num2);
    }
    public void factorial(int num){
        int fact = 1;
        for(int i = 1; i <= num; i++){
            fact *= i;
        }
        System.out.println("The factorial is " + fact);
    }
    public void maximum(ArrayList<Integer> numbers){
        int max = -100000;
        for (Integer number : numbers) {
            if (number > max) {
                max = number;
            }
        }
        System.out.println("The maximum is " + max);
    }
}
public class Main {
    public static void main(String[] args) {
        Okay obj = new Okay(10, 20);
        obj.factorial(5);
        obj.printAllPrimes();
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(10);
        arr.add(30);
        arr.add(6);
        arr.add(120);
        arr.add(1045);
        arr.add(100);
        obj.maximum(arr);
    }
}
