public class MultithreadingMain {
	public static void main(String[] args) {
		RunnableExample runnable1 = new RunnableExample("Runnable Thread 1");
		RunnableExample runnable2 = new RunnableExample("Runnable Thread 2");
		ExtendingThreadExample extendingThread1 = new ExtendingThreadExample("Extending Thread 1");
		ExtendingThreadExample extendingThread2 = new ExtendingThreadExample("Extending Thread 2");

		runnable1.start();
		runnable2.start();
		extendingThread1.start();
		extendingThread2.start();

		try {
			runnable1.getThread().join();
			runnable2.getThread().join();
			extendingThread1.join();
			extendingThread2.join();
		} catch (InterruptedException e) {
			e.printStackTrace();
		}

		System.out.println("All threads joined");
	}
}