#pragma once

#ifndef VkInstanceCreateInfo_Class
#define VkInstanceCreateInfo_Class

#include "vulkan\vulkan.h"
#include "applicationInfo.h"

class InstanceCreateInfo : public VkInstanceCreateInfo
{
public:
	InstanceCreateInfo(const ApplicationInfo* applicationInfo)
	{
		this->sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		this->pNext = NULL;
		this->flags = 0;
		this->pApplicationInfo = applicationInfo;
		this->enabledExtensionCount = 0;
		this->ppEnabledExtensionNames = NULL;
		this->enabledLayerCount = 0;
		this->ppEnabledLayerNames = NULL;
	}

	~InstanceCreateInfo() {}
};

#endif