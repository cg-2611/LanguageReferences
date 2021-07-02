import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JSeparator;
import javax.swing.JTextField;
import javax.swing.SwingConstants;
import javax.swing.event.DocumentEvent;
import javax.swing.event.DocumentListener;

public class Panel extends JPanel {

    private int width;
    private int height;

    private JTextField textField;
    private JButton button;
    private JLabel label;
    private JSeparator separator;
    private JCheckBox checkBox;

    public Panel(int width, int height) {
        this.width = width;
        this.height = height;

        initializeComponents();
    }

    private void initializeComponents() {
        setLayout(null);

        // lambda expression can be replaced with:
        // addActionListener(new ActionListener() {
        //      public void actionPerformed(ActionEvent e) {
        //
        //      }
        // });

        textField = new JTextField("Enter text into the text field and press the button...");
        textField.setHorizontalAlignment(SwingConstants.CENTER);
        textField.setBounds(6, 52, 588, 26);
        add(textField);
        textField.getDocument().addDocumentListener(new DocumentListener(){

            @Override
            public void insertUpdate(DocumentEvent e) {
                if (!button.isEnabled()) {
                    label.setText(textField.getText());
                }
            }

            @Override
            public void removeUpdate(DocumentEvent e) {
                if (!button.isEnabled()) {
                    label.setText(textField.getText());
                }
            }

            @Override
            public void changedUpdate(DocumentEvent e) {}

        });

        button = new JButton("Button");
        button.setBounds(240, 130, 120, 30);
        add(button);
        button.addActionListener((e) -> {
            String textInput = textField.getText();
            if (textInput != null) {
                label.setText(textInput);
            }
            textField.setText("");
            textField.requestFocus();
        });

        label = new JLabel("Enter text into the text field and press the button...");
        label.setHorizontalAlignment(SwingConstants.CENTER);
        label.setBounds(6, 208, 588, 16);
        add(label);

        separator = new JSeparator();
        separator.setBounds(6, 307, 588, 12);
        add(separator);

        checkBox = new JCheckBox("Disable Button");
        checkBox.setToolTipText("When the button is disabled, the label will update automatically as text is input into the text field.");
        checkBox.setBounds(6, 331, 128, 23);
        add(checkBox);
        checkBox.addActionListener((e) -> {
            if (checkBox.isSelected()) {
                button.setEnabled(false);
            } else {
                button.setEnabled(true);
            }
        });
    }

    @Override
    public int getWidth() {
        return width;
    }

    @Override
    public int getHeight() {
        return height;
    }

}
