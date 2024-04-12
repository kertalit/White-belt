#include <iomanip>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

//int main()
//{
//    std::ifstream input("input.txt");
//    int N = 0;
//    int M = 0;
//
//    std::vector<std::vector<int>> table;
//
//    if (input)
//    {
//        input >> N >> M;
//        table.resize(N);
//
//        for (int i = 0; i < N; ++i)
//        {
//            table[i].resize(M);
//
//            for (int j = 0; j < M; ++j)
//            {
//                int number;
//
//                input.get();
//                if (input >> number)
//                {
//                    table[i][j] = number;
//                }
//            }
//        }
//        input.close();
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            std::cout << std::setw(10) << table[i][j];
//
//            if (j != M - 1)
//            {
//                std::cout << ' ';
//            }
//        }
//
//        std::cout << std::endl;
//    }
//
//    return 0;
//}
