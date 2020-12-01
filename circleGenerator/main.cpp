#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
	int resolution;
	int number;
	std::cout << "Enter a resolution:";
	std::cin >> resolution;
	std::cout << "Enter the number of circles to generate:";
	std::cin >> number;
	double twoPi = 4 * acos(0.0);
	double stepSize = twoPi / resolution;
	float x = 0;
	float y = 0;
	std::string directory = "res" + std::to_string(resolution);
	fs::create_directories(directory);
	for (int j = 1; j <= number; j++) {
		std::ofstream file;
		std::string fileName = directory+"/circleRes"+std::to_string(resolution)+"Rad"+ std::to_string(j)+".json";
		file.open(fileName);
		file << "{\"vertices\":[\n";
		for (int i = 0; i < resolution; i++) {
			x = j * sin(stepSize * i) + j;
			y = j * cos(stepSize * i) + j;
			file << std::fixed << std::setprecision(2) << x << "," << y << ",0.0,0.0,0.0,0.0,0.0,0.0,\n"; //Figure out texture mapping
		}
		file << j << "," << j << ",0.0,0.0,0.0,0.0,0.0,0.0\n";
		file << "],\n\"indices\":[\n";
		for (int i = 0; i < resolution - 1; i++) {
			file << resolution << "," << i << "," << i + 1 << ",\n";
		}
		file << resolution << "," << resolution - 1 << "," << 0 << "\n";
		file << "]}";
		//(x-xOffset)^2+(y-yOffset)^2=R^2 equation for circle
		file.close();
	}
	return 0;
}