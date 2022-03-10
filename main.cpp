#include <iostream>
#include <sstream>
#include <bitset>

std::string to_binary(const std::string& input)
{
    std::ostringstream oss;
    for(auto c : input) {
        oss << std::bitset<8>(c);
    }
    return oss.str();
}

std::string BitStrToStr(std::string bstr) {
    std::string str = "";
    int sum;
    for (int i = 0; i < bstr.size(); i += 8) {
        sum = 0;
        for (int j = 0; j < 8; j++)
            if (bstr[i + j] == '1')
                sum = sum * 2 + 1;
            else
                sum = sum * 2;
        str = str + char(sum);
    }
    return str;
}


int main()
{
    std::string tmp;
    std::cout << "请输入要转换的字符串：";
    std::cin >> tmp;
    std::string outputInformations(tmp);
    std::string binary_outputInformations(to_binary(outputInformations));
    std::puts("转换结果为:");
    std::cout << binary_outputInformations << std::endl;

    std::cout << "请输入要转换的2进制字符串：";
    std::cin >> tmp;
    std::puts("转换结果为:");
    std::cout << BitStrToStr(tmp) << std::endl;
    return 0;
}