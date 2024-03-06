<h1 align="center">
Java Exception Handling
</h1>

> An exception is an unexpected event that occurs during program execution. It affects the flow of the program instructions which can cause the program to terminate abnormally.

```java
public class main{
    public static void main(String[] args){
        int a = 1;
        int b = 0;

        int result = divide(a, b);
        System.out.println("Result: " + result);
    }
    public static int divide(int a, int b){
        return a / b;
    }
}
// Exception in thread "main" java.lang.ArithmeticException: / by zero
// 	at main.divide(main.java:10)
// 	at main.main(main.java:6)

public class main{
    public static void main(String[] args){
        int a = 1;
        int b = 0;
        int result = 0;
        try{
            result = divide(a, b);
        }catch(ArithmeticException e){
            System.out.println("You can't divide " + a + " by " + b);
        }finally {
            System.out.println("This is the finally block");
        }
        
        System.out.println("Result: " + result);
    }
    public static int divide(int a, int b){
        return a / b;
    }
}

// You can't divide 1 by 0
// Result: 0
// This is the finally block
```
> Note: It is a good practice to use the finally block. It is because it can include important cleanup codes like,

>code that might be accidentally skipped by return, continue or break
> closing a file or connection

#####Java Exception hierarchy

![alt text](https://cdn.programiz.com/sites/tutorial2program/files/ExceptionHierarchy.png)

#####Errors
Errors represent irrecoverable conditions such as Java virtual machine (JVM) running out of memory, memory leaks, stack overflow errors, library incompatibility, infinite recursion, etc.
Errors are usually beyond the control of the programmer and we should not try to handle errors.

#####Exceptions
Exceptions can be caught and handled by the program.
When an exception occurs within a method, it creates an object. This object is called the exception object.
It contains information about the exception such as the name and description of the exception and state of the program when the exception occurred.

#####RuntimeException
A runtime exception happens due to a programming error. They are also known as unchecked exceptions.

These exceptions are not checked at compile-time but run-time. Some of the common runtime exceptions are:

Improper use of an API - IllegalArgumentException
Null pointer access (missing the initialization of a variable) - NullPointerException
Out-of-bounds array access - ArrayIndexOutOfBoundsException
Dividing a number by 0 - ArithmeticException
You can think about it in this way. “If it is a runtime exception, it is your fault”.

The NullPointerException would not have occurred if you had checked whether the variable was initialized or not before using it.

An ArrayIndexOutOfBoundsException would not have occurred if you tested the array index against the array bounds.

#####IOException
An IOException is also known as a checked exception. They are checked by the compiler at the compile-time and the programmer is prompted to handle these exceptions.

Some of the examples of checked exceptions are:

Trying to open a file that doesn’t exist results in FileNotFoundException
Trying to read past the end of a file

##### throws keyword
We use the throws keyword in the method declaration to declare the type of exceptions that might occur within it.

```java
import java.io.*;
class Main {
  public static void findFile() throws IOException {
    // code that may produce IOException
    File newFile=new File("test.txt");
    FileInputStream stream=new FileInputStream(newFile);
  }
  public static void main(String[] args) {
    try{
      findFile();
    } catch(IOException e){
      System.out.println(e);
    }
  }
}
// output:
// java.io.FileNotFoundException: test.txt (No such file or directory)
```
When we run this program, if the file test.txt does not exist, FileInputStream throws a FileNotFoundException which extends the IOException class.

If a method does not handle exceptions, the type of exceptions that may occur within it must be specified in the throws clause so that methods further up in the call stack can handle them or specify them using throws keyword themselves.

The findFile() method specifies that an IOException can be thrown. The main() method calls this method and handles the exception if it is thrown.

``` java
import java.io.*;
class Main {
  public static void findFile() throws NullPointerException, IOException, InvalidClassException {
    
    // code that may produce NullPointerException
    … … … 

    // code that may produce IOException
    … … … 

    // code that may produce InvalidClassException 
    … … … 
  }

  public static void main(String[] args) {
    try{
      findFile();
    } catch(IOException e1){
      System.out.println(e1.getMessage());
    } catch(InvalidClassException e2){
      System.out.println(e2.getMessage());
    }
  }
}
```
##### throws keyword Vs. try...catch...finally
There might be several methods that can cause exceptions. Writing try...catch for each method will be tedious and code becomes long and less-readable.

throws is also useful when you have checked exception (an exception that must be handled) that you don't want to catch in your current method.

##### throw keyword
The throw keyword is used to explicitly throw a single exception.

When an exception is thrown, the flow of program execution transfers from the try block to the catch block. We use the throw keyword within a method.

```java
import java.io.*;
class Main {
  public static void findFile() throws IOException {
    throw new IOException("File not found");
  }

  public static void main(String[] args) {
    try {
      findFile();
      System.out.println("Rest of code in try block");
    } catch (IOException e) {
      System.out.println(e.getMessage());
    }
  }
}
// output:
// File not found
```

The findFile() method throws an IOException with the message we passed to its constructor.

Note that since it is a checked exception, we must specify it in the throws clause.

The methods that call this findFile() method need to either handle this exception or specify it using throws keyword themselves.

We have handled this exception in the main() method. The flow of program execution transfers from the try block to catch block when an exception is thrown. So, the rest of the code in the try block is skipped and statements in the catch block are executed.

