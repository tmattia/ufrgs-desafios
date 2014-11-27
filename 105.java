import java.util.Scanner;

class Main {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int[] heights = new int[10000];
    for (int i = 0; i < 10000; i++) heights[i] = 0;
    int n = 0;
    while (scanner.hasNextInt()) {
      int start = scanner.nextInt();
      int height = scanner.nextInt();
      int end = scanner.nextInt();
      if (end > n) n = end;
      for (int i = start - 1; i < end - 1; i++) {
        if (heights[i] < height) heights[i] = height;
      }
    }

    int currentHeight = 0;
    for (int i = 0; i < n; i++) {
      if (heights[i] != currentHeight) {
        System.out.print(i + 1);
        currentHeight = heights[i];
        if (i == n - 1) System.out.print(" " + currentHeight);
        else System.out.print(" " + currentHeight + " ");
      }
    }
    System.out.println();
  }
}
