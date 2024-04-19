package college.exception;

public class Main {
    public static void main(String[] args) {
        int [] arr = {1, 2, 3, 4, 5};

        try{
//            int c = 30/0;
            System.out.println(arr[5]);
        }catch (ArithmeticException e){
            System.out.println("arithmetic");
//            System.out.println(e.getCause());
            System.out.println(e.getMessage());
        }catch (IndexOutOfBoundsException e){
            System.out.println("Out of bound");
            System.out.println(e);
            System.out.println(e.getCause());
            System.out.println(e.getMessage());
        }catch (Exception e){
            System.out.println(e.toString());
            System.out.println("Normal");
        }finally {
            System.out.println("I am the finally block");
        }

    }
}
