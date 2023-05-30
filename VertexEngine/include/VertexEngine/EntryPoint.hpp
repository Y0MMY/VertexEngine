#pragma once

extern Vertex::Application* Vertex::CreateApplication();

int main()
{
	auto* instance = Vertex::CreateApplication();
	instance->Run();
	return 0;
}