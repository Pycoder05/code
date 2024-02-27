import java.util.Scanner;

class OOCException extends Exception{
    OOCException(String message){
        super(message);
    }
}
public class test{
    static void divide(double a,double b)throws OOCException{
        if(b==0){
            throw new OOCException("Division by zero");
        }
        double c=a/b;
        System.out.println("Result is "+c);
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter two numbers");
        double a=sc.nextDouble();
        double b=sc.nextDouble();
        try{
            divide(a,b);
        }catch(OOCException e){
            System.out.println(e);
        }finally{
            System.out.println("end");
        }
    }
}