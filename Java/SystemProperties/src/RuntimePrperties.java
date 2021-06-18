public class RuntimePrperties {

    private RuntimePrperties() {}

    public static String getRuntimeVersion() {
        return Runtime.version().toString();
    }
    
    public static int getNumberofCPUs() {
        return Runtime.getRuntime().availableProcessors();
    }

    public static long getTotalRuntimeMemory() {
        return Runtime.getRuntime().totalMemory();
    }

    public static long getMaximumRuntimeMemory() {
        return Runtime.getRuntime().maxMemory();
    }

    public static long getFreeRuntimeMemory() {
        return Runtime.getRuntime().freeMemory();
    }


}
