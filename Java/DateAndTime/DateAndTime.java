import java.time.DayOfWeek;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.time.Month;
import java.time.Year;
import java.time.format.DateTimeFormatter;

public class DateAndTime {

    public static void main(String[] args) {
        LocalDate date = LocalDate.now();             // can also use LocalDate.of(year, month, dayOfMonth);
        LocalTime time = LocalTime.now();             // can also use LocalTime.of(hour, minute, second);
        LocalDateTime dateTime = LocalDateTime.now(); // other constructors available
        DateTimeFormatter dateTimeFormatter;

        System.out.println("Local Date: " + date);
        System.out.println("Local Time: " + time);

        System.out.println("\nLocal Date and Time: " + dateTime);

        dateTimeFormatter = DateTimeFormatter.ofPattern("dd-MM-yyy HH:mm:ss"); // supports many formats
        String formattedDateTime = dateTimeFormatter.format(dateTime);
        System.out.println("Formatted Local Date and Time: " + formattedDateTime);

        dateTimeFormatter = DateTimeFormatter.ofPattern("dd MMM YYYY HH:mm:ss");
        formattedDateTime = dateTimeFormatter.format(dateTime);
        System.out.println("Formatted Local Date and Time: " + formattedDateTime);

        System.out.println();

        DayOfWeek dayOfWeek = DayOfWeek.from(date);
        System.out.println(dayOfWeek.name() + " has value: " + dayOfWeek.getValue());

        Month month = Month.from(date);
        System.out.println(month.name() + " has value: " + month.getValue());

        Year year = Year.from(date);
        System.out.println("Is " + year.getValue() + " a leap year: " + year.isLeap());
        System.out.println("Length of " + year.getValue() + ": " + year.length() + " days");
    }

}
