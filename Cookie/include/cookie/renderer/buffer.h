#pragma once
#include <cookie/common.h>
#include <cookie/containers/vector.h>

namespace Cookie
{
	enum class COOKIE_API BufferDataType : u8
	{
		None = 0, 
		Float, Float2, Float3, Float4,
		Mat3, Mat4, 
		Int, Int2, Int3, Int4,
		Bool,
	};

	struct COOKIE_API BufferElement
	{
		BufferDataType type;
		bool normalized;

		static uint get_size_of_type(BufferDataType type)
		{
			switch (type)
			{
				case BufferDataType::Float: 	return 4;
				case BufferDataType::Float2: 	return 4 * 2;
				case BufferDataType::Float3: 	return 4 * 3;
				case BufferDataType::Float4: 	return 4 * 4;
				case BufferDataType::Mat3: 		return 4 * 3 * 3;
				case BufferDataType::Mat4: 		return 4 * 4 * 4;
				case BufferDataType::Int: 		return 4;
				case BufferDataType::Int2: 		return 4 * 2;
				case BufferDataType::Int3: 		return 4 * 3;
				case BufferDataType::Int4: 		return 4 * 4;
				case BufferDataType::Bool: 		return 1;
			}
			COOKIE_ASSERT(false, "BufferElement: unexpected type");
			return 0;
		}

		static uint get_count_of_type(BufferDataType type)
		{
			switch (type)
			{
				case BufferDataType::Float: 	return 1;
				case BufferDataType::Float2: 	return 2;
				case BufferDataType::Float3: 	return 3;
				case BufferDataType::Float4: 	return 4;
				case BufferDataType::Mat3: 		return 3; // 3 * float3
				case BufferDataType::Mat4: 		return 4; // 4 * float4
				case BufferDataType::Int: 		return 1;
				case BufferDataType::Int2: 		return 2;
				case BufferDataType::Int3: 		return 3;
				case BufferDataType::Int4: 		return 4;
				case BufferDataType::Bool: 		return 1;
			}
			COOKIE_ASSERT(false, "BufferElement: unexpected type");
			return 0;
		}
	};

	class COOKIE_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;		

		static VertexBuffer* create(float* vertices, u32 size);

		template<BufferDataType T>
		void push_layout()
		{
			m_layout.push_back(BufferElement{ T, false });
			m_stride += BufferElement::get_size_of_type(T);
		}

		inline const Vector<BufferElement>& layout() const { return m_layout; }
		inline uint stride() const { return m_stride; }

	private:
		Vector<BufferElement> m_layout;
		uint m_stride = 0;
	};

	class COOKIE_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual void bind() const = 0;
		virtual void unbind() const = 0;	

		virtual u32 count() const = 0;

		static IndexBuffer* create(u32* indices, u32 size);
	};
}