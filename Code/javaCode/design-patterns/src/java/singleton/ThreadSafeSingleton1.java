package singleton;

public class ThreadSafeSingleton1 {
    private static ThreadSafeSingleton1 uniqueInstance = new ThreadSafeSingleton1();

    private ThreadSafeSingleton1() {
    }

    public static ThreadSafeSingleton1 getInstance() {
        return uniqueInstance;
    }
}
