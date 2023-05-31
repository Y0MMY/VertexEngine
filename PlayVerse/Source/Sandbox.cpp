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
		void OnInit() override
		{
			Vertex::Renderer::SetFloat4(Vertex::CommandFloat4Targets::SetBackgroundColor, {0.2f, 0.3f, 0.1f, 1.0f});
		}
		void OnUpdate() override
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