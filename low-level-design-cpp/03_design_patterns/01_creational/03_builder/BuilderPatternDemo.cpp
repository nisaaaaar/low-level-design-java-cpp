int main() {
    Computer gamingPC = Computer::Builder("Intel i9", "32GB")
                            .setGraphicsCard(true)
                            .setBluetooth(true)
                            .build();

    Computer officePC = Computer::Builder("Intel i5", "16GB")
                            .setGraphicsCard(false)
                            .setBluetooth(true)
                            .build();

    gamingPC.printSpecs();
    officePC.printSpecs();

    return 0;
}