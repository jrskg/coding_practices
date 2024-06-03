package college.ioAndStreams;

import java.io.*;

class Employee implements Serializable{
    public String name;
    public String address;
    public int age;
}

public class SerializeDeserialize {
    public static void main(String[] args) {
        Employee e = new Employee();
        e.name = "Suraj Gupta";
        e.address = "Washing Ton Dc";
        e.age = 23;

        try{
            FileOutputStream fileOut = new FileOutputStream("college/ioAndStreams/employee.ser");
            ObjectOutputStream out = new ObjectOutputStream(fileOut);
            out.writeObject(e);
            fileOut.close();
            out.close();
        }catch (IOException i){
            System.out.println(i.getMessage());
        }

        Employee data = null;
        try{
            FileInputStream fileIn = new FileInputStream("college/ioAndStreams/employee.ser");
            ObjectInputStream in = new ObjectInputStream(fileIn);
            data = (Employee) in.readObject();
            fileIn.close();
            in.close();
        }catch (IOException | ClassNotFoundException i){
            System.out.println(i.getMessage());
        }

        if(data != null){
            System.out.println(data.name);
            System.out.println(data.address);
            System.out.println(data.age);
        }
    }
}
