package properties.inheritance;

public class Box {
    double length;
    double breadth;
    double width;

    Box(){
        this.length = -1;
        this.breadth = -1;
        this.width = -1;
    }
    Box(double s){
        this.length = s;
        this.breadth = s;
        this.width = s;
    }
    Box(double l, double b, double w){
        this.length = l;
        this.breadth = b;
        this.width = w;
    }

    Box(Box old){
        this.length = old.length;
        this.breadth = old.breadth;
        this.width = old.width;
    }
    public void info(){
        System.out.println("Width " + this.width);
        System.out.println("Length " + this.length);
        System.out.println("Breadth " + this.breadth);
    }
}
