package college.oopsInCollege.inheritance;

public class OddEven {
    int n;
    public OddEven(int n){
        this.n = n;
    }
    void checkOddEven(){
        if(this.n % 2 == 0){
            System.out.println(this.n + " is even");
        }else {
            System.out.println(this.n + " is odd");
        }
    }
}
