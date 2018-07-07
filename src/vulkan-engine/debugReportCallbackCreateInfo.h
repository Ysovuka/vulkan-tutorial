#pragma once

#ifndef VkDebugReportCallbackCreateInfo_Class
#define VkDebugReportCallbackCreateInfo_Class

#include "vulkan\vulkan.h"

class DebugReportCallbackCreateInfo : public VkDebugReportCallbackCreateInfoEXT
{
public:
	DebugReportCallbackCreateInfo(PFN_vkDebugReportCallbackEXT fnCallback,
		VkDebugReportFlagsEXT flags = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT)
	{
		this->sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT;
		this->pfnCallback = fnCallback;
		this->flags = flags;
	}
	~DebugReportCallbackCreateInfo() {}

	VkResult AttachDebugReport(VkInstance instance,
		const VkAllocationCallbacks* pAllocator = nullptr)
	{
		auto func = (PFN_vkCreateDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT");
		if (func != nullptr)
		{
			return func(instance, this, pAllocator, &callback);
		}
		else
		{
			return VK_ERROR_EXTENSION_NOT_PRESENT;
		}
	}
	
	void DetachDebugReport(VkInstance instance,
		const VkAllocationCallbacks* pAllocator = nullptr)
	{
		auto func = (PFN_vkDestroyDebugReportCallbackEXT)vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT");
		if (func != nullptr)
		{
			func(instance, callback, pAllocator);
		}
	}

private:
	VkDebugReportCallbackEXT callback;
};

#endif