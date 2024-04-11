#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr7.3ITER/Pr7.3ITER.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace YourUnitTestNamespace
{
    TEST_CLASS(MatrixOperationsTests)
    {
    public:

        TEST_METHOD(PositiveElementCountInColumnsWithNegative)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
            {
                matrix[i] = new int[colCount];
                for (int j = 0; j < colCount; ++j)
                {
                    matrix[i][j] = (i + j) % 2 == 0 ? -1 : 1; 
                }
            }

            int sum = 0;
            Assert::IsTrue(Part1_Count(matrix, rowCount, colCount, sum));
            Assert::AreEqual(sum, 4); 

            
            for (int i = 0; i < rowCount; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }

        TEST_METHOD(NoSaddlePointInMatrix)
        {
            const int rowCount = 3;
            const int colCount = 3;
            int** matrix = new int* [rowCount];
            for (int i = 0; i < rowCount; ++i)
            {
                matrix[i] = new int[colCount];
                for (int j = 0; j < colCount; ++j)
                {
                    matrix[i][j] = (i + j) % 2 == 0 ? 1 : -1; 
                }
            }

            for (int i = 0; i < rowCount; ++i)
            {
                delete[] matrix[i];
            }
            delete[] matrix;
        }
    };
}
