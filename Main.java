class Test<T, U> {
    T a;
    U b;

    Test(T a, U b) {
        this.a = a;
        this.b = b;
    }

    public void print() {
        System.out.println(a);
        System.out.println(b);
    }
}

class Main {
    public static void main(String[] args) {
        Test<Integer, String> obj1 = new Test<Integer, String>(2, "rdhon");
        obj1.print();

    }
}