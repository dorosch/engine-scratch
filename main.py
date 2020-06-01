from tkinter import Tk, Canvas, PhotoImage, mainloop


class Color:
    BLACK = '#000000'
    WHITE = '#ffffff'


class CustomCanvas(Canvas):
    """Class for drawing on canvas by pixels (simple as much as possible)

    >>> canvas = CustomCanvas()
    >>> canvas.draw(50, 42)
    >>> canvas.display()
    """

    def __init__(self, width=800, height=800):
        # Define a window for displaying drawing results
        self.window = Tk()

        # You cannot access to a pixel on a canvas that is why
        # we define an image for drawing by pixels
        self.image = PhotoImage(width=width, height=height)

        # We initialize the canvas and create the image into it
        super().__init__(
            self.window, width=width, height=height, bg=Color.BLACK
        )
        self.create_image((width, height), image=self.image)
        self.pack()

    def draw(self, x, y, color=Color.WHITE):
        self.image.put(color, (x, y))

    @staticmethod
    def display():
        mainloop()


if __name__ == '__main__':
    canvas = CustomCanvas()

    canvas.draw(50, 42)
    canvas.draw(73, 36)
    canvas.draw(44, 61)

    canvas.display()
