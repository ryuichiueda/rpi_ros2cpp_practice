#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16_multi_array.hpp"

class Lightsensors : public rclcpp::Node
{
public:
    Lightsensors() : Node("lightsensors")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int16MultiArray>("lightsensors", 10);
    }

private:
    rclcpp::Publisher<std_msgs::msg::Int16MultiArray>::SharedPtr publisher_;
};

int main(int argc, char* argv[])
{

}
