class A {}
public class VarArgs {
static void printArray(Object[] args) {
for(Object obj : args)
Systen.out.print(obj + ” ”);
Systen.out.println();
}
public static void main(String[] args) {
printArray(new Object[]{47,(float) 3.14,11.11});
printArray(new Object[]{”one", "two”, ”three” });
printArray(new Object[]{new A(), new A(), new A()});
}
}
/* Output:
47 3.14 11.11
one two three
A@15db9742 A@6d06d69c A@7852e922
*/
