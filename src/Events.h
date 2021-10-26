#pragma once

#include <unordered_map>
#include "Types.h"

/*
	CREATE BINDING EVENTS RATHER THAN COMPLEX CALLBACK SCHEMES
	EXAMPLES:
		TOGGLE			-> 2 CALLBACKS (STATE1 & STATE2)
		HOLD			-> 2 CALLBACKS (HOLD & RELEASE)
		PRESS			-> 1 CALLBACK
		RELEASE			-> 1 CALLBACK
		VALUE THRESHOLD ->  1 CALLBACK (or 2?)


	OHHH WAIT
	make the event class have a template type ----- bruh moment
	then based on typeid().name() choose the value function?????

*/

namespace LCKYROO {
	enum class State {
		PRESSED,
		RELEASED,
		HOLDING,
		IDLE
	};


	class Event {
	public:
		Event(Input_Event event, void(*function)()) : e_Input(event), e_Callback(function) {}
		~Event() = default;

		virtual void Update() { std::cout << GetInputValue(e_Input) << std::endl; }

	private:
		Input_Event e_Input;
		void(*e_Callback)();
	};

	class StateMachine {
	public:
		StateMachine() = default;
		~StateMachine() = default;

		virtual void Update();
	private:
		std::int32_t s_Last;
		State s_State;
	};

	class Toggle : public StateMachine {

	};

	class Hold : public StateMachine {

	};

	class Press : public StateMachine {

	};

	class Release : public StateMachine {

	};

	class ValueThreshold : public StateMachine {

	};


	class Controller {
	public:
		Controller() = default;
		~Controller() = default;
		Controller(const Controller&) = delete;

		static Controller& Get();
		
		std::string& GetName() { return c_Name; }
		template<Input_Event event> static void Bind(void(*)());
		static void Update();
		static Event* Retrieve(Input_Event);

		void BindEvent(Input_Event, void(*)());
		Event* GetEvent(Input_Event);
		virtual void UpdateEvents();

	private:
		std::string c_Name = "Lucky Roo :)";
		static Controller c_Instance;
		std::unordered_map<Input_Event, Event*> c_Events;
	};

	template<Input_Event event>
	void Controller::Bind(void(*function)())
	{
		Controller::Get().BindEvent(event, function);
	}

}