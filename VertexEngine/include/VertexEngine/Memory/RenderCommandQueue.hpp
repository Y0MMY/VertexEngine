#pragma once

namespace Vertex
{
	typedef void(*RenderCommandFn)(void*);
	class RenderCommandQueue
	{
	public:
		RenderCommandQueue()
		{
			m_CommandBuffer = new byte[1024 * 1024 * 10]; // 10mb buffer size
			m_CommandBufferPtr = m_CommandBuffer;
			memset(m_CommandBuffer, 0, 1024 * 1024 * 10);
		}

		~RenderCommandQueue()
		{
			delete[] m_CommandBuffer;
			m_CommandBuffer = nullptr;
			m_CommandBufferPtr = nullptr;
		}

		void* AddCommand(RenderCommandFn fn, size_t size)
		{
			*(RenderCommandFn*)m_CommandBufferPtr = fn;
			m_CommandBufferPtr += sizeof(fn);

			*(size_t*)m_CommandBufferPtr = size;
			m_CommandBufferPtr += sizeof(size);

			void* memory = m_CommandBufferPtr;
			m_CommandBufferPtr += size;

			m_CommandCount++;
			return memory;
		}
		void Execute()
		{
			byte* buffer = m_CommandBuffer;

			for (int i = 0; i < m_CommandCount; i++)
			{
				RenderCommandFn function = *(RenderCommandFn*)buffer;
				buffer += sizeof(RenderCommandFn);

				size_t size = *(size_t*)buffer;
				buffer += sizeof(size);

				function(buffer);
				buffer += size;

			}
			m_CommandBufferPtr = m_CommandBuffer;
			memset(m_CommandBuffer, 0, 1024 * 1024 * 10);
			m_CommandCount = 0;
		}
	private:
		byte* m_CommandBuffer = nullptr;
		byte* m_CommandBufferPtr = nullptr;

		size_t m_CommandCount = 0ull;
	};

}