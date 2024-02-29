package properties.inheritance;

public class Programmer extends Human {
    String role;
    String language;
    double salary;

    Programmer(double height, double weight, String role, String language, double salary) {
        super(height, weight);
        this.role = role;
        this.language = language;
        this.salary = salary;
    }
    Programmer(String name, double height, double weight, String role, String language, double salary){
        super(name, height, weight);
        this.role = role;
        this.language = language;
        this.salary = salary;
    }
    Programmer(String name, String color, double height, double weight, String role, String language, double salary){
        super(name, color, height, weight);
        this.role = role;
        this.language = language;
        this.salary = salary;
    }
    Programmer(Programmer other){
        super(other);
        this.role = other.role;
        this.language = other.language;
        this.salary = other.salary;
    }

    void printInfo(){
        super.printInfo();
        System.out.printf("\tRole:%s\n", this.role);
        System.out.printf("\tLanguage:%s\n", this.language);
        System.out.printf("\tSalary:%.2f\n", this.salary);
    }
}
