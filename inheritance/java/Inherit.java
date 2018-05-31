
class Inherit {
  public static void main(String[] args) {

    Parent p1 = new Parent();
    Parent c1 = new Child();

    p1.printName();
    c1.printName();
  }
}

class Parent {
  protected String name = "Homer";

  public void printName() {
    System.out.println(name);
  }
}

class Child extends Parent {
  public Child() {
    super.name = "Bart";
  }
}
