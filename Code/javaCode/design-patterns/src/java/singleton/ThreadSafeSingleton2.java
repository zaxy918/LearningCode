package singleton;

public class ThreadSafeSingleton2 {
    private volatile static ThreadSafeSingleton2 uniqueInstance;

    private ThreadSafeSingleton2() {
    }

    public static ThreadSafeSingleton2 getInstance() {
        if (uniqueInstance == null) {
            synchronized (ThreadSafeSingleton2.class) {
                if (uniqueInstance == null) {
                    uniqueInstance = new ThreadSafeSingleton2();
                }
            }
        }
        return uniqueInstance;
    }
}
