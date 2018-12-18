#pragma once

template <typename T, int offset>
class GlobalVar
{
public:

	GlobalVar& operator=(const T& value)
	{
		*reinterpret_cast<T*>(offset) = value;
		return *this;
	}

	operator T&() const
	{
		return *reinterpret_cast<T*>(offset);
	}

	// Conversion operator
	operator T*() const
	{
		return reinterpret_cast<T*>(offset);
	}

	T* operator->() const
	{
		return reinterpret_cast<T*>(offset);
	}
};
