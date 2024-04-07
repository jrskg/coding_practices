package college.practice;

public class Modifiers {
    public int pub;
    private int pri;

    public Modifiers(int pub, int pri){
        this.pub = pub;
        this.pri = pri;
    }
    public void printPrivate(){
        System.out.println("The private");
    }
}
