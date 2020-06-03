#include "simserver.h"
#include "robotrequest.pb.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
int main()
{
	// SimServer server(0, 9995);
	// warehousesim::RobotRequest rr;
	printf("none blocked\n");


	// test protobuf
	GOOGLE_PROTOBUF_VERIFY_VERSION;
	warehousesim::RobotRequest request;
	request.set_token(11111);
	request.set_timestamp(time(nullptr));
	request.set_type(warehousesim::SCHEDULE);
	std::vector<float> fstates{1.f,2.f,3.f,4.f};
	for(auto v : fstates)
		request.add_fstate(v);

	printf("to serialize\n");
	std::string se;
	request.SerializeToString(&se);
	printf("%d",se.size());
	printf("as %s",se.c_str());

	warehousesim::RobotRequest newRequest;

	if(newRequest.ParseFromString(se) == true){
		for(auto v : newRequest.fstate()){
			printf("%f",v);
		}
	}else{
		fprintf(stderr,"newRequest:ParseFromString failed\n");
	}

	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}