<h1 align="center">
Thread
</h1>

> java uses thread's using two method

* Thread class Extend
* Runnable Interface

##### Thread Class Extend

```java
public class ExtendedThread extends Thread{
    @Override
    public void run(){

    }
}
```
> extends Thread class and Override run methon() for threading

```java
import java.lang.Thread;
import java.util.concurrent.TimeUnit;

class ExtendedThread extends Thread{
    @Override
    public void run(){
        for(int i = 0; i < 5; ++i){
            System.out.println("[" + i + "] INSIDE " + Thread.currentThread().getName());
            sleepOneSecond(); // 1 second wait
        }
    }

    private static void sleepOneSecond(){
        try{
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}

public class Main{
    public static void main(String[] args){
        ExtendedThread extendedThread = new ExtendedThread();
        extendedThread.setName("Extended Thread");
        extendedThread.start();

        for(int i = 0; i < 5; ++i){
            System.out.println("[" + i + "] INSIDE " + Thread.currentThread().getName());
            sleepOneSecond();
        }
    }

    private static void sleepOneSecond(){
        try{
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
[0] INSIDE Extended Thread
[0] INSIDE main
[1] INSIDE main
[1] INSIDE Extended Thread
[2] INSIDE main
[2] INSIDE Extended Thread
[3] INSIDE main
[3] INSIDE Extended Thread
[4] INSIDE Extended Thread
[4] INSIDE main
```
> running two thread, one is **Extended Thread** another **main** simultaneously using **.start()**
> output will be different each time , bcz of os schedular. 


##### Runnable Interface

```java
public class MyThreadRunnable implements Runnable{
    @Override
    public void run(){

    }
}
```
> implements Runnable class and Override run methon() for threading

```java
import java.lang.Thread;
import java.util.concurrent.TimeUnit;

class MyThreadRunnable implements Runnable{
    @Override
    public void run(){
        for(int i = 0; i < 5; ++i){
            System.out.println("[" + i + "] INSIDE " + Thread.currentThread().getName());
            sleepOneSecond();
        }
    }
    private static void sleepOneSecond(){
        try{
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
public class Main{
    public static void main(String[] args){
        MyThreadRunnable myThreadRunnable = new MyThreadRunnable();
        Thread thread = new Thread(myThreadRunnable);
        thread.setName("Runnable Thread");
        thread.start();

        for(int i = 0; i < 5; ++i){
            System.out.println("[" + i + "] INSIDE " + Thread.currentThread().getName());
            sleepOneSecond();
        }
    }
    private static void sleepOneSecond(){
        try{
            Thread.sleep(TimeUnit.SECONDS.toMillis(1));
        }catch(InterruptedException e){
            e.printStackTrace();
        }
    }
}
[0] INSIDE Runnable Thread
[0] INSIDE main
[1] INSIDE main
[1] INSIDE Runnable Thread
[2] INSIDE Runnable Thread
[2] INSIDE main
[3] INSIDE main
[3] INSIDE Runnable Thread
[4] INSIDE main
[4] INSIDE Runnable Thread
```

> **Thread** class constructor receive **Runnable** interface as a parameter.


>> for small code , we can use anonymous inner class, or lamda expression
```java
import java.lang.Thread;

public class Main{
    public static void main(String[] args){
        // using anonymous inner class 
        Thread t1 = new Thread(new Runnable(){
            @Override
            public void run(){
                doWork();
            }
        });
        t1.start();
        // lamda expression
        Thread t2 = new Thread(() -> {
            doWork();
        });
        t2.start();
    }
    private static void doWork(){
        System.out.println("Doing some import work!");
    }
}
```

```java
Runnable runnable = new Runnable(){
    @Override
    public void run(){
    }
}
// same as
Runnable runnable = () -> {  
};
```

##### Terminating a Thread

```java
import java.lang.Thread;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class Watch implements Runnable{
    private volatile boolean running = true;

    @Override
    public void run(){
        while(running){
            printCurrentTime();
            sleepOneSecond();
        }
    }
    private void sleepOneSecond(){
        try{
            Thread.sleep(1000);
        }catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    public void printCurrentTime(){
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:s a");

        String formattedCurrentTime = LocalDateTime.now().format(formatter);

        System.out.println(formattedCurrentTime);
    }

    public void shutdown(){
        this.running = false;
    }
}
public class Main{
    public static void main(String[] args){
        Watch watch = new Watch();
        Thread t1 = new Thread(watch);
        t1.start();
        try{
            Thread.sleep(5000);
        }catch (InterruptedException e){
            e.printStackTrace();
        }
        watch.shutdown();
    }
}
```

> terminate a thread using a flag.
<img src="https://cpuninja.com/wp-content/uploads/2021/09/cache-latency.png" />
> sometimes thread store local variable to (L1, L2..) CPU cache memory.for fast read/write. so if one thread change value , another thread might not get changed value , bcz they are using cache memory. **volatile** keyword force to read/write from main memory. 