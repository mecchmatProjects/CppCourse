public class InitialValuesZ {
boolean bool = true;
char ch = ‘x‘;
byte b = 47;
short 5 = Oxff;
int i = 999;
long lng = 1;
float f = 3.14f;
double d = 3.14159;
}

// housekeeping/MethodInit.java
public class MethodInit {
 int i = f();
 int f() { return 11; }
}

// housekeeping/MethodInit2.java
public class MethodInit2 {
int i = f();
int j = g(1);
int f() { return 11; }
int g(int n) { return n * 10; }
}

public class MethodInit3 {
//- int j = g(i); // Illegal forward reference
int i = f();
int f() { return 11; }
int g(int n) { return n * 10; }
}

public class Counter {
int i;
Counter() { i = 7; }
// ...
}


class Window {
Window(int marker) {
System.out.println("Window(” + marker + ”)”);
}
}
class House {
Window w1 = new Window(1); // Before constructor
House() {
// Show that we’re in the constructor:
System.out.println("House()");
w3 = new Window(33); // Reinitialize w3
}
Window w2 = new Window(2); // After constructor
void f() { System.out.println(”f()”); }
Window w3 = new Window(3); // At end
}
public class OrderOfInitialization {
public static void main($tring[] args) {
House h = new House();
h.f(); // Shows that construction is done
}
/* Output:
Window(1)
Window(2)
Window(3)
House()
Window(33)
f()
*/

