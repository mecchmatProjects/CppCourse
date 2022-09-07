// Java program для роботи з примітивними типами 
class PrimitiveTypes{
     public static void main(String args[]){
char a = 'G'; //  визначаємо символ 
int i=89; //Цілий тип  (used for numeric values )          
byte b = 4; /* можна використати byte або short якщо потрібно заощадити память
Наступне присвоєння–омилка (larger than byte range )*/
// byte b1 = 7888888955;*/
short s = 56;
long L1 = 0xFEED1234L; // 64-бітне число  в 16-річній формі
double d = 4.355453532; // по замовченню дійсне число - тип double
float f = 4.7333434f;   // для типу float вказуємо суфікс 'f'
System.out.println("char: " + a);
System.out.println("integer: " + i);
System.out.println("byte: " + b);
System.out.println("short: " + s);
System.out.println("float: " + f);
System.out.println("double: " + d);
System.out.printf("long: %d, %x" , L1, L1);
}
}
