public class BuilderPatternDemo {
    public static void main(String[] args) {
        Computer gamingPC = new Computer.Builder("Intel i9", "32GB")
                                .setGraphicsCard(true)
                                .setBluetooth(true)
                                .build();

        Computer officePC = new Computer.Builder("Intel i5", "16GB")
                                .setGraphicsCard(false)
                                .setBluetooth(true)
                                .build();

        System.out.println(gamingPC);
        System.out.println(officePC);
    }
}
