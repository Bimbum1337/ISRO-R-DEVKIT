#pragma once



template<typename T, int offset>
class Field
{
	Field& operator=(const T& value)
	{
		*reinterpret_cast<T*>(reinterpret_cast<void*>(this)+offset) = value;
		return *this;
	}

	operator T&() const
	{
		return *reinterpret_cast<T*>(reinterpret_cast<void*>(this)+offset);
	}

	operator T*() const
	{
		return reinterpret_cast<T*>(reinterpret_cast<void*>(this)+offset);
	}

	T* operator->() const
	{
		return reinterpret_cast<T*>(reinterpret_cast<void*>(this)+offset);
	}
};
