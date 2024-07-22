package college.ioAndStreams;

import java.io.*;

class Car implements Serializable {
    String name;
    String color;
    int number;

    public Car(String name, String color, int number){
        this.name = name;
        this.color = color;
        this.number = number;
    }
}

public class SerializationPractice {
    public static void main(String[] args) {
        Car c = new Car("Nexus", "Black", 707);

        try{
            FileOutputStream fOut = new FileOutputStream("college/ioAndStreams/car.ser");
            ObjectOutputStream out = new ObjectOutputStream(fOut);
            out.writeObject(c);
            fOut.close();
            out.close();
        }catch (IOException e){
            System.out.println(e.getMessage());
        }

        Car c1 = null;
        try{
            FileInputStream fIn = new FileInputStream("college/ioAndStreams/car.ser");
            ObjectInputStream in = new ObjectInputStream(fIn);
            c1 = (Car) in.readObject();
            fIn.close();
            in.close();
        }catch (IOException | ClassNotFoundException e){
            System.out.println(e.getMessage());
        }

        if(c1 != null){
            System.out.println(c1.name);
            System.out.println(c1.color);
            System.out.println(c1.number);
        }
    }
}
