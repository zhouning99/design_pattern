// 里氏替换原则：子类必须完全能够替换父类，否则子类的设计是错误的。

// Bird 是一个抽象类，表示鸟类，但不能有fly方法，不是所有的鸟都会飞，比如企鹅。
// 如果有fly抽象方法，那么企鹅类就不能实现这个方法，这就违反了里氏替换原则。
class Bird {
public:
    virtual ~Bird() = default;
};

class Flyable {
public:
    virtual ~Flyable() = default;
    virtual void Fly() = 0;
};


class Sparrow : public Bird, public Flyable {
public:
    void Fly() override {
        std::cout << "Sparrow is flying" << std::endl;
    }
}

// 企鹅不会飞，但也是鸟，只能继承Bird，不能继承Flyable。
class Penguin : public Bird {
};