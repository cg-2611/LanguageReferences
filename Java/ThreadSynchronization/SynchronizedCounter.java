public class SynchronizedCounter implements Counter{
    
    private int count;

    public SynchronizedCounter() {
        this.count = 0;
    }

    public synchronized void incrementByThree() {
        count += 3;
    }
    
    
    public synchronized void decrementByTwo() {
        count -= 2;
    }
    
    public synchronized int getCount() {
        return count;
    }
    
    // equivalent methods lock the object and allow for only part of a method to be 
    // synchronized rather than the whole method

    // public void incrementByThree() {
    //     synchronized(this) {
    //         count += 3;
    //     }
    // }

    // public synchronized void decrementByTwo() {
    //     synchronized(this) {
    //         count -= 2;
    //     }
    // }
    
    // public synchronized int getCount() {
    //     synchronized(this) {
    //         return count;
    //     }
    // }
}