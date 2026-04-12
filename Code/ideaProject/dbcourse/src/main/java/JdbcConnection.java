import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Scanner;

public class JdbcConnection {

    private static Scanner scanner = new Scanner(System.in);
    private static final String DB_URL = "jdbc:mysql://localhost:3306/dbcourse";
    private static Connection connec;

    public static void main(String[] args) {
        login();
        searchTeacherName();

    }

    public static void login() {
        while (true) {
            System.out.println("Enter login ID: ");
            String uid = scanner.nextLine();
            System.out.println("Enter password: ");
            String pwd = scanner.nextLine();
            try {
                connec = DriverManager.getConnection(DB_URL, uid, pwd);
            } catch (SQLException e) {
                System.out.println("Login failed. Please try again.");
            }
        }
    }

    public static void searchTeacherName() {
        while (true) {
            System.out.println("Enter teacher name to search: ");
            String name = scanner.nextLine();
            String query = "SELECT ID, name FROM instructor WHERE name LIKE ?";
            try (PreparedStatement stmt = connec.prepareStatement(query)) {
                stmt.setString(1, "%" + name + "%");
                ResultSet rs = stmt.executeQuery();
                if (!rs.isBeforeFirst()) {
                    System.out.println("No teachers found with the name: " + name);
                } else {
                    System.out.println("Teachers found:");
                    while (rs.next()) {
                        System.out.println("Teacher ID: " + rs.getInt("id"));
                        System.out.println("Teacher Name: " + rs.getString("name"));
                        System.out.println("---------------------------");
                    }
                    break;
                }
            } catch (SQLException e) {
                System.out.println("Error executing query: " + e.getMessage());
            }
        }
        while (true) {
            System.out.println("Enter teacher ID (0-9999) to search: ");
            int id = Integer.parseInt(scanner.nextLine());
            if (id < 0 || id > 9999) {
                System.out.println("Invalid ID. Please enter a number between 0 and 9999.");
                continue;
            }
            String query = "SELECT ID FROM instructor WHERE id = ?";
            try (PreparedStatement stmt = connec.prepareStatement(query)) {
                stmt.setInt(1, id);
                ResultSet rs = stmt.executeQuery();
                if (!rs.isBeforeFirst()) {
                    System.out.println("No teacher found with ID: " + id);
                } else {
                    System.out.println("Teacher found with ID: " + id);
                    // Found if the teacher has taught any course
                    String courseQuery = "SELECT dept_name, course_id, title, sec_id, semester, year, " +
                            "(SELECT COUNT(*) FROM takes WHERE takes.course_id = teaches.course_id " +
                            "AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year) AS total_enrollment " +
                            "FROM teaches JOIN course ON teaches.course_id = course.course_id " +
                            "WHERE teaches.ID = ? " +
                            "ORDER BY dept_name, course_id, year, semester";
                    try (PreparedStatement courseStmt = connec.prepareStatement(courseQuery)) {
                        courseStmt.setInt(1, id);
                        ResultSet courseRs = courseStmt.executeQuery();
                        if (!courseRs.isBeforeFirst()) {
                            System.out.println("This teacher has not taught any courses.");
                        } else {
                            System.out.println("Courses taught by teacher ID " + id + ":");
                            while (courseRs.next()) {
                                System.out.println("Department: " + courseRs.getString("dept_name"));
                                System.out.println("Course ID: " + courseRs.getString("course_id"));
                                System.out.println("Title: " + courseRs.getString("title"));
                                System.out.println("Section ID: " + courseRs.getString("sec_id"));
                                System.out.println("Semester: " + courseRs.getString("semester"));
                                System.out.println("Year: " + courseRs.getInt("year"));
                                System.out.println("Total Enrollment: " + courseRs.getInt("total_enrollment"));
                                System.out.println("---------------------------");
                            }
                        }
                        break;
                    } catch (SQLException e) {
                        System.out.println("Error executing query: " + e.getMessage());
                    }
                }
            } catch (SQLException e) {
                System.out.println("Error executing query: " + e.getMessage());
            }
        }
    }
}
