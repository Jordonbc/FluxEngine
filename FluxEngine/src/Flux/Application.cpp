#include "Application.h"

#include "Log.h"

namespace Flux {

	Application::Application()
	{
	}

	Application::~Application()
	{
	}
	void Application::Run()
	{
		FLUX_CORE_TRACE("FLUX Engine Running!");
		while (true);
	}
}
