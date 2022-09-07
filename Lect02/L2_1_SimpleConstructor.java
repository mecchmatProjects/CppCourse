class Simple {
  //no-arg constructor (конструктор по замовченню)
   Simple() { // Конструктор
     System.out.print("Constructor!");
  }
}
public class L2_1_SimpleConstructor {
  public static void main(String[] args) {
  for(int i = 0; i < 3; i++)
    new Simple();
  }
}
