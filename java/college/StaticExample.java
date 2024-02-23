package college;

public class StaticExample {
    public static void main(String[] args) {
        Human ram = new Human("Suraj", 2000000, 5, 55, "JavaScript");
        System.out.println(Human.population);
        ram.name();
    }


}
