package properties.inheritance;

public class BoxWithWeight extends Box {
    double weight;
    BoxWithWeight(){
        super();
        this.weight = -1;
    }
    public BoxWithWeight(double l, double b, double w, double weight) {
        super(l, b, w);
        this.weight = weight;
    }

    public void info(){
        System.out.println("Width " + this.width);
        System.out.println("Length " + this.length);
        System.out.println("Breadth " + this.breadth);
        System.out.println("Weight " + this.weight);
    }
}
