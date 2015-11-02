#include <fstream>
#include <iostream>
#include <iomanip>
#include <thread>

class Alg
{
protected:
	float **A;
	float *B;
	float *X;
	int Size;
	int Precision = 3;
public:
	Alg();
	void SetPrecision(int _Precision);
	virtual void ShowMainData();
	virtual void ShowResult();
};

class LU :public Alg
{
private:
	float** L, ** U, *Y;
	void SetLU();
	void SetY();
	void SetX();
public:
	LU();
	~LU();
	void DoCalculate();
	void ShowResult();
};

class GaussAlg :public Alg
{
private:
	float** Inverse;
	float Key;

public:
	GaussAlg();
	~GaussAlg();
	void DoCalculate();
	void ShowResult();
};

class MOSR :public Alg //MOSR - method of square roots
{
private:
	float **U, *Y;
	void SetU();
	void SetY();
	void SetX();
public:
	MOSR();
	~MOSR();
	void DoCalculate();
	void ShowResult();
};

class LPR :public Alg
{
private:
	float* Alpha,*Beta,*a,*b,*c;
	void setAlpBet();
	void setResult();
public:
	LPR();
	~LPR();
	void DoCalculate();
	void ShowMainData();
	void ShowResult();
};