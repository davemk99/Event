#pragma once
#include "stdincl.h"

class Event {
private:
	class EventHandler {
	private:
		std::list<std::function<void(void*)>> events;

	public:
		void SetEvent(std::function<void(void*)>);

		void operator()(void*);

	}event;
public:
	Event operator+=(std::function<void(void*)>);
	void operator()(void*);
};
