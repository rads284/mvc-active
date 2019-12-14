#include "future.h"

template <typename Message>
operator Message(){
	future<Message> fut = async();
	return fut.get();
}