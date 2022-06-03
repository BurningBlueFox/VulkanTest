#pragma once
#include "lve_device.hpp"

#include <string>
#include <vector>

namespace lve
{
	struct PipelineConfigInfo {
		VkViewport viewport;
		VkRect2D scissor;
		VkPipelineViewportStateCreateInfo viewportInfo;
		VkPipelineInputAssemblyStateCreateInfo inputAssemblyInfo;
		VkPipelineRasterizationStateCreateInfo rasterizationInfo;
		VkPipelineMultisampleStateCreateInfo multisampleInfo;
		VkPipelineColorBlendAttachmentState colorBlendAttachment;
		VkPipelineColorBlendStateCreateInfo colorBlendInfo;
		VkPipelineDepthStencilStateCreateInfo depthStencilInfo;
		VkPipelineLayout pipelineLayout = nullptr;
		VkRenderPass renderPass = nullptr;
		uint32_t subpass = 0;

		PipelineConfigInfo& operator=(const PipelineConfigInfo&) = delete;
		PipelineConfigInfo(const PipelineConfigInfo&) = delete;
		PipelineConfigInfo() = default;
	};

	class LvePipeline
	{
	public:

		LvePipeline(LveDevice& device, const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& config_info);
		~LvePipeline();

		LvePipeline(const LvePipeline&) = delete;
		void operator=(const LvePipeline&) = delete;

		void bind(VkCommandBuffer commandBuffer);

		static PipelineConfigInfo defaultPipelineConfigInfo(
			uint32_t width, uint32_t height);
		static void defaultPipelineConfigInfo(
			PipelineConfigInfo& configInfo, uint32_t width, uint32_t height);

	private:
		static std::vector<char> readFile(const std::string& filepath);

		void createGraphicsPipeline(const std::string& vertFilepath, const std::string& fragFilepath, const PipelineConfigInfo& config_info);

		void createShaderModule(const std::vector<char>& code, VkShaderModule* shaderModule);

		LveDevice& lveDevice;
		VkPipeline graphicsPipeline;
		VkShaderModule vertShaderModule;
		VkShaderModule fragShaderModule;
	};
}
