//****************************************************************************
// Title : Demonstrating the Dependency Inversion Principle (DIP)
// Author: Sarafat Karim
//         Undergraduate Student
//         Khulna University
//****************************************************************************

/**
 * Represents the abstraction of a data repository.
 */
interface DataRepository {
    /**
     * Fetches data from the repository.
     *
     * @return The fetched data.
     */
    String fetchData();
}

/**
 * Represents a concrete implementation of a data repository that fetches data from a database.
 */
class DatabaseRepository implements DataRepository {
    @Override
    public String fetchData() {
        return "Data from database";
    }
}

/**
 * Represents the business logic module that depends on a data repository.
 */
class BusinessLogic {
    private DataRepository dataRepository;

    /**
     * Constructs a BusinessLogic object with a data repository dependency.
     *
     * @param dataRepository The data repository dependency.
     */
    public BusinessLogic(DataRepository dataRepository) {
        this.dataRepository = dataRepository;
    }

    /**
     * Retrieves data using the injected data repository.
     *
     * @return The retrieved data.
     */
    public String retrieveData() {
        return dataRepository.fetchData();
    }
}

/**
 * Demonstrates the usage of the Dependency Inversion Principle (DIP).
 */
class DIP {
    public static void main(String[] args) {
        // Create a database repository and use it with BusinessLogic
        DataRepository databaseRepository = new DatabaseRepository();
        BusinessLogic businessLogic = new BusinessLogic(databaseRepository);
        System.out.println("Data retrieved: " + businessLogic.retrieveData());
    }
}

/**
 * In the above program, the BusinessLogic class depends on the abstraction provided by the DataRepository interface,
 * rather than depending directly on concrete implementations. This adherence to the Dependency Inversion Principle (DIP)
 * allows the BusinessLogic class to be decoupled from specific implementations of the data repository,
 * making the code more flexible and easier to maintain.
 */
