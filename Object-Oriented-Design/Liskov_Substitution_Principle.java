//****************************************************************************
// Title : Demonstrating the Liskov Substitution Principle (LSP) in Java
// Author: Sarafat Karim
//         Undergraduate Student
//         Khulna University
//****************************************************************************

/**
 * Represents a shape with a method to calculate its area.
 */
interface Shape {
    /**
     * Calculates the area of the shape.
     *
     * @return The area of the shape.
     */
    double area();
}

/**
 * Represents a rectangle shape.
 */
class Rectangle implements Shape {
    private double width;
    private double height;

    /**
     * Constructs a new rectangle with the given width and height.
     *
     * @param width  The width of the rectangle.
     * @param height The height of the rectangle.
     */
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }

    @Override
    public double area() {
        return width * height;
    }
}

/**
 * Represents a square shape, which is a special case of a rectangle.
 */
class Square implements Shape {
    private double side;

    /**
     * Constructs a new square with the given side length.
     *
     * @param side The length of each side of the square.
     */
    public Square(double side) {
        this.side = side;
    }

    @Override
    public double area() {
        return side * side;
    }
}

/**
 * Calculates the total area of shapes.
 */
class AreaCalculator {
    /**
     * Calculates the total area of an array of shapes.
     *
     * @param shapes The array of shapes.
     * @return The total area of all shapes.
     */
    public double calculateTotalArea(Shape[] shapes) {
        double totalArea = 0;
        for (Shape shape : shapes) {
            totalArea += shape.area();
        }
        return totalArea;
    }
}

/**
 * Demonstrates the usage of shapes and area calculation.
 */
class LSPDemo {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Rectangle(5, 4),
            new Square(3)
        };

        AreaCalculator calculator = new AreaCalculator();
        double totalArea = calculator.calculateTotalArea(shapes);
        System.out.println("Total area: " + totalArea);
    }
}

/**
 * In the above program, both Rectangle and Square classes implement the Shape interface.
 * The LSP is maintained because the Square class, which is a subtype of Rectangle, can
 * be substituted for a Rectangle without affecting the correctness of the program.
 */

