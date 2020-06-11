#include "messagehelper.h"

int MessageHelper::sendMsgToFD(google::protobuf::MessageLite&& msg, int fd) 
{
    if( msg.SerializeToFileDescriptor(fd) == true){
        #ifndef NODEBUG
        std::cout<<"sendScheduleRequestToFD successful "<< std::endl;
        #endif
        return 0;
    }else{
        #ifndef NODEBUG
        std::cout<<"sendScheduleRequestToFD failed "<< std::endl;
        #endif
        return -1;
    }
}


int MessageHelper::sendScheduleRequestToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
     int64_t istate, float reward, int64_t project_id) 
{
    warehousesim::RobotRequest _request;
    _request.set_token(token);
    _request.set_type(warehousesim::RequestType::SCHEDULE);
    _request.set_session_id(session_id);
    _request.set_timestamp(time(NULL));
    _request.set_istate(istate);
    _request.set_reward(reward);
    _request.set_project_id(project_id);

    return sendMsgToFD(std::move(_request),fd);
}


int MessageHelper::sendScheduleActionToFD(evutil_socket_t fd, int64_t token, int32_t session_id, 
    warehousesim::ScheduleAction action) 
{
    warehousesim::ScheduleResponse _response;
    _response.set_token(token);
    _response.set_session_id(session_id);
    _response.set_timestamp(time(NULL));
    _response.set_action(action);

    return sendMsgToFD(std::move(_response),fd);
}

int MessageHelper::sendMotionRequestToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
    std::vector<float>& fstate, float reward, int64_t project_id) 
{
    warehousesim::RobotRequest _request;
    _request.set_timestamp(time(NULL));
    _request.set_token(token);
    _request.set_type(warehousesim::RequestType::MOTIONPLAN);
    _request.set_reward(reward);
    _request.set_session_id(session_id);
    _request.set_project_id(project_id);
    for(float i : fstate)
    {
        _request.add_fstate(i);
    }

    return sendMsgToFD(std::move(_request), fd);
    
}

int MessageHelper::sendMotionActionToFD(evutil_socket_t fd, int64_t token, int32_t session_id,
    float linear_velocity, float swirl_velocity) 
{
    warehousesim::MotionResponse _response;
    _response.set_session_id(session_id);
    _response.set_timestamp(time(NULL));
    _response.set_token(token);
    _response.set_linear_velocity(linear_velocity);
    _response.set_swirl_velocity(swirl_velocity);

    return sendMsgToFD(std::move(_response),fd);
}

bool MessageHelper::parseFromArray(google::protobuf::MessageLite* msg, void* data, int size) 
{
    #ifndef NDEBUG
    if(msg->ParseFromArray(data,size) == true){
        std::cout << "ParseFromArray succe \n" << std::endl;
        return true;
    }else {
        std::cout << "ParseFromArray failed \n" << std::endl;
        return false;
    }
    #else
    return msg->ParseFromArray(data,size);
    #endif
}