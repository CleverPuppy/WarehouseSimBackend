#include "simserver.h"

int main()
{
	SimServer server(0, 9995);
	server.run();
	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}