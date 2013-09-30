class Ex2 {
    public static int fib(Integer a) {
        if (a < 2) {
            return 1;
        }
        return fib(a - 1) + fib(a - 2);
    }

    public static void main(String[] argv) {
        int v = Integer.valueOf(argv[0]);
        System.out.println("fib(" + v + ") = " + fib(v));
    }
}
