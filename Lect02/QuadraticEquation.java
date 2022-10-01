import java.util.Scanner;
import java.lang.Math;

class QuadraticEquation{ 
  public static void main(String[] args){ 
    double a = 0.5, b = -2.7, c=3.5, d, eps=1e-8;
    Scanner in = new Scanner(System.in);
    a = in.nextDouble();
    b = in.nextDouble();
    c = in.nextDouble();

    if (Math.abs(a) < eps) {
      if (Math.abs(b) < eps) { 
        if (Math.abs(c) < eps){ // Всі коефіцієнти рівні нулю 
            System.out.println("Розвязок —любе число");
        }
        else{ 
            System.out.println("Розвязків немає");
        }
      }
      else{ 
        System.out.println("xl = x2 = " +(-c / b) ) ; 
      }
    }
    else{  // Коэфіцієнти не рівні нулю
        if((d=b*b - 4*a*c)< 0.0){ // Комплексні корені 
           d = 0.5 * Math.sqrt(-d) / a; 
           a = -0.5 * b/ a;
           System.out.println("xl = " +a+ " +i " +d+ ",x2 = " +a+ " -i " +d);
    } 
    else { 
        // Дійсні корені 
        d =0.5 * Math.sqrt(d) / a;
        a = -0.5 * b / a; 
      System.out.println("x1 = " + (a + d) + ", x2 = " +(a - d));
    } 
  } 
 } 
} 
