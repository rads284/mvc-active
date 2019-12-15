# output: client.o message.o future.o activation_queue.o scheduler.o servant.o method_request.o
# 	g++ -c -lpthread client.o message.o future.o activation_queue.o scheduler.o servant.o method_request.o

# client.o: client.cpp 
# 	g++ -c client.cpp

# message.o: message.h message.cpp
# 	g++ -c message.cpp

# future.o: future.h future.cpp
# 	g++ -c future.cpp

# activation_queue.o: activation_queue.h activation_queue.cpp
# 	g++ -c activation_queue.cpp

# scheduler.o: scheduler.h scheduler.cpp
# 	g++ -c scheduler.cpp

# servant.o: servant.h servant.cpp
# 	g++ -c servant.cpp

# method_request.o: method_request.h method_request.cpp
# 	g++ -c method_request.cpp

output: proxy.cpp future.cpp servant.cpp message.cpp client.cpp method_request.cpp activation_queue.cpp scheduler.cpp
	g++ -g -std=c++11 proxy.cpp future.cpp servant.cpp message.cpp client.cpp method_request.cpp activation_queue.cpp scheduler.cpp -lpthread

