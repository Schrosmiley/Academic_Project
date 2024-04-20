//****************************************************************************
// Title : Demonstrating the Interface Segregation Principle (ISP)
// Author: Sarafat Karim
//         Undergraduate Student
//         Khulna University
//****************************************************************************

/**
 * Represents a device that can connect to a network.
 */
interface NetworkDevice {
    /**
     * Connects the device to a network.
     */
    void connectToNetwork();

    /**
     * Disconnects the device from the network.
     */
    void disconnectFromNetwork();
}

/**
 * Represents a device that can connect to a printer.
 */
interface PrinterDevice {
    /**
     * Connects the device to a printer.
     */
    void connectToPrinter();

    /**
     * Disconnects the device from the printer.
     */
    void disconnectFromPrinter();

    /**
     * Prints a document.
     *
     * @param document The document to be printed.
     */
    void printDocument(String document);
}

/**
 * Represents a computer that can connect to both a network and a printer.
 */
class Computer implements NetworkDevice, PrinterDevice {
    @Override
    public void connectToNetwork() {
        System.out.println("Connected to network");
    }

    @Override
    public void disconnectFromNetwork() {
        System.out.println("Disconnected from network");
    }

    @Override
    public void connectToPrinter() {
        System.out.println("Connected to printer");
    }

    @Override
    public void disconnectFromPrinter() {
        System.out.println("Disconnected from printer");
    }

    @Override
    public void printDocument(String document) {
        System.out.println("Printing document: " + document);
    }
}

/**
 * Demonstrates the usage of a computer that can connect to both a network and a printer.
 */
class ISP {
    public static void main(String[] args) {
        // Create a computer and connect it to the network and printer
        Computer computer = new Computer();
        computer.connectToNetwork();
        computer.connectToPrinter();
        computer.printDocument("Test document");

        // Disconnect computer from the network and printer
        computer.disconnectFromNetwork();
        computer.disconnectFromPrinter();
    }
}

/**
 * In the above program, the NetworkDevice interface represents the responsibility
 * of connecting to and disconnecting from a network, while the PrinterDevice
 * interface represents the responsibility of connecting to a printer, disconnecting
 * from a printer, and printing a document. The Computer class implements both
 * interfaces, adhering to the Interface Segregation Principle (ISP) by implementing
 * only the methods relevant to its specific responsibilities.
 */
