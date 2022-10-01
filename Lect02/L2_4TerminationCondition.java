class Book {
  boolean checkedOut = false;
  Book(boolean checkOut) {
     checkedOut = checkOut;
  }
  void checkIn() {
   checkedOut = false;
  }
  
  @Override
  public void finalize() {
    if(checkedOut)
      System.out.println("Error: checked out");
    // або
    //super.finalize(); // Call the base-class version
  }
}

public class L2_4TerminationCondition {
  public static void main(String[] args) {
    Book novel = new Book(true);
    // Коректна очистка
    novel.checkIn();
    // Створили посилання, забули прибрати:
    new Book(true);
    //Викликали збирач мусора:
    System.gc();
 }
}
