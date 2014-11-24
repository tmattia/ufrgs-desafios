import java.util.Scanner;

class Main {
    private class Node {
        public int value;
        public Node next;

        public Node(int v, Node n) {
            value = v;
            next = n;
        }
    }

    private class Stack {
        private Node first;

        public void push(int n) {
            Node newNode = new Node(n, first);
            first = newNode;
        }

        public int pop() {
            if (isEmpty()) {
                throw new IllegalStateException("pop from empty stack");
            }
            int value = first.value;
            first = first.next;
            return value;
        }

        public int peek() {
            if (isEmpty()) {
                throw new IllegalStateException("peek from empty stack");
            }
            return first.value;
        }

        public boolean isEmpty() {
            return first == null;
        }
    }

    public void testStack() {
        Stack stack = new Stack();
        assert stack.isEmpty() : "stack with no elements should be empty";

        stack.push(10);
        assert !stack.isEmpty() : "stack with one element should not be empty";
        assert stack.peek() == 10 : "peek should return top of stack";
        assert stack.pop() == 10 : "stack should have LIFO access pattern";

        stack.push(1);
        stack.push(2);
        stack.push(3);
        assert stack.pop() == 3 : "stack should have LIFO access pattern";
        assert stack.pop() == 2 : "stack should have LIFO access pattern";
        assert stack.pop() == 1 : "stack should have LIFO access pattern";
        assert stack.isEmpty() : "stack with no elements should be empty";

        try {
            stack.peek();
            assert false : "can't peek empty stack";
        } catch (IllegalStateException e) { assert true; }

        try {
            stack.pop();
            assert false : "can't pop empty stack";
        } catch(IllegalStateException e) { assert true; }
    }


    private int n;
    private Stack[] stacks;
    private int[] positions;

    public Main(int n) {
        this.n = n;
        positions = new int[n];
        stacks = new Stack[n];
        for (int i = 0; i < n; i++) {
            stacks[i] = new Stack();
            stacks[i].push(i);
            positions[i] = i;
        }
    }

    private void returnTop(int a) {
        assert !stacks[positions[a]].isEmpty();

        while (stacks[positions[a]].peek() != a) {
            int x = stacks[positions[a]].pop();
            stacks[x].push(x);
            positions[x] = x;
        }
    }

    private boolean illegalMove(int a, int b) {
        return a == b || positions[a] == positions[b];
    }

    public void moveOnto(int a, int b) {
        if (illegalMove(a, b)) return;

        returnTop(b);
        moveOver(a, b);
    }

    public void moveOver(int a, int b) {
        if (illegalMove(a, b)) return;

        returnTop(a);
        stacks[positions[b]].push(stacks[positions[a]].pop());
        positions[a] = positions[b];
    }

    public void pileOnto(int a, int b) {
        if (illegalMove(a, b)) return;

        returnTop(b);
        pileOver(a, b);
    }

    public void pileOver(int a, int b) {
        if (illegalMove(a, b)) return;

        Stack reverse = new Stack();
        while(stacks[positions[a]].peek() != a) {
            reverse.push(stacks[positions[a]].pop());
        }
        reverse.push(stacks[positions[a]].pop());

        while(!reverse.isEmpty()) {
            int x = reverse.pop();
            stacks[positions[b]].push(x);
            positions[x] = positions[b];
        }
    }

    public void print() {
        for (int i = 0; i < n; i++) {
            System.out.print(i + ":");
            if (!stacks[i].isEmpty()) System.out.print(" ");

            Stack reverse = new Stack();
            while (!stacks[i].isEmpty()) {
                reverse.push(stacks[i].pop());
            }

            while(!reverse.isEmpty()) {
                System.out.print(reverse.pop());
                if (!reverse.isEmpty()) System.out.print(" ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        Main main = new Main(n);
        main.testStack();

        while (true) {
            String command = scanner.next();
            if (command.compareTo("quit") == 0) {
                main.print();
                return;
            }

            int a = scanner.nextInt();
            String position = scanner.next();
            int b = scanner.nextInt();
            if (command.compareTo("move") == 0) {
                if (position.compareTo("onto") == 0) {
                    main.moveOnto(a, b);
                } else {
                    main.moveOver(a, b);
                }
            } else {
                if (position.compareTo("onto") == 0) {
                    main.pileOnto(a, b);
                } else {
                    main.pileOver(a, b);
                }
            }
        }
    }
}
