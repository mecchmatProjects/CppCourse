class Bowl {
  Bowl(int marker) {
   System.out.println("Bowl(" + marker + ")");
  }
  void f1(int marker) {
   System.out.println("f1(" + marker + ")");
  }
}

class Table {
  static Bowl bowll = new Bowl(1);
  Table() {
   System.out.println("Table()");
   bowl2.f1(1);
  }
  void f2(int marker) {
    System.out.println("f2(" + marker + ")");
  }

  static Bowl bowl2 = new Bowl(2);
}

class Cupboard {
  Bowl bowl3 = new Bowl(3);
  static Bowl bowl4 = new Bowl(4);
  Cupboard() {
    System.out.println("Cupboard()");
    bowl4.f1(2);
  }
  void f3(int marker) {
    System.out.println("f3(" + marker + ")");
  }
  static Bowl bowl5 = new Bowl(5);
}

public class L2_5StaticInitialization {

  public static void main(String[] args) {
    System.out.println("main creating new Cupboard()");
    new Cupboard();
    System.out.println("main creating new Cupboard()");
    new Cupboard();
    table.f2(1);
    cupboard.f3(1);
  }
  static Table table = new Table(); // 1st Table -> Bowl1,Bowl2
  static Cupboard cupboard = new Cupboard();
}

/*
2_5StaticInitialization 
Bowl(1)
Bowl(2)
Table()
f1(1)
Bowl(4)
Bowl(5)
Bowl(3)
Cupboard()
f1(2)
main creating new Cupboard()
Bowl(3)
Cupboard()
f1(2)
main creating new Cupboard()
Bowl(3)
Cupboard()
f1(2)
f2(1)
f3(1)

*/
