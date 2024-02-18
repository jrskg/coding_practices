package college;

import java.util.Scanner;

public class Prime {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        boolean isPrime = true;
        System.out.print("Enter a number : ");
        n = sc.nextInt();

        if(n <= 1){
            isPrime = false;
        }

        for(int i = 2; i*i <= n; i++){
            if(n%i == 0){
                isPrime = false;
                break;
            }
        }
        
        if(isPrime){
            System.out.println("Prime");
        }else{
            System.out.println("Not Prime");
        }
        sc.close();
    }   
}