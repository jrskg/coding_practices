package properties.inheritance;

public class Cricketer extends Human{
    String type;
    Cricketer(double height, double weight, String type) {
        super(height, weight);
        this.type = type;
    }
    Cricketer(String name, double height, double weight, String type) {
        super(name, height, weight);
        this.type = type;
    }
    Cricketer(String name, String color, double height, double weight, String type) {
        super(name, color, height, weight);
        this.type = type;
    }
    Cricketer(Cricketer other) {
        super(other);
        this.type = other.type;
    }
    void printInfo(){
        super.printInfo();;
        System.out.printf("\tCricketer Type:%s", this.type);
    }
}
