<h1 align="center">
JAVA OOP
</h1>


- [abstract_class](#abstract_class)
    * [distinct](#distinct)


> static / final methods can't be over ride


> using "super" sub class can access parent class var
```java
 class animal{
    int a = 10;
}
class dog extends animal{
    int a = 50;
    void print(){
        System.out.println(super.a);
    }   
}
public class main {
    public static void main(String[] args) {
        dog d1 = new dog();
        d1.print();
    }
}
```

> 


# Abstract_class
> abstract class is a class that is declared abstract—it may or may not include abstract methods. Abstract classes cannot be instantiated, but they can be subclassed.

- If a class includes abstract methods, then the class itself must be declared abstract.
- If the abstract class includes any abstract method, then all the child classes inherited from the abstract superclass must provide the implementation of the abstract method.

```java
abstract class animal{
    abstract void sound();
    void eat(){
        System.out.println("Animal eat!");
    }
}

class dog extends animal{
    @override
    void sound(){
        System.out.println("wuff wuff!");
    }
}
public class main {
    public static void main(String[] args) {
        dog d1 = new dog();
        d1.eat();
        d1.sound();
    }
}
```

- if the Dog class doesn't provide the implementation of the abstract method makeSound(), Dog should also be declared as abstract. This is because the subclass Dog inherits makeSound() from Animal.

```java
abstract class animal{
    public int m;
    animal(int m){
        this.m = m;
    }
    abstract void sound();
    void eat(){
        System.out.println("Animal eat!");
    }
}
abstract class dog extends animal{
    dog(int m){
        super(m);
    }
    abstract void sound();
}
class puppy extends dog{
    puppy(int m){
        super(m);
    }
    void sound(){
        System.out.println("small wuff!");
    }
}
public class main {
    public static void main(String[] args) {
        dog p1 = new puppy(12);
        p1.eat();
        p1.sound();
        System.out.println(p1.m);
    }
}
//output:
//Animal eat!
//small wuff!
//12
```
> abstruct class can have constructor, but through sub class
> can't be final

# Interface

```java
// pure abstract class
public abstract class PureAbstructClass{
    public abstract void method1();
    public abstract void method2();
    public abstract void method3(); 
}
// interface 
public interface class PureAbstructClass{
    void method1();
    void method2();
    void method3(); 
}
```
> Multiple Interfaces
```java
interface A {
  // members of A
}
interface B {
  // members of B
}
class C implements A, B {
  // abstract members of A
  // abstract members of B
}
```

> here we don't have to change payment engine if we want to add any new payment method

```java
interface Payment{
    long getAmount();
}
class BkashPayment implements Payment{
    public long getAmount(){
        System.out.println("Taking Bkash Payment");
        return 100;
    }
}
class NagadPayment implements Payment{
    public long getAmount(){
        System.out.println("Taking Naga Payment");
        return 500;
    }
}
class PaymentEngine{
    public void accept(Payment payment){
        System.out.println("Accepting Payment: " + payment.getAmount());
    }
}
public class main {
    public static void main(String[] args) {
        PaymentEngine paymentEngine = new PaymentEngine();

        BkashPayment bkashPayment = new BkashPayment();
        paymentEngine.accept(bkashPayment);

        NagadPayment nagadPayment = new NagadPayment();
        paymentEngine.accept(nagadPayment);
    }
}
// output:
// Taking Bkash Payment
// Accepting Payment: 100
// Taking Naga Payment
// Accepting Payment: 500

```
> compile use auto public and static before interface



# Polymorphism

```java
class Liquid{
    public void swirl(boolean clockwise){
        System.out.println("Swirling Liquid");
    }
}
class Coffee extends Liquid{
    @Override
    public void swirl(boolean clockwise){
        System.out.println("Swirling Coffee");
    }
}
class Milk extends Liquid{
    @Override
    public void swirl(boolean clockwise){
        System.out.println("Swirling Milk");
    }
}
class CoffeeCup{
    private Liquid innerLiquid;

    void addLiquid(Liquid liq){
        innerLiquid = liq;
        innerLiquid.swirl(false);
    }
}
public class main{
    public static void main(String args[]){
        CoffeeCup myCup = new CoffeeCup();

        Liquid genericLiquid = new Liquid();
        Coffee coffee = new Coffee();
        Milk milk = new Milk();

        myCup.addLiquid(genericLiquid);
        myCup.addLiquid(coffee);
        myCup.addLiquid(milk);
    }
}

```

> only the super class methods can be called
``` java
class Liquid{
    public void swirl1(boolean clockwise){
        System.out.println("Swirling Liquid");
    }
}

class Coffee extends Liquid{
    public void swirl2(boolean clockwise){
        System.out.println("Swirling Coffee");
    }
}

public class main{
    public static void main(String args[]){

        Liquid L1 = new Coffee();
        L1.swirl1(false);
        L1.swirl2(false); // this will give an error
    }
}

```

> but method overriding will call subclass method
``` java
class Liquid{
    public void swirl(boolean clockwise){
        System.out.println("Swirling Liquid");
    }
}
class Coffee extends Liquid{
    public void swirl(boolean clockwise){
        System.out.println("Swirling Coffee");
    }
}
public class main{
    public static void main(String args[]){

        Liquid L1 = new Coffee();
        L1.swirl(false);
    }
}
// output:
// Swirling Coffee
```

#### upcasting

```java
Liquid liquid = new Coffee();
// normally this is upcasing
// sub class object to super class reference 
```

#### downcasing
> normally we can't called getName() method from dog3, but if we want then do it by down casting.
```java
class Dog{
    public void getType(){
        System.out.println("Normal Dog");
    }
}

class DeshiDog extends Dog{
    @Override
    public void getType(){
        System.out.println("Deshi Dog");
    }
}
class BideshiDog extends Dog{
    @Override
    public void getType(){
        System.out.println("Bideshi Dog");
    }

    public void getName(){
        System.out.println("Poodle");
    }
}
public class main{
    public static void main(String args[]){
        Dog dog1 = new Dog();
        Dog dog2 = new DeshiDog();
        Dog dog3 = new BideshiDog();

        BideshiDog bideshiDog = (BideshiDog) dog3;
        bideshiDog.getName();
        // or 
        ((BideshiDog) dog3).getName();

        dog1.getType();
        dog2.getType();
        dog3.getType();
        
        
    }
}
// output: 
// Poodle
// Poodle
// Normal Dog
// Deshi Dog
// Bideshi Dog

```

## access_modifier

> protected method can be change to public in sub class, but reverse is not possible.

## Anonymous Class
nested class that doesn't have any name is known as an anonymous class.

```java
class outerClass {
    // defining anonymous class
    object1 = new Type(parameterList) {
         // body of the anonymous class
    };
}
```
> Anonymous classes usually extend subclasses or implement interfaces.
> Anonymous classes are defined inside an expression. So, the semicolon is used at the end of anonymous classes to indicate the end of the expression.

##### Anonymous Class Extending a Class
```java
class Polygon {
   public void display() {
      System.out.println("Inside the Polygon class");
   }
}

class AnonymousDemo {
   public void createClass() {

      // creation of anonymous class extending class Polygon
      Polygon p1 = new Polygon() {
         public void display() {
            System.out.println("Inside an anonymous class.");
         }
      };
      p1.display();
   }
}

class Main {
   public static void main(String[] args) {
       AnonymousDemo an = new AnonymousDemo();
       an.createClass();
   }
}

// Output:
// Inside an anonymous class.
```


#####  Anonymous Class Implementing an Interface
```java
interface Polygon {
   public void display();
}

class AnonymousDemo {
   public void createClass() {

      Polygon p1 = new Polygon() {
         public void display() {
            System.out.println("Inside an anonymous class.");
         }
      };
      p1.display();
   }
}

class Main {
   public static void main(String[] args) {
      AnonymousDemo an = new AnonymousDemo();
      an.createClass();
   }
}


// Output:
// Inside an anonymous class.
```

##### example 

```java
public class main {
  interface HelloWorld {
      public void greet();
      public void greetSomeone(String someone);
  }
  public void sayHello() {
      class EnglishGreeting implements HelloWorld {
          String name = "world";
          public void greet() {
              greetSomeone("world");
          }
          public void greetSomeone(String someone) {
              name = someone;
              System.out.println("Hello " + name);
          }
      }
      HelloWorld englishGreeting = new EnglishGreeting();

      HelloWorld frenchGreeting = new HelloWorld() {
          String name = "tout le monde";
          public void greet() {
              greetSomeone("tout le monde");
          }
          public void greetSomeone(String someone) {
              name = someone;
              System.out.println("Salut " + name);
          }
      };
      
      HelloWorld spanishGreeting = new HelloWorld() {
          String name = "mundo";
          public void greet() {
              greetSomeone("mundo");
          }
          public void greetSomeone(String someone) {
              name = someone;
              System.out.println("Hola, " + name);
          }
      };
      englishGreeting.greet();
      frenchGreeting.greetSomeone("Fred");
      spanishGreeting.greet();
  }

  public static void main(String... args) {
      main myApp = new main();
      myApp.sayHello();
  }            
}
// output: 
// Hello world
// Salut Fred
// Hola, mundo
```