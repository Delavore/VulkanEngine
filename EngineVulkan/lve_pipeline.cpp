#include "lve_pipeline.hpp"
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>

namespace lve {
	std::vector<char> LvePipeline::readFile(const std::string& filepath) {
		std::ifstream file(filepath, std::ios::ate | std::ios::binary);  // read as binary to avoid any unwanted text transformations

		if (!file.is_open()) {
			throw std::runtime_error("failed to open file: " + filepath);
		}

		size_t fileSize = static_cast<size_t>(file.tellg());  // because ::ate flag we already at the end of the file, so when we use tellg we get the 
		// last position which is the file size
		std::vector<char> buffer(fileSize);

		file.seekg(0);
		file.read(buffer.data(), fileSize);

		file.close();
		return buffer;
	}

	void LvePipeline::createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& configInfo) {
		auto vertCode = readFile(vertFilepath);
		auto fragCode = readFile(fragFilepath);

		std::cout << "vertex shader code size: " << vertCode.size() << '\n';
		std::cout << "fragment shader code size: " << fragCode.size() << '\n';
	}

	LvePipeline::LvePipeline(
		LveDevice& device,
		const std::string& vertFilepath,
		const std::string& fragFilepath,
		const PipelineConfigInfo& configInfo) : lveDevice{ device } {
		createGraphicsPipeline(vertFilepath, fragFilepath);
	}
}