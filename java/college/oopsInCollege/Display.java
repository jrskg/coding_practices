package college.oopsInCollege;

import java.util.Scanner;

public class Display {
    void display(){
        System.out.println("This is a message");
    }

    void oddEven(){
        int n;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a number : ");
        n = sc.nextInt();
        if(n%2 == 0){
            System.out.println(n+ " is Even");
        }else{
            System.out.println(n+ " is Odd");
        }
    }
}
