#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <math.h>

class BMP
{
private:

	std::vector<char> header;
	std::vector<int> data;
	int width = 0;
	int height = 0;
	std::vector < std::vector<int>> gs_data;

	std::vector<std::vector<float>> gs_data_f;

	std::vector<std::vector<float>> deriche(std::vector<std::vector<float>> matrix, float a_1, float a_2, float a_3, float a_4, float a_5, float a_6, float a_7, float a_8, float b_1, float b_2, float c)
	{

		std::vector<float> y_1;
		std::vector<float> y_2;

		int h = matrix.size();
		int w = matrix.at(0).size();

		for (int j = 0; j < h; j++)
		{

			y_1 = matrix.at(j);
			y_2 = matrix.at(j);

			for (int i = 2; i < w; i++)
			{
				y_1.at(i) = (a_1 * matrix.at(j).at(i)) + (a_2 * matrix.at(j).at(i - 1)) + (b_1 * y_1.at(i - 1)) + (b_2 * y_1.at(i - 2));
			}
			for (int i = w - 2 - 1; i >= 0; i--)
			{
				y_2.at(i) = (a_3 * matrix.at(j).at(i + 1)) + (a_4 * matrix.at(j).at(i + 2)) + (b_1 * y_2.at(i + 1)) + (b_2 * y_2.at(i + 2));
			}
			for (int i = 0; i < w; i++)
			{
				matrix.at(j).at(i) = c * (y_1.at(i) + y_2.at(i));
			}
		}

		return matrix;
	}

	std::vector<std::vector<float>> transpose(std::vector<std::vector<float>> matrix)
	{

		int h = matrix.size();
		int w = matrix.at(0).size();

		std::vector<std::vector<float>> transpose_matrix;

		transpose_matrix.resize(w);

		for (int j = 0; j < w; j++)
		{
			transpose_matrix.at(j).resize(h);

			for (int i = 0; i < h; i++)
			{
				transpose_matrix.at(j).at(i) = matrix.at(i).at(j);
			}

			std::cout << "\n";

		}

		return transpose_matrix;
	}

	std::vector<std::vector<float>> edge_detection(std::vector<std::vector<float>> matrix, std::vector<std::vector<float>> matrix_x, std::vector<std::vector<float>> matrix_y)
	{
		int h = matrix.size();
		int w = matrix.at(0).size();

		std::vector<std::vector<float>> magnitudes(h);
		std::vector<std::vector<float>> gradients(h);

		for (int j = 0; j < h; j++)
		{
			magnitudes.at(j).resize(w);
			gradients.at(j).resize(w);

			for (int i = 0; i < w; i++)
			{
				magnitudes.at(j).at(i) = sqrt(pow(matrix_x.at(j).at(i), 2) + pow(matrix_y.at(j).at(i), 2));
				gradients.at(j).at(i) = atan2f(matrix_y.at(j).at(i), matrix_x.at(j).at(i));

			}

		}

		// TODO here have to be Non-maximum suppression and Hysteresis yet

	}

public:

	BMP() {};

	BMP(std::vector<char> head, std::vector<int> d, int w, int h)
	{
		header = head;
		data = d;
		width = w;
		height = h;
	};

	void draw()
	{
		int r;
		int g;
		int b;

		for (int i = 0; i < data.size(); i += 3)
		{

			r = data[i + 2];
			g = data[i + 1];
			b = data[i];

			//std::cout << "R: " << r << " \tG: " << g << " \tB: " << b << "\n";

			if ((r > 200) && (g > 200) && (b > 200))
			{
				std::cout << "k";
			}
			else if ((r < 50) && (g < 50) && (b < 50))
			{
				std::cout << "w";
			}
			else if ((r > 200) && (g < 50) && (b < 50))
			{
				std::cout << "r";
			}
			else if ((g > 200) && (r < 50) && (b < 50))
			{
				std::cout << "g";
			}
			else if ((b > 200) && (g < 50) && (r < 50))
			{
				std::cout << "b";
			}
			else
			{
				std::cout << "-";
			}

			if (((i + 3) % (width * 3)) == 0)
			{
				std::cout << "\n";
			}

		}

	}

	void draw_gs()
	{
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < width; i++)
			{

				if (gs_data_f.at(j).at(i) > 200)
				{
					std::cout << static_cast<char>(219); // █
				}
				else if (gs_data_f.at(j).at(i) > 150)
				{
					std::cout << static_cast<char>(178); // ▓
				}
				else if (gs_data_f.at(j).at(i) > 100)
				{
					std::cout << static_cast<char>(177); // ▒
				}
				else if (gs_data_f.at(j).at(i) > 50)
				{
					std::cout << static_cast<char>(176); // ░
				}
				else
				{
					std::cout << " "; // 
				}

			}

			std::cout << "\n";

		}

	}

	bool readBMP(const std::string& file)
	{
		static constexpr size_t HEADER_SIZE = 54;

		std::ifstream bmp(file, std::ios::binary); // otevři bmp jako binártní soubor

		if (!bmp.is_open())
		{
			return false;
		}

		header.resize(HEADER_SIZE);

		bmp.read(header.data(), header.size()); // do header načti celou hlavičku

		// První dva byte obsahují znaky "BM", jako bit map
		auto dataOffset = *reinterpret_cast<uint32_t*>(&header[10]); // offset je desátý až čtrnáctý byte, informace je číslo ve čtyřech byte, proto vezmu přetypování všech čtyř byte
		width = *reinterpret_cast<uint32_t*>(&header[18]); // šířka osmnáctý
		height = *reinterpret_cast<uint32_t*>(&header[22]); // výška dvaadvacátý   

		std::vector<char> img(dataOffset - HEADER_SIZE); // přichystání vektoru o velikosti souboru mínus hlavička

		bmp.read(img.data(), img.size()); // všechny data kromě samotného obázku nahraj (tím je vyhoď z bmp)

		auto dataSize = ((width * 3 + 3) & (~3)) * height; // na konci každého řádku jsou tzv. padding bity, ty jsou maximálně tři a minimálně žádný. Zajišťují, že počet bitů v řádce je vždy dělitelný čtyřmi. Výpočet zde, automaticky k hodnotě počet pixelů v řádce krát tři (rgb byte pro každý pixel) přidá + 3 a následně vynuluje poslední dva bity hodnoty. Tím je dosaženo přidání padding bitů 

		img.resize(dataSize); // změň velikost img na počet byte obrázku

		bmp.read(img.data(), img.size()); // přečti obrázek

		data.resize(width * height * 3);

		int width_with_padding = ((width * 3 + 3) & (~3));

		auto padding_bytes = width_with_padding - (width * 3);

		int j = -1;
		int k = 0;
		int l = 0;

		for (int i = 0; i < img.size(); i++)
		{
			j++;

			if (j > width_with_padding - 1)
			{
				j = 0;
				k++;
			}
			if (j < padding_bytes)
			{
				continue;
			}

			//std::cout << "Na pozici: " << l << " je ulozen byte: \"" << img.at(img.size() - 1 - (j + (k * width_with_padding))) << "\" ktery se puvodne nachazel na indexu: " << img.size() - 1 - (j + (k * width_with_padding)) << "\n";
			data.at((width * 3) * (2 * k + 1) - l - 1) = static_cast<int>(img.at(img.size() - 1 - (j + (k * width_with_padding))) & 0xff);

			l++;
		}

		return true;
	}

	bool writeBMP(const std::string& file)
	{

		std::ofstream bmp(file, std::ios::binary);

		if (!bmp.is_open())
		{
			return false;
		}

		bmp.write(header.data(), header.size());

		int width_with_padding = ((width * 3 + 3) & (~3));

		auto dataSize = width_with_padding * height;

		auto padding_bytes = width_with_padding - (width * 3);

		std::vector<char> img(dataSize);

		int l = 0;

		for (int j = height - 1; j >= 0; j--)
		{
			for (int i = 0; i < width; i++)
			{
				for (int k = 0; k < 3; k++)
				{
					img.at(l) = static_cast<char>(gs_data_f.at(j).at(i));
					l++;
				}
			}

			for (int i = 0; i < padding_bytes; i++)
			{
				img.at(l) = static_cast<char>(0);
				l++;
			}
		}

		bmp.write(img.data(), img.size());

		return true;
	}

	void gray_scale()
	{
		gs_data.resize(height);
		gs_data_f.resize(height);

		int r;
		int g;
		int b;

		for (int j = 0; j < height; j++)
		{
			gs_data.at(j).resize(width);
			gs_data_f.at(j).resize(width);

			for (int i = 0; i < width * 3; i += 3)
			{

				r = data[((j * width * 3) + i) + 2];
				g = data[((j * width * 3) + i) + 1];
				b = data[((j * width * 3) + i)];


				gs_data.at(j).at(i / 3) = (r + b + g) / 3;
				gs_data_f.at(j).at(i / 3) = static_cast<float>((r + b + g) / 3);
			}
		}
	}

	void deriche_filter(float alpha)
	{
		float k = pow(1 - exp(-alpha), 2.0) / (1.0 + (2.0 * alpha * exp(-alpha)) - (exp(-2.0 * alpha)));

		// smhooting
		float a_1 = k, a_2 = k * exp(-alpha) * (alpha - 1.0), a_3 = k * exp(-alpha) * (alpha + 1.0), a_4 = -k * exp(-2.0 * alpha);
		float a_5 = k, a_6 = k * exp(-alpha) * (alpha - 1.0), a_7 = k * exp(-alpha) * (alpha + 1.0), a_8 = -k * exp(-2.0 * alpha);
		float b_1 = 2.0 * exp(-alpha), b_2 = -exp(-2.0 * alpha);
		float c_1 = 1.0, c_2 = 1.0;

		gs_data_f = deriche(gs_data_f, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_1);
		gs_data_f = transpose(gs_data_f);
		gs_data_f = deriche(gs_data_f, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_2);
		gs_data_f = transpose(gs_data_f);

		// x - derivative
		a_1 = 0, a_2 = 1, a_3 = -1, a_4 = 0;
		a_5 = k, a_6 = k * exp(-alpha) * (alpha - 1.0), a_7 = k * exp(-alpha) * (alpha + 1.0), a_8 = -k * exp(-2.0 * alpha);
		c_1 = -pow(1.0 - exp(-alpha), 2.0);

		std::vector<std::vector<float>> gs_data_x = deriche(gs_data_f, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_1);
		gs_data_x = transpose(gs_data_x);
		gs_data_x = deriche(gs_data_x, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_2);

		// y - derivative
		a_1 = k, a_2 = k * exp(-alpha) * (alpha - 1.0), a_3 = k * exp(-alpha) * (alpha + 1.0), a_4 = -k * exp(-2.0 * alpha);
		a_5 = 0, a_6 = 1, a_7 = -1, a_8 = 0;
		c_1 = 1.0, c_2 = -pow(1.0 - exp(-alpha), 2.0);

		std::vector<std::vector<float>> gs_data_y = deriche(gs_data_f, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_1);
		gs_data_y = transpose(gs_data_y);
		gs_data_y = deriche(gs_data_y, a_1, a_2, a_3, a_4, a_5, a_6, a_7, a_8, b_1, b_2, c_2);

		//gs_data_f = edge_detection(gs_data_f,gs_data_x,gs_data_y);

	}
};

int main()
{
	BMP picture;

	if (!picture.readBMP("e.bmp"))
	{
		std::cout << "The file does not exist.\n";
		return 0;
	}

	//picture.draw();

	picture.gray_scale();

	//picture.deriche_filter(0.3);

	picture.draw_gs();

	//picture.writeBMP("gg.bmp");
}