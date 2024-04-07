package college.practice;

interface childOne{
    void printName(String name);
    void printEmail(String Email);
}

interface childTwo{
    void printDetails(String name, String email);
}

public class Multiple implements childOne, childTwo {
    public void printName(String name){
        System.out.println("Name is : " + name);
    }
    public void printEmail(String email){
        System.out.println("Email is : " + email);
    }
    public void printDetails(String name, String email){
        System.out.println("Name is : " + name);
        System.out.println("Email is : " + email);
    }

}
