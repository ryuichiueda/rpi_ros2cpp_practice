#include <chrono>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/int16_multi_array.hpp"

using namespace std::chrono_literals;

class Lightsensors : public rclcpp::Node
{
public:
    Lightsensors() : Node("lightsensors")
    {
        publisher_ = this->create_publisher<std_msgs::msg::Int16MultiArray>("lightsensors", 10);
	timer_ = this->create_wall_timer(100ms, std::bind(&Lightsensors::timer_callback, this));
    }

private:
    void timer_callback()
    {
        auto message = std_msgs::msg::Int16MultiArray();
        publisher_->publish(message);
    }

    rclcpp::Publisher<std_msgs::msg::Int16MultiArray>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<Lightsensors>());
    rclcpp::shutdown();
    return 0;
}
