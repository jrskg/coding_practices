package college;


import java.util.Scanner;

public class Fibonacci {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.print("Enter number : ");
        n = sc.nextInt();
        int a = 0, b = 1, ans = 0;

        for(int i = 0; i <= n; i++){
            System.out.print(a + " ");
            ans = a+b;
            a = b;
            b = ans;
        }
    }
}
