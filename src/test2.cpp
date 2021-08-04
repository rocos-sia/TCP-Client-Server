//
// Created by think on 2021/2/25.
//

#include "inspirehand.hpp"
#include <thread>
#include <unistd.h>

#define HAND_ID 0x00

int main(int argc, char **argv)
{
    InspireHand ih(HAND_ID, "/dev/ttyUSB0");
    std::vector<uint16_t> fingers;
    uint8_t id;
    ih.getHandID(id);
    // while (1)
    // {
    //     if (ih.getAngle(fingers))
    //     {
    //         int i = 0;
    //         for (auto &v : fingers)
    //         {

    //             std::cout << "finger " << i++ << " is: [" << static_cast<int>(v) << "]" << std::endl;
    //         }
    //     }

    //     if (ih.getForce(fingers))
    //     {
    //         int j = 0;
    //         for (auto &v : fingers)
    //         {
    //             std::cout << "finger  force" << j++ << " is: [" << static_cast<short>(v) << "]" << std::endl;
    //         }
    //     }

    //     sleep(1);
    // }

    return 0;
}