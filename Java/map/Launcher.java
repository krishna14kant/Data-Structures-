package Java.map;

public class Launcher {

    public static void main(String[] args) {
        HashMapImpl<String, Integer> myMap = new HashMapImpl<>();
        String keyA = "shane";
        String keyB = "brian";
        String keyC = "nashe";
        String keyD = "shane";

        myMap.put(keyA, 55);
        myMap.put(keyB, 70);
        myMap.put(keyC, 30);
        myMap.put(keyD, 0);

        Integer valA = myMap.get(keyA);
        Integer valB = myMap.get(keyB);
        Integer valC = myMap.get(keyC);
        Integer valD = myMap.get(keyD);

        System.out.printf("%d\n%d\n%d\n%d\n", valA, valB, valC, valD);
        System.out.printf("size: %d\n", myMap.size());

        valA = myMap.remove(keyA);
        valB = myMap.remove(keyB);
        valC = myMap.remove(keyC);
        valD = myMap.remove(keyD);

        System.out.printf("%d\n%d\n%d\n%d\n", valA, valB, valC, valD);
        System.out.printf("size: %d\n", myMap.size());
    }

}