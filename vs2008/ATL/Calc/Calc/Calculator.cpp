// Calculator.cpp : Implementation of CCalculator
#include "stdafx.h"
#include "Calculator.h"


// CCalculator

STDMETHODIMP CCalculator::Add(DOUBLE a, DOUBLE b, DOUBLE* result)
{
	// TODO: Add your implementation code here

	int ret = 0;
	double aa;
	aa = a + b;
	*result = aa;
	if ( aa > 5 )
	{
		ret = S_FALSE;
	} 
	else
	{
		ret = S_OK;
	}
	return ret;
}
