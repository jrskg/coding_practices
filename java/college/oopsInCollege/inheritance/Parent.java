package college.oopsInCollege.inheritance;

public class Parent {
    int l, b, h;
    public Parent(int l,int b, int h){
        this.l = l;
        this.b = b;
        this.h = h;
    }

    int getArea(){
        return this.l * this.b;
    }
    int getPeri(){
        return 2*(this.l + this.b);
    }
    int getVolume(){
        return this.l * this.b * this.h;
    }
}
