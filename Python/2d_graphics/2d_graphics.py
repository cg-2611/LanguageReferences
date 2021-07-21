import tkinter

from tkinter import constants


def draw_graphics(canvas: tkinter.Canvas) -> None:
    canvas.create_line(40, 140, 55, 250)
    canvas.create_line(40, 80, 120, 75, dash=(4, 2)) # creates a dashed line where each dash is 4px and each gap is 2px
    canvas.create_line(55, 85, 155, 85, 105, 180, 55, 85, fill="blue", smooth=False)
    canvas.create_line(55, 185, 155, 185, 105, 280, 55, 185, fill="green", smooth=True)
    canvas.create_rectangle(200, 60, 300, 110)
    canvas.create_oval(350, 150, 450, 200, outline="yellow", fill="yellow")
    canvas.create_rectangle(300, 220, 450, 320, fill="magenta")
    canvas.create_oval(470, 270, 570, 370, outline="red")
    canvas.create_arc(170, 300, 250, 200, start=0, extent=210, outline="blue", fill="purple", width=2)

    vertices = [400, 50, 475, 80, 500, 140, 500, 210, 580, 210, 500, 105, 450, 70, 350, 60, 400, 50]
    canvas.create_polygon(vertices, outline="orange", fill="green", width=2)

    canvas.create_text(200, 350, anchor=constants.W, font="{Comic Sans MS}", text="Example text in comic sans.")
    canvas.create_text(250, 370, anchor=constants.W, font="Arial", text="Example text drawn on canvas in Arial.")

    canvas.pack(fill=tkinter.BOTH, expand=1)


if __name__ == "__main__":
    root = tkinter.Tk()
    root.title("2D Graphics Example")
    root.geometry("600x400")

    frame = tkinter.Frame(root)
    frame.pack(fill=tkinter.BOTH, expand=1)

    canvas = tkinter.Canvas(frame)
    draw_graphics(canvas)

    root.mainloop()

