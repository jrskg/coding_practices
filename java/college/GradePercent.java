package college;

import java.util.Scanner;

public class GradePercent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] marks = new int[3];
        int total = 0;

        for(int i = 0; i < marks.length; i++) {
            System.out.print("Enter mark " + (i+1) + " : ");
            marks[i] = sc.nextInt();
            total += marks[i];
        }
        int per = total/3;
        System.out.println("Total : "+total);

        if(per >= 90){
            System.out.println("Grade A");
        }
        else if(per >= 60){
            System.out.println("Grade B");
        }
        else{
            System.out.println("Grade C");
        }

    }
}
