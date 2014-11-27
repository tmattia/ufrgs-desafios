import java.util.*;
import java.io.*;
import java.util.regex.Pattern;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int expected = scanner.nextInt();
            int open = 0;
            int node = 0;
            int sign = 1;
            int sum = 0;
            int emptyNodes = 0;
            char prev = 'a';
            boolean found = false;
            Stack<Integer> stack = new Stack<Integer>();

            scanner.useDelimiter("");
            while (scanner.hasNext()) {
                char c = scanner.next().charAt(0);
                if (c == '(') {
                    if (open > 0 && prev != ')') {
                        sum += node;
                        stack.push(node);
                        node = 0;
                        sign = 1;
                    }
                    open++;

                } else if (c == ')') {
                    if (prev == '(') {
                        emptyNodes++;
                    } else {
                        sum -= stack.pop();
                        emptyNodes = 0;
                    }

                    if (emptyNodes == 2) {
                        if (sum == expected) found = true;
                        emptyNodes = 0;
                    }

                    open--;
                    if (open == 0) {
                        break;
                    }

                } else if (c == '-') {
                    sign = -1;

                } else if (c >= '0' && c <= '9') {
                    node = (node * 10) + sign * (c - 48);
                    emptyNodes = 0;
                }


                if (c == '(' || c == ')' || c == '-' || (c >= '0' && c <= '9')) prev = c;
            }

            System.out.println(found ? "yes" : "no");

            scanner.useDelimiter("\\s");
        }
    }
}
