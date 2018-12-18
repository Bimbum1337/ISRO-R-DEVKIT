class IDxSound
{
public:
	virtual ~IDxSound()
	{
	}

	virtual bool Func_1(HWND, int, int, int, int, float) = 0;
	virtual void Func_2() = 0;
	virtual void Func_3(float, float) = 0;
	virtual void Func_4() = 0;
	virtual int Func_5() = 0;
};
