// 接口隔离原则：不同功能接口区分开，不要让一个类实现它不需要的接口；
// 个人感觉跟单一职责有点类似，单一职责是具体的类，接口隔离是抽象的接口；
class IConnectable {
public:
    virtual ~IConnectable() = default;
    virtual void Connect() = 0;
    virtual void Disconnect() = 0;
};

class ICalibratable {
public:
    virtual ~ICalibratable() = default;
    virtual void Calibrate() = 0;
};

class IMovable {
public:
    virtual ~IMovable() = default;
    virtual void Move() = 0;
};

class ICamera {
public:
    virtual ~ICamera() = default;
    virtual void CaptureImage() = 0;
};
