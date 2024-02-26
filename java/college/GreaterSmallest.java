package college;

import java.util.Scanner;

public class GreaterSmallest {
    public static void main(String [] args){
        greater();
        smaller();
    }

    static void greater(){
        Scanner sc = new Scanner(System.in);
        int a, b;
        System.out.print("Enter a : ");
        a = sc.nextInt();
        System.out.print("Enter b : ");
        b = sc.nextInt();

        if(a > b){
            System.out.println("a is greater " + a);
        }else{
            System.out.println("b is greater " + b);
        }
    }

    static void smaller(){
        Scanner sc = new Scanner(System.in);
        int a, b;
        System.out.print("Enter a : ");
        a = sc.nextInt();
        System.out.print("Enter b : ");
        b = sc.nextInt();

        if(a < b){
            System.out.println("a is smaller " + a);
        }else{
            System.out.println("b is smaller " + b);
        }
    }
}
