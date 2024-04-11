package college.practice;

public final class FinalExample {
    String name;
    String color;
    int seats;

    public FinalExample(String name, String color, int seats){
        this.name = name;
        this.color = color;
        this.seats = seats;
    }

    public void display(){
        System.out.println("Name : " + name);
        System.out.println("Color : " + color);
        System.out.println("Seats : " + seats);
    }
}
