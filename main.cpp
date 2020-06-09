#include "simserver.h"
#include "protobuf/robotrequest.pb.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
int main()
{
	SimServer server(0, 9995);
	warehousesim::RobotRequest rr;
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}