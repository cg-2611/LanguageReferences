public class Main {
    public static void main(String[] args) {
        System.out.println("Runtime Properties");
        System.out.println("------------------");
        System.out.println("Runtime version: " + RuntimeProperties.getRuntimeVersion());
        System.out.println("Number of available CPU cores: " + RuntimeProperties.getNumberOfCPUs());
        System.out.println("Total runtime memory: " + RuntimeProperties.getTotalRuntimeMemory());
        System.out.println("Maximum runtime memory: " + RuntimeProperties.getMaximumRuntimeMemory());
        System.out.println("Free runtime memory: " + RuntimeProperties.getFreeRuntimeMemory());
        System.out.println();
        
        System.out.println("System Properties");
        System.out.println("-----------------");
        System.out.println("OS name: " + SystemProperties.getOperatingSystemName());
        System.out.println("OS architecture: " + SystemProperties.getOperatingSystemArchitecture());
        System.out.println("OS version: " + SystemProperties.getOperatingSystemVersion());
        System.out.println("Java version: " + SystemProperties.getJavaVersion());
        System.out.println("Java home: " + SystemProperties.getJavaHome());
        System.out.println("User home directory: " + SystemProperties.getUserHomeDirectory());
        System.out.println("User country: " + SystemProperties.getUserCountry());
        System.out.println();

        System.out.println("Screen Properties");
        System.out.println("-----------------");
        System.out.println("Screen width in pixels: " + ScreenProperties.getScreenWidth());
        System.out.println("Screen height in pixels: " + ScreenProperties.getScreenHeight());
        System.out.println("Screen colour bit depth: " + ScreenProperties.getBitDepth());
        System.out.println();
    }
}
