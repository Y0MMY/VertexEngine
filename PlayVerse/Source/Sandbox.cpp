#include <VertexEngine/PlayVerse.hpp>
#include <VertexEngine/EntryPoint.hpp>

namespace Sandbox
{
	class Sandbox : public Vertex::Application
	{
	public:
		Sandbox(const Vertex::ApplicationSpecification& spec)
			: Vertex::Application(spec)
		{

		}
	};

}

VERTEX_CREATE_APPLICATION
(
	ApplicationSpecification spec;
	spec.Name = "WindowHello";

	return new Sandbox::Sandbox(spec);
)