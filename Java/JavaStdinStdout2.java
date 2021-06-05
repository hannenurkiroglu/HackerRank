import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int i    = scan.nextInt();
        double d = scan.nextDouble();
        scan.nextLine();
        String s = scan.nextLine();
        
        // Write your code here.

        System.out.println("String: " + s);
        System.out.println("Double: " + d);
        System.out.println("Int: " + i);
    }
}
/* If we write it like this; String s = scan.next();
    Output: Welcome // Wrong Answer.
   If we write it like this; String s = scan.nextLine();
    Output: //Empty
*/
