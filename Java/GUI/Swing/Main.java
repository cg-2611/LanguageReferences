import javax.swing.SwingUtilities;
import javax.swing.UIManager;

public class Main {

    public static final int WIDTH = 600;
    public static final int HEIGHT = 400;
    public static final String TITLE = "Swing Example";

    private Window window;

    public Main() {
        window = new Window(WIDTH, HEIGHT, TITLE);
    }

    public void start() {
        window.getFrame().setVisible(true);
    }

    public static void main(String[] args) {
        try {
            Main main = new Main();

            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());

            SwingUtilities.invokeLater(() -> {
                main.start();
            });
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
}