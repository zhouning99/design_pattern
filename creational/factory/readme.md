### 简单工厂模式
- 提供一个接口创建对象，通常需要传入一个参数决定创建哪个子类的对象。
- 通常只能创建同一类型的对象，或者说继承同一个父类的各个子类的对象，比如LoggerFactory只能创建Logger的子类对象。
LoggerFactory
     │
     ├── ConsoleLogger
     │
     └── FileLogger

### 工厂方法模式
- 提供一个类创建对象，每个子类有一个对应的工厂类，不在通过传入参数决定创建哪个子类的对象。
ConsoleLoggerFactory
     │
     └── ConsoleLogger

FileLoggerFactory
     │
     └── FileLogger

### 抽象工厂模式
- 创建一系列产品，或者说是产品族，产品之间互有关联，比如适配不同的操作系统；
- GPT描述：假设你的系统不仅有 Logger，还有 Config、Database，并且不同平台需要一整套对应的实现：
Linux
 ├── LinuxLogger
 ├── LinuxConfig
 └── LinuxDatabase

Windows
 ├── WindowsLogger
 ├── WindowsConfig
 └── WindowsDatabase

- 抽象一个工厂类，每个产品族实现自己的工厂方法
LinuxFactory
     │
     ├── LinuxLogger
     ├── LinuxConfig
     └── LinuxDatabase

- 缺点：如果增加一个产品，变动比较大，新增一个产品族，变动则不大；


### 简单工厂和抽象工厂的区别
- 工厂简单模式：一个工厂生产一个产品，解决我应该创建哪个商品的问题；
                 Factory
                    │
          ┌─────────┴─────────┐
          ↓                   ↓
       ProductA            ProductB
- 抽象工厂模式：一个工厂生产一个产品族，解决我应该创建哪一套商品的问题；
              AbstractFactory
                 │
        ┌────────┴────────┐
        ↓                 ↓
   LinuxFactory      WindowsFactory
        │                 │
   ┌────┼────┐       ┌────┼────┐
   ↓    ↓    ↓       ↓    ↓    ↓
 Logger Config DB   Logger Config DB