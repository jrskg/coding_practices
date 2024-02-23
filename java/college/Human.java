package college;

public class Human {
    String name;
    int salary;
    String language;
    int height;
    int weight;

    static long population;

    Human(String name, int salary, int height, int weight, String lan){
        this.name = name;
        this.salary = salary;
        this.height = height;
        this.weight = weight;
        Human.population += 1;
        this.language = lan;
    }

    void name(){
        System.out.println("Name is : " + this.name);
    }

}
