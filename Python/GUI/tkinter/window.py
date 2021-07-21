import tkinter

from tkinter import constants, ttk

# use tkmacosx package for improved support fot tkinter on macos such as button colours
# ttk used where there are text colour problems on macos

class Window:
    def __init__(self, width: int, height: int, title: str) -> None:
        self.width = width
        self.height = height
        self.title = title

        self.window = tkinter.Tk()
        self.window_frame = tkinter.Frame(self.window)

        self.__set_window_properties()
        self.__initialize_window()

    def __set_window_properties(self) -> None:
        self.window.title(self.title)
        self.window.geometry(f"{self.width}x{self.height}")

        # allows frame to take full space of window
        self.window_frame.pack(fill=tkinter.BOTH, expand=1)

    def __initialize_window(self) -> None:
        self.text_field = tkinter.Entry(self.window_frame, justify=tkinter.CENTER)
        self.text_field.place(x=6, y=92, width=588, height=26)

        self.button = ttk.Button(self.window_frame, text="Button", command=lambda: self.__button_click())
        self.button.place(x=240, y=170, width=120, height=30)

        self.label = tkinter.Label(self.window_frame, text="Enter text into the text field and press the button...")
        self.label.place(x=6, y=248, width=588, height=16)

        # use a frame of width 1 as a separator, can also use ttk.Separator
        self.separator = tkinter.Frame(self.window_frame, bg="gray", width=1, bd=0)
        self.separator.place(x=6, y=347, width=588, height=1)

        self.check_box = ttk.Checkbutton(self.window_frame, text="Disable Button", command=lambda: self.__check_box_toggle())
        self.check_box.place(x=6, y=371, width=128, height=23)

        # call __entry_update method when a key is released
        self.text_field.bind("<KeyRelease>", self.__entry_update)

    # although it is not used, the second parameter is necessary
    def __entry_update(self, _) -> None:
        if "disabled" in self.button.state():
            # can also use self.label.configure(text=new_text) or a StringVar
            self.label["text"] = self.text_field.get()

    def __button_click(self) -> None:
        text_input = self.text_field.get()
        if text_input is not None:
            self.label["text"] = text_input # can also use self.label.configure(text=new_text) or a StringVar

        self.text_field.delete(0, constants.END)
        self.text_field.focus()

    def __check_box_toggle(self) -> None:
        if "selected" in self.check_box.state():
            self.button["state"] = "disabled"
        else:
            self.button["state"] = "normal"

    def run(self) -> None:
        self.window.mainloop()
