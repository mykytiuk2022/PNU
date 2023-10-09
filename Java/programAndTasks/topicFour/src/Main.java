public class Main {
    public static void main(String[] args) {
        int []array=randomArray(10);
        System.out.println("Початковий масив");
        printArray(array);
        sumAndNumOfEven(array);
        minMax(array);
        int []increaseAndDecrease=increasePositivesAndDecreaseNegatives(array);
        System.out.println("Збільшити на одиницю додатні елементи масиву та зменшити на одиницю від’ємні елементи масиву");
        printArray(increaseAndDecrease);
        int []swappedArray=swapMinMax(array);
        System.out.println("Поміняти місцями максимум та мінімум");
        printArray(swappedArray);
        int []removedArray = removeMinMax(array);
        System.out.println("Усунути максимум та мінімум");
        printArray(removedArray);
        averageAndAmount(array);
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
            boolean alreadyThere=false;
            int num=(int) (Math.random()*-20+10);
            for (int j = 0; j < i; j++) {
                if (arr[j] == num) {
                    alreadyThere = true;
                    break;
                }
            }
            if(!alreadyThere){
                arr[i]=num;
            } else {
                i--;
            }
        }
        return arr;
    }
    public static void sumAndNumOfEven(int[] arr){
        int evenSum=0, evenNum=0;
        for (int num : arr) {
            if(num%2==0) {
                evenNum++;
                evenSum+=num;
            }
        }
        System.out.println("Кількість парних чисел:" + evenNum+ ", їхня сума:" + evenSum);
    }
    public static void minMax(int[] arr){
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int num : arr){
            if (num < 0 && num > max) {
                max = num;
            } else if (num > 0 && num < min) {
                min = num;
            }

        }
        System.out.println("Максимальний від'ємний елемент: " + max);
        System.out.println("Мінімальний додатній елемент: " + min);
    }
    public static int[] increasePositivesAndDecreaseNegatives(int[] arr){
        int[] newArr=new int[arr.length];
        for (int i = 0; i < arr.length; i++) {
            if(arr[i]>0){
                newArr[i]=arr[i]+1;
            } else if (arr[i]<0) {
                newArr[i]=arr[i]-1;
            }
            else {
                newArr[i]=arr[i];
            }
        }
        return newArr;
    }
    public static int[] swapMinMax(int[] arr){
        int[] newArr=new int[arr.length];
        int minPos=0;
        int maxPos=0;

        for (int i = 0; i < arr.length; i++) {
                if (arr[i]<arr[minPos]){
                    minPos=i;
                }
                if (arr[i]>arr[maxPos]) {
                    maxPos = i;
                }
            newArr[i]=arr[i];
        }
        int temp=newArr[minPos];
        newArr[minPos]=newArr[maxPos];
        newArr[maxPos]=temp;
        return newArr;
    }
    public static int[] removeMinMax(int[]arr){
        int minPos=0;
        int maxPos=0;
        int[] newArr=new int[arr.length-2];
        for (int i = 0; i < arr.length; i++) {
            if (arr[i]<arr[minPos]){
                minPos=i;
            }
            if (arr[i]>arr[maxPos]) {
                maxPos = i;
            }

        }
        for (int i = 0, j=0; i < arr.length; i++) {
            if((i != minPos)& (i !=maxPos)) {
                newArr[j] = arr[i];
                j++;
            }
        }
        return newArr;
    }
    public static void averageAndAmount(int[]arr){
        double sum=0;
        for (int num : arr) {
            sum+=num;
        }
        int higherAverage=0;
        for (int num : arr) {
            if(num>(sum/arr.length)){
                higherAverage++;
            }
        }
        System.out.println("Середнє арифметичне:" + sum/arr.length+", кількість елементів, що є більшими за середнє арифметичне:" + higherAverage);
    }
}


