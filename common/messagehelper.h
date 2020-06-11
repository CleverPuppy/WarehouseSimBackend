#pragma once
#include <utility>
#include "../common/robotmessage.pb.h"
#include "../common/envmessage.pb.h"
#include <google/protobuf/message_lite.h>

#include <event2/util.h>
#include <vector>
#include <ctime>
#include <iostream>

#include <unistd.h>

class MessageHelper
{
public:
    static int sendMsgToFD(google::protobuf::MessageLite&& msg, int fd);
    static int sendScheduleRequestToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
     int64_t istate, float reward, int64_t project_id);
    static int sendScheduleActionToFD(evutil_socket_t fd, int64_t token, int32_t session_id, 
    warehousesim::ScheduleAction action);
    static int sendMotionRequestToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
    std::vector<float>& fstate, float reward, int64_t project_id);
    static int sendMotionActionToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
    float linear_velocity, float swirl_velocity);

    static bool parseFromArray(google::protobuf::MessageLite* msg, void* data, int size);
};

