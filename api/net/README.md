# LICENSE
The file **common.cmake** has been taken from the **gRPC** repo *https://github.com/grpc/grpc*

# TODO
Separate generated code from *proto* files into dedicated directory of each service. This has not been done yet due to error caused by import proto file in other proto, e.g.
``
project/messages/Header.pb.cc:74:6: error: ‘::descriptor_table_company_2fmessages_2fRobot_2eproto’ has not been declared
``
