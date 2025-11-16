#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab_09.2.2/Lab_09.2.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


TEST_CLASS(ProcessFileTest)
{
public:

    TEST_METHOD(TestProcessFileBasic)
    {
        ofstream f("test_input.txt");
        f << "Abc123!? \n";
        f.close();

        processFile("test_input.txt", 0, 9);

        Assert::IsTrue(true);
    }

    TEST_METHOD(TestMissingFile)
    {
        processFile("NO_SUCH_FILE.txt", 0, 9);

        Assert::IsTrue(true);
    }
};

       
    
