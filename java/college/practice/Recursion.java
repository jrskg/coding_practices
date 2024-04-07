package college.practice;

public class Recursion {
    int factorial(int n){
        if (n == 1) {
            return 1;
        }
        return n * factorial(n-1);
    }

    int fibonacci(int n){
        if (n <= 1) {
            return n;
        }
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
