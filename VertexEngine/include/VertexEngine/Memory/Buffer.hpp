#pragma once

namespace Vertex
{
	struct Buffer
	{
		byte* Data;
		size_t Size;

		Buffer()
			: Data(nullptr), Size(0)
		{

		}

		Buffer(byte* data, size_t size)
			: Data(data), Size(size)
		{

		}

		void Allocate(size_t size)
		{
			delete[] Data;
			Data = nullptr;

			Data = new byte[size];
			Size = size;
		}

		void ZeroInitialize()
		{
			if (Data)
				memset(Data, 0, Size);
		}

		template <typename T>
		T& Read(size_t offset = 0)
		{
			return *(T*)(Data + offset);
		}

		void Write(void* data, size_t size, size_t offset = 0)
		{
			assert(size + offset <= Size, "Buffer overflow!");
			memcpy(Data + offset, data, size);
		}

		static Buffer Copy(void* data, size_t size)
		{
			Buffer buffer;
			buffer.Allocate(size);

			memcpy(buffer.Data, data, size);
			return buffer;
		}

		template <typename T>
		T* As() const
		{
			return (T*)(Data);
		}

		operator bool() const {
			return Data;
		}

		byte& operator[](int index)
		{
			return ((byte*)Data)[index];
		}

		byte operator[](int index) const
		{
			return ((byte*)Data)[index];
		}

		inline size_t GetSize() { return Size; }

		template <typename T>
		bool operator==(T& rhs)
		{
			return Data == rhs.Data;
		}
	};
}