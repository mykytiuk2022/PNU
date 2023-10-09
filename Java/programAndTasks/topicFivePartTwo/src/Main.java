import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        int[] firstArray = randomArray(10);
        int[] secondArray = randomArray(10);
        System.out.println("Перший масив: ");
        printArray(firstArray);
        System.out.println("Другий масив: ");
        printArray(secondArray);
        System.out.println("\n Перший масив, розділений на дві колекції з від’ємних та додатніх чисел ");
        ArrayList negatives = new ArrayList<>();
        ArrayList positives = new ArrayList<>();

        splitArray(firstArray, negatives, positives);
        System.out.println("Від'ємні числа: ");
        System.out.println(negatives);
        System.out.println("Позитивні числа: ");
        System.out.println(positives);
        System.out.println("\nКолекція з елементів, що знаходяться в межах між значеннями середніх арифметичних");
        ArrayList rangeAverage = withinRangeArrays(firstArray, secondArray);
        System.out.println(rangeAverage);
        System.out.println("\nУтворити колекцію з масиву, в якому видалити дублікати максимума та мінімума");
        ArrayList deletedMinMax = mimMax(firstArray);
        System.out.println(deletedMinMax);
    }
    public static void printArray(int[] arr){
        for (int number : arr) {
            System.out.print(number + " ");
        }
        System.out.println();
    }
    public static int[] randomArray(int size){
        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            int num=(int) (Math.random()*-20+10);
            arr[i]= num;
        }
        return arr;
    }
    public static void splitArray(int[] initialArray, ArrayList negatives, ArrayList positives) {
        for (int num : initialArray) {
            if (num > 0) {
                positives.add(num);
            }
            else if (num < 0) {
                negatives.add(num);
            }
        }
    }
    public static double arrayAverage(int[] arr) {
        int sum = 0;
        for(int num: arr) {
            sum+=num;
        }
        return (double) (sum/arr.length);
    }
    public static ArrayList withinRangeArrays(int[] firstArr, int[] secondArr) {
        ArrayList rangeCollection = new ArrayList<>();
        double firstAverage = arrayAverage(firstArr);
        double secondAverage = arrayAverage(secondArr);
        double min = Math.min(firstAverage, secondAverage);
        double max = Math.max(firstAverage, secondAverage);
        System.out.println("Межі: [" + min + ";" + max + "]");
        for (int num : firstArr) {
            if ((num >= min) & (num <= max)) {
                rangeCollection.add(num);
            }
        }
        for (int num : secondArr) {
            if ((num >= min) & (num <= max)) {
                rangeCollection.add(num);
            }
        }
        return rangeCollection;
    }
    public static ArrayList mimMax(int[] arr) {
        ArrayList collection = new ArrayList<>();
        int min =  arr[0];
        int max =  arr[0];
        for (int num : arr) {
            if (num < min) {
                min = num;
            }
            if (num > max) {
                max = num;
            }
        }
        for (int num : arr) {
            if ((num == min && collection.contains(min)) || (num == max && collection.contains(max))) {
                continue;
            } else {
                collection.add(num);
            }

        }
        return collection;
    }


}
