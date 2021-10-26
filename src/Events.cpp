#include "Events.h"

namespace LCKYROO {
	Controller Controller::c_Instance;

	Controller& Controller::Get()
	{
		return c_Instance;
	}


	void Controller::BindEvent(Input_Event event, void(*function)())
	{
		Event* NewEvent = new Event(event, function);
		c_Events.insert(std::pair<Input_Event, Event*>(event, NewEvent));
	}

	void Controller::Update()
	{
		Controller::Get().UpdateEvents();
	}

	void Controller::UpdateEvents()
	{
		for (auto& event : c_Events)
		{
			event.second->Update();
		}
	}

	Event* Controller::Retrieve(Input_Event event)
	{
		return Controller::Get().GetEvent(event);
	}

	Event* Controller::GetEvent(Input_Event event)
	{	
		return c_Events[event];
	}
}