public class Main {
    public static void main(String[] args) {
        System.out.println("Програмне завдання 1:");
        System.out.println("Трикутник 1:");
        typeOne(10);
        System.out.println("Трикутник 2:");
        typeTwo(10);
        System.out.println("Трикутник 3:");
        typeThree(10);
        System.out.println("Трикутник 4:");
        typeFour(10);
        System.out.println("Прямокутник:");
        rectangle(6, 10);
        System.out.println("Програмне завдання 2:");
        System.out.println("Рівнобедрений трикутник:");
        isoscelesTriangle(6, '.', 0);
        System.out.println("Трапеція:");
        trapeze(2, 7);
        System.out.println("Програмне завдання 3:");
        System.out.println("Трикутник 1:");
        typeOne(6);
        typeTwo(6);
        System.out.println("Паралелограм 1:");
        typeOne(6);
        typeThree(6);
        System.out.println("Трикутник 2:");
        typeFour(6);
        typeThree(6);
        System.out.println("Паралелограм 2:");
        typeFour(6);
        typeTwo(6);
        System.out.println("Трапеція:");
        typeFour(6);
        rectangle(4, 6);
        typeThree(6);
        System.out.println("Паралелограм 3:");
        typeFour(6);
        rectangle(3, 6);
        typeTwo(6);
        System.out.println("Програмне завдання 4:");
        christmasTree(5, '*', 0);

    }
    public static void typeOne(int size) {
        for (int i= 0; i<size; i++) {
            for(int j=0; j<i; j++) {
                System.out.print(". ");
            }
            System.out.println();
        }

    }
    public static void typeTwo(int size) {
        for (int i= 0; i<size; i++) {
            for(int j=i; j<size; j++) {
                System.out.print(". ");
            }
            System.out.println();
        }
    }
    public static void typeThree(int size) {
        int i, j;
        for(i=0; i<size; i++) {
            for(j=0; j<i; j++) {
                System.out.print("  ");
            }
            for(j=i; j<size; j++) {
                System.out.print(". ");
            }
            System.out.println();
        }
    }
    public static void typeFour(int size) {
        for (int i= 0; i<=size; i++) {
            for(int j=i; j<size; j++) {
                System.out.print("  ");
            }
            for(int j=0; j<i; j++) {
                System.out.print(". ");
            }
            System.out.println();
        }
    }
    public static void rectangle(int height, int width) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                System.out.print(". ");
            }
            System.out.println();
        }
    }
    public static void isoscelesTriangle(int size, char symbol, int shift) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i + shift; j++) {
                System.out.print("  ");
            }
            for (int k = 0; k < 4 * i+1; k++) {
                System.out.print(symbol);
            }
            System.out.println();
        }
    }

    public static void trapeze(int size, int baseSize) {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - i; j++) {
                System.out.print(" ");
            }
            for (int k = 0; k < baseSize + 2 * i; k++) {
                System.out.print(".");
            }
            System.out.println();
        }
    }
    public static void christmasTree(int numTriangles, char symbol, int shift) {
        for (int i = 0; i < numTriangles; i++) {
            isoscelesTriangle(i + 2, symbol, numTriangles + shift-i);
        }
    }

}
