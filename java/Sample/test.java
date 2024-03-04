import java.util.Scanner;

interface Flyable {
    void fly();
}

interface Swimmable {
    void swim();
}

class FlyingFish implements Flyable, Swimmable {
    private String name;

    public FlyingFish(String name) {
        this.name = name;
    }

    @Override
    public void fly() {
        System.out.println(name + " can glide through the air");
    }

    @Override
    public void swim() {
        System.out.println(name + " can swim in water");
    }
}

public class Test {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String fishName = scanner.nextLine();

        FlyingFish flyingFish = new FlyingFish(fishName);

        flyingFish.fly();
        flyingFish.swim();

        scanner.close();
    }
}