import java.util.ArrayList;
public class Main {
    public static void main(String[] args) {
        System.out.println("Оригінальний текст");
        String text = "The quick brown fox jumps over the lazy dog. The old red car raced down the winding road. The tall oak tree stood strong against the gusty wind.";
        System.out.println("Зробити великими перші букви у кожному слові тексту");
        String capitalizedText = capitalize(text);
        System.out.println(capitalizedText);
        System.out.println("В тексті слова заданої довжини заміниті вказаним підрядком довільної довжини");
        String replacedText = replaceWords(text, "JAVA", 3);
        System.out.println(replacedText);
        System.out.println("Після кожного слова тексту, що закінчується заданим підрядком, вставити\n" +
                "вказане слово");
        String insertText = insertWord(text, "he", "JAVA");
        System.out.println(insertText);
        System.out.println("В тексті до кожного слова з довжиною, більшою за k символів, вставити заданий\n" +
                "підрядок після k-го символу,");
        System.out.println(insertAfterK(text, "!", 4));
        System.out.println("Утворити колекцію зі слів тексту, в яких перша і остання букви співпадають,");
        System.out.println(firstAndLastLetters(text));
        ArrayList maxWords = new ArrayList<>();

        ArrayList minWords = new ArrayList<>();
        findMaxAndMinWords(text, maxWords, minWords);
        System.out.println("Слова максимальної довжини:");
        System.out.println(maxWords);

        System.out.println("Слова мінімальної довжини:");
        System.out.println(minWords);

        System.out.println("В кожному реченні тексту поміняти місцями перше слово з останнім");
        String swapped = swapFirstAndLast(text);
        System.out.println(swapped);


    }
    public static String capitalize(String str) {
        String[] words = str.split(" ");
        // Перебираємо всі слова
        for (int i = 0; i < words.length; i++) {
            // Змінюємо першу букву на велику
            words[i] = words[i].substring(0, 1).toUpperCase() + words[i].substring(1);
        }
        return String.join(" ", words);

    }
    public static String replaceWords(String str, String replaceWord, int wordLength) {
        String[] words = str.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() == wordLength) {
                words[i]=replaceWord;
            }
        }
        return String.join(" ", words);
    }
    public static String insertWord(String str, String suffix, String insertedWord) {
        String[] words = str.split(" ");
        String insertedStr= "";
        for (int i = 0; i < words.length; i++) {
            insertedStr+=words[i] + " ";
            if((words[i].endsWith(suffix))&(i+1< words.length)){
                insertedStr+=insertedWord + " ";
            }
        }
        return insertedStr;
    }
    public static String insertAfterK(String str, String suffix, int k) {
        String[] words = str.split(" ");
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() > k) {
                words[i]=words[i].substring(0,k)+suffix+words[i].substring(k);
            }
        }
        return String.join(" ", words);
    }
    public static ArrayList firstAndLastLetters(String str) {
        String[] words = str.split(" ");
        ArrayList collection =new ArrayList();
        for (int i = 0; i < words.length; i++) {
            if (words[i].charAt(0) == words[i].charAt(words[i].length() - 1)) {
                collection.add(words[i]);
            }
        }

        return collection;
    }
    public static void findMaxAndMinWords(String text, ArrayList maxWords, ArrayList minWords) {
        String[] words = text.split("\\s+");
        int maxLength = Integer.MIN_VALUE;
        int minLength = Integer.MAX_VALUE;

        for (String word : words) {
            int length = word.length();
            if (length > maxLength) {
                maxWords.clear();
                maxWords.add(word);
                maxLength = length;
            } else if (length == maxLength) {
                maxWords.add(word);
            }

            if (length < minLength) {
                minWords.clear();
                minWords.add(word);
                minLength = length;
            } else if (length == minLength) {
                minWords.add(word);
            }
        }
    }
    public static String swapFirstAndLast(String str) {
        String[] sentences = str.split("\\.");
        String swappedStr="";
        for (int i = 0; i < sentences.length; i++) {
            String[] words = sentences[i].split(" ");
            String temp = words[0];
            words[0]=words[words.length-1];
            words[words.length-1]=temp;
            swappedStr += String.join(" ", words);
            swappedStr += ". ";

        }
        return swappedStr;
    }
}
