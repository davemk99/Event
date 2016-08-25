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
		void operator()(T*);
	};

	
