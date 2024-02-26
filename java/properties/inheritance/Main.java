package properties.inheritance;

public class Main {
    public static void main(String[] args) {
        Box box = new Box(20);
        box.info();

        Box box2 = new Box(box);
        box2.info();

        BoxWithWeight bw = new BoxWithWeight();
        bw.info();
    }
}
