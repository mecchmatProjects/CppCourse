// Java програма для типу byte 
class ByteBites{
 public static void main(String args[]){
        byte a = 126;
        // byte is 8 bit value 
        System.out.println(a); 
        a++; 
        System.out.println(a); 
        a++; 
        System.out.println(a); ////Відбудеться циклічний проход по інтервалу 
        a++; 
        System.out.println(a);
        System.out.printf("%d \n",a);
        int b = (a>>2);
        int b1 = (a<<2);
        int b2 = (a>>>2);

        System.out.printf("%d %d %d",b,b1,b2);
  }
} 
