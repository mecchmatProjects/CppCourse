class NoSimpleClass {
  int m;
  NoSimpleClass(int i) {}
  NoSimpleClass(double d) {}
}

public class L2_2NoSimpleTests {
  public static void main(String[] args) {
  //- NoSimpleClass b = new NoSimpleClass(); // No default
  NoSimpleClass b2 = new NoSimpleClass(1);
  NoSimpleClass b3 =new NoSimpleClass(1.0);
  //NoSimpleClass b4 =new NoSimpleClass(b3);// Немає копіювання
  NoSimpleClass b5 =b2;  // b2 те саме що b5 (b5.m == b2.m)
  b5.m =2;
  System.out.printf("B5.m=%d , B2.m=%d", b5.m,b2.m);
  }
}
