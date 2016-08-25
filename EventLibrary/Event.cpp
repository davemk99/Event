#include "Event.h"
#include "stdincl.h"
//using namespace std;
//void Event::EventHandler::SetEvent(function<void(void*)> func) {
//	this->events.push_back(func);
//}
//void Event::EventHandler::operator()(void* sender) {
//	if (!this->events.empty()) {
//		for_each(this->events.begin(), this->events.end(), [&](function<void(void*)>& event) {event(sender); });
//	}
//}
//Event Event::operator+=(function<void(void*)> func) {
//	this->event.SetEvent(func);
//	return *(this);
//}
//void Event::operator()(void* sender) {
//	std::thread thread([&]() {this->event(sender); });
//	thread.join();
//}
template <class T>
template <class U>
void Event<T>::EventHandler<U>::SetEvent(std::function<void(U)> func) {
	this->events.push_back(func);
}
template<class T>
template<class U>
void Event<T>::EventHandler<U>::operator()(U sender)
{
	if (!this->events.empty()) 
	{
		for_each(this->(events.begin(), this->events.end(), [&](function<void(void*)>& event) {event(sender); }));
	}
}
template <class T>
Event<T> Event<T>::operator+=(std::function<void(T)> func) {
	this->event.SetEvent(func);
	return *this;
}
template <class T>
void Event<T>::operator()(T* sender) {
	std::thread thread([&]() {this->event(*sender)});
	thread.join();

}
