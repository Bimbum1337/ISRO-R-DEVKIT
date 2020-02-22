#pragma once

#include <new>
#include <string>

class CMsgStreamBuffer
{
protected:
	struct SMsgStreamNode
	{
		SMsgStreamNode* next_node; //0x0000
		char N00012EE8[4096]; //0x0004
		char* N00012EE9; //0x1004
		char pad_1008[4]; //0x1008

		SMsgStreamNode()
		{
			next_node = 0;
			N00012EE9 = &N00012EE8[0];
		}

		void* operator new(std::size_t sz)
		{
			return reinterpret_cast<void* (__thiscall*)(int)>(0x425400)(0x00EECD98);
		}
	}; //Size: 0x100C


public:
	CMsgStreamBuffer(short msgid)
		: msgid(msgid), field3(0), _begin(0), _end(0)
	{
		buffer = node_current = new SMsgStreamNode;
	}

	virtual ~CMsgStreamBuffer()
	{
		/*
		CheckMsgNotCompletelyUsed();

		while (node_current) {
			SMsgStreamNode *node = node_current;
			node_current = node_current->next_node;

			delete node;
			node->next_node = 0xFEEEFEEE;
		}
		*/

		reinterpret_cast<void(__thiscall*)(CMsgStreamBuffer*)>(0x005097A0)(this);
	}


	void FlushRemaining()
	{
		_begin = _end;
	}

	template <typename T>
	CMsgStreamBuffer& operator>>(T& value)
	{
		Read(value);
		return *this;
	}


	template <typename T>
	void Read(T& value)
	{
		Read(&value, sizeof(T));
	}


	void Read(void* value, size_t numBytes)
	{
		reinterpret_cast<void(__thiscall*)(CMsgStreamBuffer*, void*, size_t)>(0x004F7220)(this, value, numBytes);

#if 0
		if ((buffer_end - current_buffer_ptr) < numBytes)
		{
			requireBytes(numBytes);
		}

		// Copy bytes
		memcpy(value, current_buffer_ptr, numBytes);

		// Move buffer forward
		current_buffer_ptr += numBytes;
#endif
	}



	/*
	 *++++++ WRITE +++++++++++++
	 */

	template <typename T>
	void Write(const T* const data, size_t size)
	{
		reinterpret_cast<void(__thiscall*)(CMsgStreamBuffer*, const void* const, size_t)>(0x00508FE0)(this, reinterpret_cast<const void* const>(data), size);
	}

	template <typename T>
	void Write(const T& value)
	{
		Write(&value, sizeof(T));
	}

	template <typename T>
	CMsgStreamBuffer& operator<<(const T& value)
	{
		Write(value);
		return *this;
	}

	CMsgStreamBuffer& operator<<(const std::string& str)
	{
		*this << static_cast<short>(str.length());
		Write(str.c_str(), str.length());

		return *this;
	}


public:
	int _begin;
	int _end;
	int field3;
	SMsgStreamNode* buffer;
	SMsgStreamNode* node_current;
	unsigned short msgid;
	char _gap[4];

};
