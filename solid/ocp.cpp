// OCP: 开闭原则，对扩展开放，对修改关闭，利用多态实现
// 新增功能或设备不修改原来的代码

class IDevice {
public:
    virtual ~IDevice() = default;
    virtual void Start() = 0;
};

class Camera : public IDevice {
public:
    void Start() override {
        // Camera启动
    }
};

class Laser : public IDevice {
public:
    void Start() override {
        // Laser启动
    }
};

// 增加一个设备
class RobotArm : public IDevice {
public:
    void Start() override {
        // RobotArm启动
    }
}
// 业务代码
void StartDevice(IDevice& device) {
    device.Start();
}


// 错误例子
class Device {
public:
    void Start(const std::string& type) {
        if (type == "camera") {
            // camera
        } 
        else if (type == "laser") {
            // laser
        }
        else if (type == "sensor") {
            // sensor
        }
    }
};
