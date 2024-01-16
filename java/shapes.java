abstract class Shape{
    abstract void CalcArea();
    abstract void CalcPeri();
}
class Circle extends Shape{
    double r;
    Circle(double r){
        this.r=r;
    }
    void CalcArea(){
        System.out.println("Area of Circle is "+Math.PI*r*r);
    }
    void CalcPeri(){
        System.out.println("Perimeter of Cicrle is "+2*Math.PI*r);
    }
}
class Triangle extends Shape{
    double a,b,c;
    Triangle(double a,double b, double c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
    void CalcArea(){
        double s=(a+b+c)/2;
        System.out.println("Area of Triangle is "+Math.sqrt(s*(s-a)*(s-b)*(s-c)));
    }
    void CalcPeri(){
        System.out.println("Perimeter of Triangle is "+(a+b+c));
    }
}
public class shapes{
    public static void main(String[] args) {
        Shape obj=new Circle(10);
        obj.CalcArea();
        obj.CalcPeri();
        obj=new Triangle(3,4,5);
        obj.CalcArea();
        obj.CalcPeri();
    }
}