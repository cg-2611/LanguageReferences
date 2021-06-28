package example;

import javafx.geometry.Orientation;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.control.CheckBox;
import javafx.scene.control.Label;
import javafx.scene.control.Separator;
import javafx.scene.control.TextField;
import javafx.scene.control.Tooltip;
import javafx.scene.layout.Pane;

public class Panel extends Pane {
    
    private TextField textField;
    private Button button;
    private Label label;
    private Separator separator;
    private CheckBox checkBox;

    public Panel() {
        initializeComponents();
    }

    private void initializeComponents() {
        // lambda expressions equivalent to:
        // button.setOnAction(new EventHandler<ActionEvent>() {
        //		@Override
        //		public void handle(ActionEvent event) {
        //
        //		}
        //	});

        textField = new TextField("Enter text into the text field and press the button...");
        textField.relocate(6, 92);
        textField.setPrefSize(588, 26);
        textField.setAlignment(Pos.CENTER);
        textField.setOnKeyTyped((e) -> {
            if (button.isDisabled()) {
                label.setText(textField.getText());
            }
        });

        button = new Button("Button");
        button.relocate(240, 170);
        button.setPrefSize(120, 30);
        button.setOnAction((e) -> {
            String textInput = textField.getText();
            if(textInput != null) {
                label.setText(textInput);
            }
            textField.setText("");
            textField.requestFocus();
        });

        label = new Label("Enter text into the text field and press the button...");
        label.relocate(6, 248);
        label.setPrefSize(588, 16);
        label.setAlignment(Pos.CENTER);

        separator = new Separator(Orientation.HORIZONTAL);
        separator.relocate(6, 347);
        separator.setPrefSize(588, 12);

        checkBox = new CheckBox("Disable Button");
        checkBox.relocate(6, 371);
        checkBox.setPrefSize(128, 23);
        checkBox.setTooltip(new Tooltip("When the button is disabled, the label will update automatically as text is input into the text field."));
        checkBox.setOnAction((e) -> {
            if(checkBox.isSelected()) {
                button.setDisable(true);
            } else {
                button.setDisable(false);
            }
        });

        getChildren().addAll(textField, button, label, separator, checkBox);
    }

}