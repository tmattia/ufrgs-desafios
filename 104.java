import java.util.Scanner;

class Main {
    private int n;
    private double[][][] dist;
    private int[][][] next;

    public Main(int n) {
        this.n = n;
        dist = new double[n + 1][n + 1][n];
        next = new int[n + 1][n + 1][n];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j][0] = 1.0;
                next[i][j][0] = i;
            }
        }
    }

    public void conversion(int a, int b, double rate) {
        dist[a][b][0] = rate;
        next[a][b][0] = a;
    }

    public void arbitrage() {
        for (int d = 1; d < n; d++) {
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        double newRoute = dist[i][k][d - 1] * dist[k][j][0];
                        double currentRoute = dist[i][j][d];
                        if (newRoute > currentRoute) {
                            dist[i][j][d] = newRoute;
                            next[i][j][d] = k;
                        }
                    }
                }
            }
        }

        for (int d = 1; d < n; d++) {
            for (int i = 1; i <= n; i++) {
                if (dist[i][i][d] > 1.01) {
                    int[] path = new int[d + 1];
                    path[d] = next[i][i][d];
                    for (int j = d - 1; j >= 0; j--) {
                        path[j] = next[i][path[j + 1]][j];
                    }
                    for (int j = 0; j <= d; j++) {
                        System.out.print(path[j] + " ");
                    }
                    System.out.println(path[0]);
                    return;
                }
            }
        }

        System.out.println("no arbitrage sequence exists");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int n = scanner.nextInt();
            Main main = new Main(n);
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j) continue;
                    main.conversion(i, j, scanner.nextDouble());
                }
            }
            main.arbitrage();
        }
    }
}
