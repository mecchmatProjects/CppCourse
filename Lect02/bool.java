import java.util.Scanner;

class bool{

   public static void main(String[] args){
       boolean b1,b2,b3;
       boolean b4 = true, b5=(1>2);

       Scanner in = new Scanner(System.in);
       b1 = in.nextBoolean();

       if(b1){
          b2 = (1 !=2) && (3>4); 
       }
       else{
          b2 = !b1||(3==4)&&(5>=2);
       }       
       b3 = (b1==b2)?true:b2;
       System.out.println("Bools:"+b1 +' '+ b2 + ' ' + b3);
  
   }

}
