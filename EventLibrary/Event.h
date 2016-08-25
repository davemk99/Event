#pragma once
#include "stdincl.h"

//class Event {
//private:
//	class EventHandler {
//	private:
//		std::list<std::function<void(void*)>> events;
//
//	public:
//		void SetEvent(std::function<void(void*)>);
//
//		void operator()(void*);
//
//	}event;
//public:
//	Event operator+=(std::function<void(void*)>);
//	void operator()(void*);
//};

	template<class T>
	class Event {
	private:
		template <class U>
		class EventHandler {
		private:
			std::list < std::function<void(U)>> events;
		public:
			void SetEvent(std::function<void(U)>);
			void operator()(U);
		};
		EventHandler<T> event;
	public:
		Event operator+=(std::function<void(T)>);
		void operator()(T);
	};

	template <class T>
	template <class U>
	inline void Event<T>::EventHandler<U>::SetEvent(std::function<void(U)> func) {
		this->events.push_back(func);
	}
	template<class T>
	template<class U>
	inline void Event<T>::EventHandler<U>::operator()(U sender)
	{
		if (!this->events.empty()) {
			std::for_each(this->events.begin(), this->events.end(), [&](std::function<void(U)> event) {event(sender); });
		}
	}

	template <class T>
	Event<T> Event<T>::operator+=(std::function<void(T)> func) {
		this->event.SetEvent(func);
		return *this;
	}
	template<class T>
	void Event<T>::operator()(T sender)
	{
		std::thread thread([&]() {this->event(sender); });
		thread.join();
	}
	