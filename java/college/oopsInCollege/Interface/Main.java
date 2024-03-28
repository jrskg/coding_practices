package college.oopsInCollege.Interface;

import java.util.ArrayList;

interface Algos{
    void factorial(int num);
    void maximum(ArrayList<Integer> numbers);
}

interface Algos2{
    void palindromicString(String str);
    void palindromicNumber(int num);
    void palindromicArray(ArrayList<Integer> arr);
}

class Prime{
    int min, max;
    public Prime(int min, int max){
        this.min = Math.min(min, max);
        this.max = Math.max(min, max);
    }

    void printAllPrimes(){
        for(int i = this.min; i <= this.max; i++){
            boolean isPrime = true;
            for(int j = 2; j * j <= i; j++){
                if(i%j == 0){
                    isPrime = false;
                    break;
                }
            }
            if (isPrime){
                System.out.print(i + " ");
            }
        }
    }
}

class Okay extends Prime implements Algos, Algos2{
    public Okay(int num1, int num2){
        super(num1,num2);
    }
    @Override
    public void factorial(int num){
        int fact = 1;
        for(int i = 1; i <= num; i++){
            fact *= i;
        }
        System.out.println("The factorial is " + fact);
    }
    @Override
    public void maximum(ArrayList<Integer> numbers){
        int max = -100000;
        for (Integer number : numbers) {
            if (number > max) {
                max = number;
            }
        }
        System.out.println("The maximum is " + max);
    }

    @Override
    public void palindromicString(String str) {
        int i = 0, j = str.length() - 1;
        boolean flag = true;

        while(i < j){
            if(str.charAt(i++) != str.charAt(j--)){
                flag = false;
                break;
            }
        }

        if(flag){
            System.out.println(str + " is palindromic");
        }else{
            System.out.println(str + " is not palindromic");
        }
    }

    @Override
    public void palindromicNumber(int num) {
        int temp = num;
        int reversedNum = 0;

        while (temp != 0){
            reversedNum = reversedNum * 10 + (temp % 10);
            temp /= 10;
        }

        if(reversedNum == num){
            System.out.println(num + " is palindromic number");
        }else {
            System.out.println(num + " is not a palindromic number");
        }
    }

    @Override
    public void palindromicArray(ArrayList<Integer> arr) {
        int i = 0, j = arr.size() - 1;
        boolean flag = true;

        while(i <= j){
            if(!(arr.get(i++).equals(arr.get(j--)))){
                flag = false;
                break;
            }
        }

        if(flag){
            System.out.println("Given array is palindromic");
        }else{
            System.out.println("Given array is not palindromic");
        }
    }
}
public class Main {
    public static void main(String[] args) {
        Okay obj = new Okay(10, 20);
        obj.factorial(5);
        obj.printAllPrimes();
        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(100);
        arr.add(10);
        arr.add(30);
        arr.add(6);
        arr.add(30);
        arr.add(10);
        arr.add(100);

        obj.maximum(arr);
        obj.palindromicNumber(112211);
        obj.palindromicString("okayako");
        obj.palindromicArray(arr);
    }
}
