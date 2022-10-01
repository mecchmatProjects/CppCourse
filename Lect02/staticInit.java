class Bowl {
Bowl(int marker) {
System.out.println("Bowl(” + marker + ”)”);
void f1(int marker) {
Systen.out.println("f1(" + marker + ”)”);
}
}
class Table {
static Bowl bowll = new Bowl(1);
Table() {
System.out.println("Table()");
bowl2.f1(1);
void f2(int marker) {
System.out.println("f2(" + marker + ")")3
}
static Bowl bowlZ = new Bowl(Z);
}

class Cupboard {
Bowl bowl3 = new Bowl(3);
static Bowl bowl4 = new Bowl(4);
Cupboard() {
System.out.println("Cupboard()");
bowl4.f1(2);
}
void f3(int marker) {
System.out.println("f3(" + marker + ")")§
}
static Bowl bowlS = new Bowl(5);
}
public class StaticInitialization {
public static void main(String[] args) {
System.out.println("main creating new Cupboard()”);
new Cupboard();
System.out.println("main creating new Cupboard()”);
new Cupboard();
table.f2(1);
cupboard.f3(1);
}
static Table table = new Table();
static Cupboard cupboard = new Cupboard();
}
/* Output:
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
BowZ(3)
Cupboard()
f1(2)
f2(1)
f3(1)
*/


To summarize the process of creating an object, consider a class called Dog:
1. Even though it doesn’t explicitly use the static keyword, the constructor is
actually a static method. So the first time you create an object of type Dog, or
the first time you access a static method or static field of class Dog, the Java
interpreter must locate Dog . class, which it does by searching through the
classpath.
2. As Dog . class is loaded (creating a Class object, which you’ll learn about
later), all of its static initializers are run. Thus, static initialization takes
place only once, as the Class object is loaded for the first time.
3. When you create a new Dog( ), the construction process for a Dog object first
allocates enough storage for a Dog object on the heap.
4. This storage is wiped to zero, automatically setting all the primitives in that Dog
object to their default values (zero for numbers and the equivalent for boolean
and char) and the references to null.
5. Any initializations that occur at the point of field definition are executed.
6. Constructors are executed. As you shall see in the m chapter, this might
actually involve a fair amount of activity, especially when inheritance is
involved.


public class Spoon {
static int i;
static {
i = 47;
}


class Cup {
Cup(int marker) {
System.out.println("Cup(" + marker + ")")§
}
void f(int marker) {
System.out.println("f(" + marker + ")")$
}
}

class Cups {
static Cup cupl;
static Cup cup2;
static {
cupl
cup2
new Cup(1);
new Cup(2);
}
CUPS() {
System.out.println("Cups()”);
}
}


public class ExplicitStatic {
public static void main($tring[] args) {
Systen.out.println("Inside main()");
Cups.cup1.f(99); // [1]
}
// static Cups cupsl = new Cup5();
// static Cups cup52 = new Cup5();
// [2]
// [2]
}
/* Output:
Inside main()
Cup(1)
Cup(2)
f(99)
*/

/*
The instance initialization clause looks exactly like the static initialization
clause except for the missing static keyword. This syntax is necessary to
support the initialization of anonymous inner classes (see the Inner Classes
chapter), but you can also guarantee that certain operations occur regardless of
which explicit constructor is called.

*/





// Instance initialization
class Mug {
Mug(int marker) {
System.out.println("Mug(" + marker + ")")§
}
}
public class Mugs {
Mug mugl;
Mug mugZ;
{ // [1]
mugl = new Mug(1);
mugZ = new Mug(2);
System.out.println("mugl & mugZ initialized”);
}
MUQS() {
System.out.println("Mugs()”);
}
Mugs(int i) {
System.out.println("Mugs(int)”);
}
public static void main($tring[] args) {
Systen.out.println("Inside main()");
new Mugs();
Systen.out.println("new Mugs() completed”);
new Mugs(l);
System.out.println("new Mugs(l) completed”);
}
}
/* Output:
Inside nain()
Mug(1)
Mug(2)
nugI & nugZ initialized
Mug5()
new Mugs() completed
Mug(1)
Mug(2)
nug1 & nugZ initialized
Mugs(int)
new Mugs(l) completed
*
/
