#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <math.h>
#define _USE_MATH_DEFINES

unsigned char* DoubleArrayToByteArray(std::vector<double>* data);
void WriteToFile(std::vector<double>* data, std::string filename);
std::vector<double>* ByteArrayToDoubleArray(std::vector<unsigned char>* data);
