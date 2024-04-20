//****************************************************************************
// Title : Demonstrating the Open/Closed Principle (OCP) in Java
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
 * Represents a circle shape.
 */
class Circle implements Shape {
    private double radius;

    /**
     * Constructs a new circle with the given radius.
     *
     * @param radius The radius of the circle.
     */
    public Circle(double radius) {
        this.radius = radius;
    }

    @Override
    public double area() {
        return Math.PI * radius * radius;
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
class Open_Closed_Principal {
    public static void main(String[] args) {
        Shape[] shapes = {
            new Rectangle(5, 4),
            new Circle(3)
        };

        AreaCalculator calculator = new AreaCalculator();
        double totalArea = calculator.calculateTotalArea(shapes);
        System.out.println("Total area: " + totalArea);
    }
}

/**
 * In the above program, the AreaCalculator class is closed for modification but
 * open for extension. It can work with any new shapes that implement the Shape interface
 * without needing any changes to its existing code, adhering to the Open/Closed Principle (OCP).
 */
