#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::string> split(std::string text, std::string delim)
{
	std::vector<std::string> vec;
	size_t pos = 0, prevPos = 0;
	while (1) {
		pos = text.find(delim, prevPos);
		if (pos == std::string::npos) {
			vec.push_back(text.substr(prevPos));
			return vec;
		}

		vec.push_back(text.substr(prevPos, pos - prevPos));
		prevPos = pos + delim.length();
	}
}

bool write_file(std::string file_name)
{
	///////////////////////////

	bool calculated = true;
	int layers = 3;
	std::vector<int> neurons;
	neurons.push_back(2);
	neurons.push_back(3);
	neurons.push_back(1);
	int input_data_cnt = 5;
	std::string algorithm = "ADAM";
	bool stoachastic = false;
	double stochastic_ratio = 0;
	double learning_coeff = 0.05;
	bool max_cycles_bool = true;
	int max_cycles = 3000;
	bool max_tolerance_bool = true;
	double max_tolerance = 0.005;
	bool regularization_bool = true;
	std::string regularization = "lasso";
	int regularization_from = 1;
	int regularization_to = 4;
	int regularization_cycles = 10;
	std::vector<std::vector<std::string>> neurons_arr;
	neurons_arr.push_back(std::vector<std::string>{ "lin", "sin", "tim" });
	neurons_arr.push_back(std::vector<std::string>{ "div"});
	std::vector<std::vector<double>> input_data;
	input_data.push_back(std::vector<double>{0.156, 1.255, 3, 1.22, 0.55});
	input_data.push_back(std::vector<double>{0.1, 0.2, 0.3, 0.4, 0.5});
	input_data.push_back(std::vector<double>{-0.6, -0.4, 0.0, 0.4, 0.6});
	std::vector<std::vector<std::vector<double>>> koef = { {{0.5},{0.1},{1.1}}, {{0.5},{0.1},{1.1},{1.3},{1.2}}};


	///////////////////////////

	std::string str = "name=" + file_name + "\n";
	str.append("calculated=");
	str.append(calculated ? "true" : "false");
	str.append("\nlayers=" + std::to_string(layers) + "\n");
	str.append("neurons=");
	for (int i = 0; i < layers - 1; i++)
	{
		str.append(std::to_string(neurons[i]) + ",");
	}
	str.append(std::to_string(neurons[layers - 1]) + "\n");
	str.append("input_data=" + std::to_string(input_data_cnt) + "\n");
	str.append("algorithm=" + algorithm + "\n");
	str.append("stochastic=");
	str.append(stoachastic ? "true" : "false");
	str.append("," + std::to_string(stochastic_ratio) + "\n");
	str.append("learning_coefficient=" + std::to_string(learning_coeff) + "\n");
	str.append("cycles=");
	str.append(max_cycles_bool ? "true" : "false");
	str.append("," + std::to_string(max_cycles) + "\n");
	str.append("tolerance=");
	str.append(max_tolerance_bool ? "true" : "false");
	str.append("," + std::to_string(max_tolerance) + "\n");
	str.append("regularization=");
	str.append(regularization_bool ? "true" : "false");
	str.append("," + regularization + "," + std::to_string(regularization_from) + "," + std::to_string(regularization_to) + "," + std::to_string(regularization_cycles) + "\n");
	for (int j = 1; j < layers; j++)
	{
		str.append("l" + std::to_string(j) + "=");

		for (int i = 0; i < neurons.at(j) - 1; i++)
		{
			str.append(neurons_arr.at(j - 1).at(i) + ",");
		}

		str.append(neurons_arr.at(j - 1).at(neurons.at(j) - 1) + "\n");

	}
	for (int j = 0; j < neurons.at(0) + 1; j++)
	{
		str.append("d_");
		str.append((j == 0) ? "y" : "x");
		str.append(std::to_string(j) + "=");

		for (int i = 0; i < input_data_cnt - 1; i++)
		{
			str.append(std::to_string(input_data.at(j).at(i)) + ",");
		}

		str.append(std::to_string(input_data.at(j).at(input_data_cnt - 1)) + "\n");

	}
	if (calculated) 
	{
		int temp_cnt = 1;

		for (int k = 0; k < koef.size(); k++)
		{
			for (int j = 0; j < koef.at(k).size(); j++)
			{
				for (int i = 0; i < koef.at(k).at(j).size(); i++)
				{
					str.append("k_");
					str.append((k==0?"w":"b"));
					str.append(std::to_string(temp_cnt));
					temp_cnt++;
					str.append("=");
					str.append(std::to_string(koef.at(k).at(j).at(i)));
					str.append("\n");
				}
			}

			temp_cnt = 1;
		}
	}


	std::fstream file;

	file.open(file_name, std::ios::out);

	file << str;

	file.close();

	return true;
}

bool read_file(std::string file_name)
{

	bool calculated;
	int layers;
	std::vector<int> neurons;
	int input_data_cnt;
	std::string algorithm;
	bool stoachastic;
	double stochastic_ratio;
	double learning_coeff;
	bool max_cycles_boo;
	int max_cycles;
	bool max_tolerance_bool;
	double max_tolerance;
	bool regularization_bool;
	std::string regularization;
	int regularization_from;
	int regularization_to;
	int regularization_cycles;
	std::vector<std::vector<std::string>> neurons_arr;
	std::vector<std::vector<double>> input_data;

	std::fstream file;
	file.open(file_name, std::ios::in);
	std::string text((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	std::vector<std::string> data_str = split(text, "\n");
	std::vector<std::string> temp = split(data_str.at(1), "=");
	calculated = (temp.at(0) == "true") ? true : false;
	temp = split(data_str.at(2), "=");
	layers = stoi(temp.back());
	temp = split(data_str.at(3), "=");
	temp = split(temp.at(1), ",");
	for (int i = 0; i < layers; i++)
	{
		neurons.push_back(stoi(temp.at(i)));
	}
	temp = split(data_str.at(4), "=");
	input_data_cnt = stoi(temp.back());
	temp = split(data_str.at(5), "=");
	algorithm = temp.at(1);
	temp = split(data_str.at(6), "=");
	temp = split(temp.at(1), ",");
	stoachastic = (temp.at(0) == "true") ? true : false;
	stochastic_ratio = (stoachastic ? stoi(temp.back()) : 0.0);
	temp = split(data_str.at(7), "=");
	learning_coeff = stold(temp.back());
	temp = split(data_str.at(8), "=");
	temp = split(temp.at(1), ",");
	max_cycles_boo = (temp.at(0) == "true") ? true : false;
	max_cycles = (max_cycles_boo ? stoi(temp.back()) : 0.0);
	temp = split(data_str.at(9), "=");
	temp = split(temp.at(1), ",");
	max_tolerance_bool = (temp.at(0) == "true") ? true : false;
	max_tolerance = (max_tolerance_bool ? stold(temp.back()) : 0.0);
	temp = split(data_str.at(10), "=");
	temp = split(temp.at(1), ",");
	regularization_bool = (temp.at(0) == "true") ? true : false;
	regularization = temp.at(1);
	regularization_from = (regularization_bool ? stoi(temp.at(2)) : 0);
	regularization_to = (regularization_bool ? stoi(temp.at(3)) : 0);
	regularization_cycles = (regularization_bool ? stoi(temp.at(4)) : 0);
	neurons_arr.resize(layers - 1);
	for (int j = 0; j < neurons_arr.size(); j++)
	{
		temp = split(data_str.at(11 + j), "=");
		temp = split(temp.at(1), ",");

		for (int i = 0; i < neurons.at(j + 1); i++)
		{
			neurons_arr.at(j).push_back(temp.at(i));
		}
	}
	input_data.resize(neurons.at(0) + 1);

	temp = split(data_str.at(11 + layers - 1), "=");
	temp = split(temp.at(1), ",");

	for (int i = 0; i < input_data_cnt; i++)
	{
		input_data.at(0).push_back(stold(temp.at(i)));
	}

	for (int j = 0; j < input_data.size() - 1; j++)
	{
		temp = split(data_str.at(11 + layers + j), "=");
		temp = split(temp.at(1), ",");
		for (int i = 0; i < input_data_cnt; i++)
		{
			input_data.at(j + 1).push_back(stold(temp.at(i)));
		}
	}

	if (calculated) 
	{
	
	
	// Vysledky
	
	
	}

	
	return true;
}

int main()
{

	std::string file_name = "network.nnd";

	write_file(file_name);

	read_file(file_name);

}