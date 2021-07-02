public class ThreadedCount extends Thread {

    private Counter counter;
    private String threadName;

    public ThreadedCount(Counter counter, String threadName) {
        this.counter = counter;
        this.threadName = threadName;
    }

    public String getThreadName() {
        return threadName;
    }

    @Override
    public void run() {
        // only one counter may run at a time
        synchronized(counter) {
            for (int i = 0; i < 10; i++) {
                if (i % 2 == 0) {
                    counter.incrementByThree();
                    System.out.println(threadName + " - Counter incremented by 3 to: " + counter.getCount());
                } else {
                    counter.decrementByTwo();
                    System.out.println(threadName + " - Counter decremented by 2 to: " + counter.getCount());
                }
            }
        }
    }

}
