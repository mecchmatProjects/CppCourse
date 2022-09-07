class Window {
  Window(int marker) {
    System.out.println("Window(" + marker + ")");
  }
}
class House {
  Window w1 = new Window(1); //Перед 
  House() {
  // Конструктор:
    System.out.println("House()");
    w3 = new Window(33); //Реініціалізація w3
  }
  Window w2 = new Window(2); // Після
  void f() { System.out.println("f()"); }
  Window w3 = new Window(3); // В кінці
}

public class L2_3OrderOfInitialization {
  public static void main(String[] args) {
    House h = new House();
    h.f(); // Виклик методу
  }
}
/* Результат:
Window(1)
Window(2)
Window(3)
House()
Window(33)
f()
*/
