#pragma once

template <typename T, int offset>
class GlobalPtr
{
public:

	GlobalPtr& operator=(const T& value)
	{
		**reinterpret_cast<T**>(offset) = value;
		return *this;
	}

	operator T&() const
	{
		return **reinterpret_cast<T**>(offset);
	}

	operator T*() const
	{
		return *reinterpret_cast<T**>(offset);
	}

	T* operator->() const
	{
		return *reinterpret_cast<T**>(offset);
	}
};
