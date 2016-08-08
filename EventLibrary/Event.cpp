#include "Event.h"
using namespace std;
void Event::EventHandler::SetEvent(function<void(void*)> func) {
	this->events.push_back(func);
}
void Event::EventHandler::operator()(void* sender) {
	if (!this->events.empty()) {
		for_each(this->events.begin(), this->events.end(), [&](function<void(void*)>& event) {event(sender); });
	}
}
Event Event::operator+=(function<void(void*)> func) {
	this->event.SetEvent(func);
	return *(this);
}
void Event::operator()(void* sender) {
	this->event(sender);
}
