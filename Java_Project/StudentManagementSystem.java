package Academic_Project.Java_Project;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
class Student implements Serializable {
    private String name;
    private int id;
    private String school;
    private String college;
    private String hometown;
    private double cgpa;
    public Student(String name, int id, String school, String college, String hometown, double cgpa) {
        this.name = name;
        this.id = id;
        this.school = school;
        this.college = college;
        this.hometown = hometown;
        this.cgpa = cgpa;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getSchool() {
        return school;
    }
    public void setSchool(String school) {
        this.school = school;
    }
    public String getCollege() {
        return college;
    }
    public void setCollege(String college) {
        this.college = college;
    }
    public String getHometown() {
        return hometown;
    }
    public void setHometown(String hometown) {
        this.hometown = hometown;
    }
    public double getCgpa() {
        return cgpa;
    }
    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }
    public String toString() {
        return "Name: " + name + "\n" +
                "ID: " + id + "\n" +
                "School: " + school + "\n" +
                "College: " + college + "\n" +
                "Hometown: " + hometown + "\n" +
                "CGPA: " + cgpa + "\n";
    }
}

class StudentForm extends JFrame implements ActionListener {
    private List<Student> students;
    private int currentIndex;
    private JTextField nameField;
    private JTextField idField;
    private JTextField schoolField;
    private JTextField collegeField;
    private JTextField hometownField;
    private JTextField cgpaField;
    private JButton createButton;
    private JButton deleteButton;
    private JButton updateButton;
    private JButton nextButton;
    private JButton previousButton;
    private JButton sortByIdButton;
    private JButton sortByCgpaButton;
    private JButton sortByNameButton;
    private JButton displayButton;
       public StudentForm() {
        students = new ArrayList<>();
        currentIndex = -1;

        setTitle("Student Management System");
        setSize(400, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new GridLayout(8, 2));

        nameField = new JTextField();
        idField = new JTextField();
        schoolField = new JTextField();
        collegeField = new JTextField();
        hometownField = new JTextField();
        cgpaField = new JTextField();

        createButton = new JButton("Create");
        createButton.addActionListener(this);
        createButton.setBackground(Color.GREEN);  // Set background color to green

        deleteButton = new JButton("Delete");
        deleteButton.addActionListener(this);
        deleteButton.setBackground(Color.RED);  // Set background color to red

        updateButton = new JButton("Update");
        updateButton.addActionListener(this);
        updateButton.setBackground(Color.ORANGE);  // Set background color to orange

        nextButton = new JButton("Next");
        nextButton.addActionListener(this);
        nextButton.setBackground(Color.YELLOW);  // Set background color to yellow

        previousButton = new JButton("Previous");
        previousButton.addActionListener(this);
        previousButton.setBackground(Color.YELLOW);  // Set background color to yellow

        sortByIdButton = new JButton("Sort by ID");
        sortByIdButton.addActionListener(this);
        sortByIdButton.setBackground(Color.CYAN);  // Set background color to cyan

        sortByCgpaButton = new JButton("Sort by CGPA");
        sortByCgpaButton.addActionListener(this);
        sortByCgpaButton.setBackground(Color.CYAN);  // Set background color to cyan

        sortByNameButton = new JButton("Sort by Name");
        sortByNameButton.addActionListener(this);
        sortByNameButton.setBackground(Color.CYAN);  // Set background color to cyan

        displayButton = new JButton("Display Database");
        displayButton.addActionListener(this);
        displayButton.setBackground(Color.BLUE);  // Set background color to blue

        add(new JLabel("Name: "));
        add(nameField);
        add(new JLabel("ID: "));
        add(idField);
        add(new JLabel("School: "));
        add(schoolField);
        add(new JLabel("College: "));
        add(collegeField);
        add(new JLabel("Hometown: "));
        add(hometownField);
        add(new JLabel("CGPA: "));
        add(cgpaField);
        add(createButton);
        add(deleteButton);
        add(updateButton);
        add(nextButton);
        add(previousButton);
        add(sortByIdButton);
        add(sortByCgpaButton);
        add(sortByNameButton);
        add(displayButton);
    }
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == createButton) {
            createStudent();
        } else if (e.getSource() == deleteButton) {
            deleteStudent();
        } else if (e.getSource() == updateButton) {
            updateStudent();
        } else if (e.getSource() == nextButton) {
            nextStudent();
        } else if (e.getSource() == previousButton) {
            previousStudent();
        } else if (e.getSource() == sortByIdButton) {
            sortById();
        } else if (e.getSource() == sortByCgpaButton) {
            sortByCgpa();
        } else if (e.getSource() == sortByNameButton) {
            sortByName();
        } else if (e.getSource() == displayButton) {
            displayDatabase();
        }
    }

    private void createStudent() {
        String name = nameField.getText();
        int id = Integer.parseInt(idField.getText());
        String school = schoolField.getText();
        String college = collegeField.getText();
        String hometown = hometownField.getText();
        double cgpa = Double.parseDouble(cgpaField.getText());

        Student student = new Student(name, id, school, college, hometown, cgpa);
        students.add(student);

        try {
            ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("students.dat"));
            outputStream.writeObject(students);
            outputStream.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        clearFields();
    }

    private void deleteStudent() {
        if (currentIndex >= 0 && currentIndex < students.size()) {
            students.remove(currentIndex);

            try {
                ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("students.dat"));
                outputStream.writeObject(students);
                outputStream.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }

            currentIndex = -1;
            clearFields();
        }
    }

    private void updateStudent() {
        if (currentIndex >= 0 && currentIndex < students.size()) {
            Student student = students.get(currentIndex);
            student.setName(nameField.getText());
            student.setId(Integer.parseInt(idField.getText()));
            student.setSchool(schoolField.getText());
            student.setCollege(collegeField.getText());
            student.setHometown(hometownField.getText());
            student.setCgpa(Double.parseDouble(cgpaField.getText()));

            try {
                ObjectOutputStream outputStream = new ObjectOutputStream(new FileOutputStream("students.dat"));
                outputStream.writeObject(students);
                outputStream.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    private void nextStudent() {
        if (currentIndex < students.size() - 1) {
            currentIndex++;
            displayStudent(students.get(currentIndex));
        }
    }

    private void previousStudent() {
        if (currentIndex > 0) {
            currentIndex--;
            displayStudent(students.get(currentIndex));
        }
    }

    private void sortById() {
        Collections.sort(students, Comparator.comparingInt(Student::getId));
        displayDatabase();
    }

    private void sortByCgpa() {
        Collections.sort(students, Comparator.comparingDouble(Student::getCgpa));
        displayDatabase();
    }

    private void sortByName() {
        Collections.sort(students, Comparator.comparing(Student::getName));
        displayDatabase();
    }

    private void displayDatabase() {
        try {
            ObjectInputStream inputStream = new ObjectInputStream(new FileInputStream("students.dat"));
            students = (List<Student>) inputStream.readObject();
            inputStream.close();
        } catch (IOException | ClassNotFoundException ex) {
            ex.printStackTrace();
        }

        currentIndex = 0;
        if (!students.isEmpty()) {
            displayStudent(students.get(currentIndex));
        } else {
            clearFields();
        }
    }

    private void displayStudent(Student student) {
        nameField.setText(student.getName());
        idField.setText(String.valueOf(student.getId()));
        schoolField.setText(student.getSchool());
        collegeField.setText(student.getCollege());
        hometownField.setText(student.getHometown());
        cgpaField.setText(String.valueOf(student.getCgpa()));
    }

    private void clearFields() {
        nameField.setText("");
        idField.setText("");
        schoolField.setText("");
        collegeField.setText("");
        hometownField.setText("");
        cgpaField.setText("");
    }
}

public class StudentManagementSystem {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new StudentForm().setVisible(true);
            }
        });
    }
}