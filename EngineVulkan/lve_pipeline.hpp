#pragma once 

#include "lve_device.hpp"

#include <vector>
#include <string>

namespace lve {
	struct PipelineConfigInfo {};
	class LvePipeline {
	private:
		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;

		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(
			const LveDevice& device,
			const std::string& vertFilepath,
			const std::string& fragFilepath,
			const PipelineConfigInfo& configInfo);
	public:

		LvePipeline(
			const LveDevice& device,
			const std::string& vertFilepath, 
			const std::string& fragFilepath, 
			const PipelineConfigInfo& configInfo);
	};
}