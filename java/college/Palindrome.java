package college;

import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str;
        System.out.print("Enter a string : ");
        str = sc.nextLine();

        int  i = 0, j = str.length()-1;
        boolean isPalindrome = true;
        while (i <= j) {
            if(str.charAt(i) != str.charAt(j)){
                isPalindrome = false;
            }
            i++;
            j--;
        }

        if(isPalindrome){
            System.out.println("Palindrome");
        }else{
            System.out.println("Not Palindrome");
        }
        sc.close();
    }
}