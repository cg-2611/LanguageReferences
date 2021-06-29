public class UnsynchronizedCounter implements Counter {
    
    private int count;

    public UnsynchronizedCounter() {
        this.count = 0;
    }

    public void incrementByThree() {
        count += 3;
    }

    public void decrementByTwo() {
        count -= 2;
    }

    public int getCount() {
        return count;
    }

}
