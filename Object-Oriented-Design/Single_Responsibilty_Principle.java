//****************************************************************************
// Title : Demonstrating the Single Responsibility Principle (SRP)
// Author: Sarafat Karim
//         Undergraduate Student
//         Khulna University
//****************************************************************************


/**
 * This class represents an EmailSender responsible for sending emails.
 */
class EmailSender {
    /**
     * Sends an email to the specified recipient with the given subject and message.
     *
     * @param recipient The recipient's email address.
     * @param subject   The subject of the email.
     * @param message   The message content of the email.
     */
    public void sendEmail(String recipient, String subject, String message) {
        // Code to send email goes here
        System.out.println("Email sent to: " + recipient);
        System.out.println("Subject: " + subject);
        System.out.println("Message: " + message);
    }
}

/**
 * This class demonstrates the usage of EmailSender class.
 */
class SRP {
    public static void main(String[] args) {
        // Create an instance of EmailSender
        EmailSender emailSender = new EmailSender();

        // Prepare email details
        String recipient = "example@example.com";
        String subject = "Test Email";
        String message = "This is a test email.";

        // Send the email using EmailSender
        emailSender.sendEmail(recipient, subject, message);
    }
}

/**
 * In the above program, the EmailSender class has a single responsibility
 * of sending emails. The SRP class demonstrates the usage of EmailSender
 * class without involving in the email sending process itself, thus adhering
 * to the Single Responsibility Principle (SRP).
 */
