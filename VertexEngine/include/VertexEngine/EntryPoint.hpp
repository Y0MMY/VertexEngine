#pragma once

extern Vertex::Application* Vertex::CreateApplication();

int main()
{
	Vertex::InitializeCore();
	auto* instance = Vertex::CreateApplication();
	instance->Run();
	return 0;
}