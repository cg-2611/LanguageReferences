import java.awt.Dimension;

import javax.swing.JFrame;

public class Window {

    private int width;
    private int height;
    private String title;

    private JFrame frame;

    private Panel panel;

    public Window(int width, int height, String title) {
        this.width = width;
        this.height = height;
        this.title = title;

        frame = new JFrame();
        setWindowProperties();

        panel = new Panel(width, height);
        panel.setBounds(0, 0, panel.getWidth(), panel.getHeight());
        frame.add(panel);
    }

    private void setWindowProperties() {
        frame.setTitle(title);
        frame.setSize(new Dimension(width, height));
        frame.setResizable(false);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);
    }

    public JFrame getFrame() {
        return frame;
    }

}
