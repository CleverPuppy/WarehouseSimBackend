#include "../common/robotmessage.pb.h"
#include "simclientnobuffer.h"

#include "sys/socket.h"
#include "sys/types.h"
#include <unistd.h>
#include <errno.h>

int main()
{
    // using ScheduleClient = SimClient<warehousesim::RobotRequest, warehousesim::ScheduleResponse>;
    // using MotionClient = SimClient<warehousesim::RobotRequest, warehousesim::MotionResponse>;
    // ScheduleClient client{};
    // client.run();

    using ScheduleClientNoBuffer = SimClientNoBuffer<warehousesim::RobotRequest, warehousesim::ScheduleResponse>;
    using MotionClientNoBuffer = SimClientNoBuffer<warehousesim::RobotRequest, warehousesim::MotionResponse>;
    ScheduleClientNoBuffer client{};
    client.run();

    // const char *MESSAGE = "HELLOOOO\n";
    // int fd;
    // sockaddr_in sin{0};
    // sin.sin_family = AF_INET;
    // sin.sin_addr.s_addr = 0;
    // sin.sin_port = htons(9995);
    // fd = socket(AF_INET, SOCK_STREAM, 0);
    // evutil_make_socket_nonblocking(fd);
    // if (fd > 0)
    // {
    //     if (connect(fd, (sockaddr *)&sin, sizeof(sin)) == -1)
    //     {
    //         printf("connect error \n");
    //     }
    //     else
    //     {
    //         write(fd, MESSAGE, sizeof(MESSAGE));
    //     }
    // }
    // else
    // {
    //     printf("fd < 0");
    // }
    google::protobuf::ShutdownProtobufLibrary();
    return 0;
}