package college;

import java.util.Scanner;

public class OddEven {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter a number : ");
        n = sc.nextInt();

        System.out.print("Even : ");
        for(int  i = 1; i <= n; i++){
            if(i%2 == 0){
                System.out.print(i+" ");
            }
        }
        System.out.println();
        System.out.print("Odd : ");
        for(int  i = 1; i <= n; i++){
            if(i%2 == 1){
                System.out.print(i+" ");
            }
        }
        System.out.println();
    }
    
}