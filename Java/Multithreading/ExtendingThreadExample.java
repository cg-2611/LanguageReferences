public class ExtendingThreadExample extends Thread {

    private Thread thread;
    private String threadName;

    public ExtendingThreadExample(String threadName) {
        this.threadName = threadName;
        System.out.println("Created " + this.threadName);
    }

    public String getThreadName() {
        return threadName;
    }


    public void start() {
        System.out.println("Starting " + this.threadName + ": ");
        if (thread == null) {
            thread = new Thread(this, this.threadName);

            // calls run() method
            thread.start();
        }
    }

    @Override
    public void run() {
        try {
            for(int i = 3; i > 0; i--) {
                System.out.println("Thread " + this.threadName + ": " + i);

                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            // exception triggered when thread interrupted
            e.printStackTrace();
        }

        System.out.println("Thread " + this.threadName + " exited");
    }

}
