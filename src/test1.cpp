//
// Created by think on 2021/2/9.
//

#include <boost/asio.hpp>
#include <iostream>
#include <thread>
#include <iomanip>
#include <frame.hpp>

using namespace boost::asio;

const char HEADER1 = 0xEB;
const char HEADER2 = 0x90;
const char HAND_ID = 0x00;
const char _force_address1 = 0x2e;
const char _force_address2 = 0x06;

template <typename T>
uint8_t getBinary(T t, int i)
{
    return ((char *)&t)[i];
}

std::vector<uint8_t> setAngle(uint16_t h1, uint16_t h2, uint16_t h3, uint16_t h4, uint16_t h5, uint16_t h6)
{
    uint8_t checksum = 0;
    uint8_t dataLens = 2 * 6 + 3;
    std::vector<uint8_t> buffer;
    buffer.push_back(HEADER1);
    buffer.push_back(HEADER2); //帧头

    buffer.push_back(HAND_ID); //ID
    checksum += HAND_ID;
    buffer.push_back(dataLens); //长度
    checksum += dataLens;
    buffer.push_back(0x12); //写寄存器命令
    checksum += 0x12;
    buffer.push_back(0xCE);
    buffer.push_back(0x05);
    checksum += 0xCE + 0x05;
    buffer.push_back(getBinary(h1, 0));
    buffer.push_back(getBinary(h1, 1));
    checksum += getBinary(h1, 0) + getBinary(h1, 1);
    //    std::cout << std::hex << (int)getBinary(h1, 0) << (int)getBinary(h1, 1) << std::endl;
    buffer.push_back(getBinary(h2, 0));
    buffer.push_back(getBinary(h2, 1));
    checksum += getBinary(h2, 0) + getBinary(h2, 1);
    ;
    buffer.push_back(getBinary(h3, 0));
    buffer.push_back(getBinary(h3, 1));
    checksum += getBinary(h3, 0) + getBinary(h3, 1);
    ;
    buffer.push_back(getBinary(h4, 0));
    buffer.push_back(getBinary(h4, 1));
    checksum += getBinary(h4, 0) + getBinary(h4, 1);
    ;
    buffer.push_back(getBinary(h5, 0));
    buffer.push_back(getBinary(h5, 1));
    checksum += getBinary(h5, 0) + getBinary(h5, 1);
    ;
    buffer.push_back(getBinary(h6, 0));
    buffer.push_back(getBinary(h6, 1));
    checksum += getBinary(h6, 0) + getBinary(h6, 1);
    ;
    buffer.push_back(checksum);

    //std::cout << std::hex << (int)checksum << std::endl;

    return buffer;
}
std::vector<uint8_t> setSpeed(uint16_t h1, uint16_t h2, uint16_t h3, uint16_t h4, uint16_t h5, uint16_t h6)
{
    uint8_t checksum = 0;
    uint8_t dataLens = 2 * 6 + 3;
    std::vector<uint8_t> buffer;
    buffer.push_back(HEADER1);
    buffer.push_back(HEADER2); //帧头

    buffer.push_back(HAND_ID); //ID
    checksum += HAND_ID;
    buffer.push_back(dataLens); //长度
    checksum += dataLens;
    buffer.push_back(0x12); //写寄存器命令
    checksum += 0x12;
    buffer.push_back(0xF2);
    buffer.push_back(0x05);
    checksum += 0xf2 + 0x05;
    buffer.push_back(getBinary(h1, 0));
    buffer.push_back(getBinary(h1, 1));
    checksum += getBinary(h1, 0) + getBinary(h1, 1);
    //    std::cout << std::hex << (int)getBinary(h1, 0) << (int)getBinary(h1, 1) << std::endl;
    buffer.push_back(getBinary(h2, 0));
    buffer.push_back(getBinary(h2, 1));
    checksum += getBinary(h2, 0) + getBinary(h2, 1);
    ;
    buffer.push_back(getBinary(h3, 0));
    buffer.push_back(getBinary(h3, 1));
    checksum += getBinary(h3, 0) + getBinary(h3, 1);
    ;
    buffer.push_back(getBinary(h4, 0));
    buffer.push_back(getBinary(h4, 1));
    checksum += getBinary(h4, 0) + getBinary(h4, 1);
    ;
    buffer.push_back(getBinary(h5, 0));
    buffer.push_back(getBinary(h5, 1));
    checksum += getBinary(h5, 0) + getBinary(h5, 1);
    ;
    buffer.push_back(getBinary(h6, 0));
    buffer.push_back(getBinary(h6, 1));
    checksum += getBinary(h6, 0) + getBinary(h6, 1);
    ;
    buffer.push_back(checksum);

    //std::cout << std::hex << (int)checksum << std::endl;

    return buffer;
}
std::vector<uint8_t> Default_force_set(uint16_t h1, uint16_t h2, uint16_t h3, uint16_t h4, uint16_t h5, uint16_t h6)
{
    uint8_t checksum = 0;
    uint8_t dataLens = 2 * 6 + 3;
    std::vector<uint8_t> buffer;
    buffer.push_back(HEADER1);
    buffer.push_back(HEADER2); //帧头

    buffer.push_back(HAND_ID); //ID
    checksum += HAND_ID;
    buffer.push_back(dataLens); //长度
    checksum += dataLens;
    buffer.push_back(0x12); //写寄存器命令
    checksum += 0x12;
    buffer.push_back(0x14);
    buffer.push_back(0x04);
    checksum += 0x14 + 0x04;
    buffer.push_back(getBinary(h1, 0));
    buffer.push_back(getBinary(h1, 1));
    checksum += getBinary(h1, 0) + getBinary(h1, 1);
    //    std::cout << std::hex << (int)getBinary(h1, 0) << (int)getBinary(h1, 1) << std::endl;
    buffer.push_back(getBinary(h2, 0));
    buffer.push_back(getBinary(h2, 1));
    checksum += getBinary(h2, 0) + getBinary(h2, 1);
    ;
    buffer.push_back(getBinary(h3, 0));
    buffer.push_back(getBinary(h3, 1));
    checksum += getBinary(h3, 0) + getBinary(h3, 1);
    ;
    buffer.push_back(getBinary(h4, 0));
    buffer.push_back(getBinary(h4, 1));
    checksum += getBinary(h4, 0) + getBinary(h4, 1);
    ;
    buffer.push_back(getBinary(h5, 0));
    buffer.push_back(getBinary(h5, 1));
    checksum += getBinary(h5, 0) + getBinary(h5, 1);
    ;
    buffer.push_back(getBinary(h6, 0));
    buffer.push_back(getBinary(h6, 1));
    checksum += getBinary(h6, 0) + getBinary(h6, 1);
    ;
    buffer.push_back(checksum);

    //std::cout << std::hex << (int)checksum << std::endl;

    return buffer;
}

int main(int argc, char **argv)
{
    io_service ioService;
    boost::system::error_code ec;
    serial_port serialPort(ioService);
    serialPort.open("/dev/ttyUSB0", ec);

    if (ec)
    {
        std::cout << "Can not open serial port, error reason: " << ec.message() << std::endl;
        return -1;
    }

    serialPort.set_option(serial_port::baud_rate(115200));                             //波特率15200
    serialPort.set_option(serial_port::flow_control(serial_port::flow_control::none)); //无流控制
    serialPort.set_option(serial_port::parity(serial_port::parity::none));             //无奇偶校验
    serialPort.set_option(serial_port::stop_bits(serial_port::stop_bits::one));        //1位奇偶校验
    serialPort.set_option(serial_port::character_size(8));                             //数据位8位

    /******************************************************************/

    //write(serialPort, buffer(Default_force_set(300, 300, 300, 300, 300, 300)));

    /**********************************************/
    // unsigned int angle1 = (argc >= 2) ? (unsigned int)atoi(argv[1]) : (unsigned int)1000;
    // unsigned int angle2 = (argc >= 3) ? (unsigned int)atoi(argv[2]) : (unsigned int)1000;
    // unsigned int angle3 = (argc >= 4) ? (unsigned int)atoi(argv[3]) : (unsigned int)1000;
    // unsigned int angle4 = (argc >= 5) ? (unsigned int)atof(argv[4]) : (unsigned int)1000;
    // unsigned int angle5 = (argc >= 6) ? (unsigned int)atof(argv[5]) : (unsigned int)1000;
    // unsigned int angle6 = (argc >= 7) ? (unsigned int)atof(argv[6]) : (unsigned int)1000;

    //write(serialPort, buffer(setAngle(angle1, angle2, angle3, angle4, angle5, angle6)));

#if 0
    // write(serialPort, buffer(setSpeed(1000, 1000, 1000, 1000, 1000, 1000)));
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 1000, 1000)));
    //std::this_thread::sleep_for(std::chrono::seconds(3));
    write(serialPort, buffer(setSpeed(40, 40, 40, 40, 80, 800)));
    std::this_thread::sleep_for(std::chrono::seconds(3));
    write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 1000, 110)));
    std::this_thread::sleep_for(std::chrono::seconds(3));
    write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 865, 110)));
    std::this_thread::sleep_for(std::chrono::seconds(3));
    write(serialPort, buffer(setAngle(800, 800, 730, 782, 865, 110)));
    std::this_thread::sleep_for(std::chrono::seconds(3));
#endif
    write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 1000, 1000)));
    //  write(serialPort, buffer(setSpeed(1000, 1000, 1000, 1000, 1000, 1000)));

    // write(serialPort, buffer(setSpeed(40, 40, 40, 40, 500, 100)));
    // std::this_thread::sleep_for(std::chrono::seconds(3));

    // write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 865, 110)));
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 700, 110)));
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 1000, 110)));
    // std::this_thread::sleep_for(std::chrono::seconds(3));
    // write(serialPort, buffer(setAngle(1000, 1000, 1000, 1000, 1000, 1000)));

    /*********************************************************/

    ioService.run();

    return 0;
}