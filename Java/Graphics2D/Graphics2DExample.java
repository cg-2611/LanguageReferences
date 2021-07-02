import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.geom.Arc2D;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;


import javax.swing.JFrame;
import javax.swing.SwingUtilities;

public class Graphics2DExample extends JFrame {

    private static final int WIDTH = 600;
    private static final int HEIGHT = 400;
    private static final String TITLE = "Graphics2D Example";

    public Graphics2DExample() {
        super();
        setSize(new Dimension(WIDTH, HEIGHT));
        setTitle(TITLE);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setLocationRelativeTo(null);
        setVisible(true);
    }

    private void drawLines(Graphics g) {
        Graphics2D g2d = (Graphics2D) g;

        g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        Shape line = new Line2D.Float(40, 140, 55, 250);
        g2d.draw(line);

        g2d.drawLine(40, 80, 120, 75);

        g2d.fillRect(200, 60, 100, 50);

        g2d.setColor(Color.YELLOW);
        g2d.fillOval(350, 150, 100, 50);

        Shape rectangle = new Rectangle.Float(300, 220, 150, 100);
        g2d.setColor(Color.MAGENTA);
        g2d.fill(rectangle);

        Shape ellipse = new Ellipse2D.Float(470, 270, 100, 100);
        g2d.setColor(Color.RED);
        g2d.draw(ellipse);

        Shape openArc = new Arc2D.Double(5, 250, 100, 100, 45, 180, Arc2D.OPEN);
        g2d.setColor(Color.BLUE);
        g2d.draw(openArc);

        Shape chordArc = new Arc2D.Double(5, 300, 100, 100, 45, 45, Arc2D.CHORD);
        g2d.setColor(Color.GREEN);
        g2d.draw(chordArc);

        Shape pieArc = new Arc2D.Double(5, 275, 250, 100, 45, 45, Arc2D.PIE);
        g2d.setColor(Color.ORANGE);
        g2d.fill(pieArc);
        g2d.setColor(Color.CYAN);
        g2d.draw(pieArc);
    }

    @Override
    public void paint(Graphics g) {
        super.paint(g);
        drawLines(g);
    }

    public static void main(String[] args) {
        // lambda expression equivalent to:
        // SwingUtilities.invokeLater(new Runnable() {
        // 	@Override
        // 	public void run() {
        // 		new Graphics2DExample();
        // 	}
        // });

        SwingUtilities.invokeLater(() -> {
            new Graphics2DExample();
        });
    }

}
