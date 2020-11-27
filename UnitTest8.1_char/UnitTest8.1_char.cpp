#include "pch.h"
#include "CppUnitTest.h"
#include "../lab8.1_char/lab8.1_char.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81char
{
	TEST_CLASS(UnitTest81char)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			char* s = "sasha.stu..de..nt";
			t = Find_Dot(s, '.');
			Assert::AreEqual(t, 13);
		}
	};
}
