#ifndef _GENERIC_HELPER_H_
#define _GENERIC_HELPER_H_

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

class GenericHelper
{
public:
	GenericHelper();
	~GenericHelper();
	void testStdFind();		//ֻ���㷨
	void testInserter();	//д�����㷨
	void testFill_n();
	void testSort();

	static bool isShorter(const string &s1, const string &s2);
private:

};
#endif