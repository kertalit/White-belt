#include <iostream>
#include <vector>

//class FunctionPart
//{
//public:
//    FunctionPart(char operation, double value) :
//        operation_{ operation },
//        value_{ value }
//    {
//    }
//
//    double Apply(double source) const
//    {
//        switch (operation_)
//        {
//        case '+':
//            return source + value_;
//        case '-':
//            return source - value_;
//        default:
//            break;
//        }
//    }
//
//    void Invert()
//    {
//        switch (operation_)
//        {
//        case '+':
//            operation_ = '-';
//            break;
//        case '-':
//            operation_ = '+';
//            break;
//        default:
//            break;
//        }
//    }
//
//private:
//    char operation_;
//    double value_;
//};
//
//class Function
//{
//public:
//
//    void AddPart(char operation, double value)
//    {
//        operations_.push_back({ operation, value });
//    }
//
//    double Apply(double value) const
//    {
//        for (const auto& operation : operations_)
//        {
//            value = operation.Apply(value);
//        }
//
//        return value;
//    }
//
//    void Invert()
//    {
//        for (auto& operation : operations_)
//        {
//            operation.Invert();
//        }
//
//        std::reverse(operations_.begin(), operations_.end());
//    }
//
//private:
//
//    std::vector<FunctionPart> operations_;
//    double value_;
//};
//
//struct Image
//{
//    double quality;
//    double freshness;
//    double rating;
//};
//
//struct Params
//{
//    double a;
//    double b;
//    double c;
//};
//
//Function MakeWeightFunction(const Params& params, const Image& image)
//{
//    Function function;
//    function.AddPart('-', image.freshness * params.a + params.b);
//    function.AddPart('+', image.rating * params.c);
//    return function;
//}
//
//double ComputeImageWeight(const Params& params, const Image& image)
//{
//    Function function = MakeWeightFunction(params, image);
//    return function.Apply(image.quality);
//}
//
//double ComputeQualityByWeight(const Params& params, const Image& image, double weight)
//{
//    Function function = MakeWeightFunction(params, image);
//    function.Invert();
//    return function.Apply(weight);
//}

//int main()
//{
//    Image image = { 10, 2, 6 };
//    Params params = { 4, 2, 6 };
//    std::cout << ComputeImageWeight(params, image) << std::endl;
//    std::cout << ComputeQualityByWeight(params, image, 46) << std::endl;
//    return 0;
//}