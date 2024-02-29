package properties.inheritance;

import java.util.Random;

public class Human {
    String name;
    double height;
    double weight;
    String color;
    static int population;

    Human(double height, double weight){
        this.height = height;
        this.weight = weight;
        this.name = this.generateName();
        this.color = "brown";
        Human.population += 1;
    }
    Human(String name, double height, double weight){
        this.height = height;
        this.weight = weight;
        this.name = name;
        this.color = "brown";
        Human.population += 1;
    }
    Human(String name, String color, double height, double weight){
        this.height = height;
        this.weight = weight;
        this.name = name;
        this.color = color;
        Human.population += 1;
    }
    Human(Human other){
        this.name = other.name;
        this.height = other.height;
        this.weight = other.weight;
        this.color = other.color;
        Human.population += 1;
    }
    private String generateName(){
        int leftLimit = 97;
        int rightLimit = 122;
        int targetStrLength = 8;
        Random rd = new Random();
        StringBuilder buffer =new StringBuilder();

        for(int i = 0; i < targetStrLength; i++){
            int randomInt = leftLimit + (int) (rd.nextFloat() * (rightLimit - leftLimit + 1));
            buffer.append((char) randomInt);
        }
        return buffer.toString();
    }
    void printInfo(){
        System.out.println("Human Details");
        System.out.printf("\tName:%s\n", this.name);
        System.out.printf("\tColor:%s\n", this.color);
        System.out.printf("\tHeight:%.2f\n", this.height);
        System.out.printf("\tName:%.2f\n", this.weight);
    }
}
