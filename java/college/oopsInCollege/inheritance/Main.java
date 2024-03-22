package college.oopsInCollege.inheritance;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, l, b, h;
        System.out.print("Enter a num, l, b and h: ");
        n = sc.nextInt();
        l = sc.nextInt();
        b = sc.nextInt();
        h = sc.nextInt();

//        Area obj = new Area(n, l, b);
//        obj.getArea();
//        obj.checkOddEven();

        Volume obj2 = new Volume(n, l, b, h);
        obj2.getVolume();
        obj2.getArea();
        obj2.checkOddEven();
    }
}
