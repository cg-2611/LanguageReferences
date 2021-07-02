import java.awt.GraphicsDevice;
import java.awt.GraphicsEnvironment;

public class ScreenProperties {

    private static GraphicsDevice device = GraphicsEnvironment.getLocalGraphicsEnvironment().getDefaultScreenDevice();

    private ScreenProperties() {}

    public static int getScreenWidth() {
        return device.getDisplayMode().getWidth();
    }

    public static int getScreenHeight() {
        return device.getDisplayMode().getHeight();
    }

    public static int getBitDepth() {
        return device.getDisplayMode().getBitDepth();
    }

}
