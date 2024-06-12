package college.collectionFramework;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> l = new ArrayList<>();
        l.add(10);
        l.add(20);
        l.add(30);
        System.out.println(l);
        System.out.println(l.size());
        System.out.println(l.contains(20));

//        Iterator<Integer> it = l.iterator();
//        while (it.hasNext()){
//            System.out.println(it.next());
//        }


    }
}
