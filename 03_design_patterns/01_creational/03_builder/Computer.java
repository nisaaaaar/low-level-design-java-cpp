public class Computer {
    // Required parameters
    private String CPU;
    private String RAM;

    // Optional parameters
    private boolean hasGraphicsCard;
    private boolean hasBluetooth;

    // Private constructor
    private Computer(Builder builder) {
        this.CPU = builder.CPU;
        this.RAM = builder.RAM;
        this.hasGraphicsCard = builder.hasGraphicsCard;
        this.hasBluetooth = builder.hasBluetooth;
    }

    public String toString() {
        return "Computer [CPU=" + CPU + ", RAM=" + RAM +
                ", GraphicsCard=" + hasGraphicsCard + ", Bluetooth=" + hasBluetooth + "]";
    }

    // Static nested Builder class
    public static class Builder {
        // Required
        private String CPU;
        private String RAM;

        // Optional
        private boolean hasGraphicsCard;
        private boolean hasBluetooth;

        public Builder(String CPU, String RAM) {
            this.CPU = CPU;
            this.RAM = RAM;
        }

        public Builder setGraphicsCard(boolean hasGraphicsCard) {
            this.hasGraphicsCard = hasGraphicsCard;
            return this;
        }

        public Builder setBluetooth(boolean hasBluetooth) {
            this.hasBluetooth = hasBluetooth;
            return this;
        }

        public Computer build() {
            return new Computer(this);
        }
    }
}