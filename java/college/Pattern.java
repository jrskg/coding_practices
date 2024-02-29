package college;

import java.util.Scanner;

public class Pattern {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, k = 1;
        System.out.print("Enter number : ");
        n = sc.nextInt();
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++){
                System.out.print(k++ + "");
            }
            System.out.println();
        }
    }
}
