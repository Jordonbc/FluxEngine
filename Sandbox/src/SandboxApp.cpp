#include <Flux.h>

class Sandbox : public Flux::Application
{
public:
	Sandbox()
	{
		
	}
	~Sandbox()
	{
		
	}
};

Flux::Application* Flux::CreateApplication()
{
	return new Sandbox();
}