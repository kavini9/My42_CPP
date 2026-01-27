
#include <string>
#include <iostream>

int main() { 
    std::string arr[50];
    int nEle = 19;
    char *pEnd;
    double dbl;
    double dbl_dbl;
    arr[0] = "10.78f";
    arr[1] = "1";
    arr[2] = "2.";
    arr[3] = "+3";
    arr[4] = ".1E";
    arr[5] = "+";
    arr[6] = "23.";
    arr[7] = "34f";
    arr[8] = "34.f";
    arr[9] = "4.402823466e+38f";
    arr[10] = ".f";
    arr[11] = "0.0f";
    arr[12] = "67e4f";
    arr[13] = ".1";
    arr[14] = "nanf";
    arr[15] = "inff";
    arr[16] = "+inff";
    arr[17] = "-inff";
    arr[18] = "-0000067.89f";

    for(int i = 0; i < nEle; i++) {
        dbl = std::strtof(arr[i].c_str(), &pEnd);
        dbl_dbl = std::strtod(arr[i].c_str(), &pEnd);
        std::cout << "arr[" << i << "] :" << arr[i] << "    val: " << dbl << "  in float: "<< static_cast<float>(dbl) << "  in double: "<< dbl_dbl <<"  pEnd: " << pEnd << std::endl;
    }

    double arrdbl[50];

    arrdbl[0] = 1.;
    arrdbl[1] = .1;
    arrdbl[2] = .1e1;
    arrdbl[3] = 4;
    arrdbl[4] = inf;


}