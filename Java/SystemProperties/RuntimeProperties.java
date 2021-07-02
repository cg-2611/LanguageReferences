public class RuntimeProperties {

    private RuntimeProperties() {}

    public static String getRuntimeVersion() {
        return Runtime.version().toString();
    }

    public static int getNumberOfCPUs() {
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
