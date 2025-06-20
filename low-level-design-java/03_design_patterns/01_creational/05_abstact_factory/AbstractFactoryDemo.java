public class AbstractFactoryDemo {
    public static void main(String[] args) {
        // Choose your OS/environment
        GUIFactory factory = new WindowsFactory();  // or new MacFactory()
        
        Application app = new Application(factory);
        app.renderUI();
    }
}