#include "stdincl.h"
using namespace std;
#pragma once
class Event {
private:
	class EventHandler {
	private:
		list<function<void(void*)>> events;

	public:
		void SetEvent(function<void(void*)>);

		void operator()(void*);

	}event;
public:
	Event operator+=(function<void(void*)>);
	void operator()(void*);
};