public class SynchronizedBlockExample {

    public static void main(String[] args) {
        System.out.println("\nUsing synchronized blocks: ");
        UnsynchronizedCounter unsynchronizedCounter = new UnsynchronizedCounter();
        ThreadedCount threadedCount1 = new ThreadedCount(unsynchronizedCounter, "Thread 1");
        ThreadedCount threadedCount2 = new ThreadedCount(unsynchronizedCounter, "Thread 2");

        threadedCount1.start();
        threadedCount2.start();

        try {
            threadedCount1.join();
            threadedCount2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println("\nUsing synchronized methods:");
        SynchronizedCounter synchronizedCounter = new SynchronizedCounter();
        threadedCount1 = new ThreadedCount(synchronizedCounter, "Thread 1");
        threadedCount2 = new ThreadedCount(synchronizedCounter, "Thread 2");

        threadedCount1.start();
        threadedCount2.start();

        try {
            threadedCount1.join();
            threadedCount2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

}
