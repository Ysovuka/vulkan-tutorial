#pragma once

#ifndef VkApplicationInfo_Class
#define VkApplicationInfo_Class

#include "vulkan\vulkan.h"

class ApplicationInfo : public VkApplicationInfo
{
public:
	ApplicationInfo(const char* applicationName, uint32_t applicationVersion,
		uint32_t apiVersion = VK_API_VERSION_1_0)
		: ApplicationInfo(applicationName, applicationName,
			applicationVersion, applicationVersion, apiVersion)
	{

	}

	ApplicationInfo(const char* applicationName,
		uint32_t apiVersion = VK_API_VERSION_1_0)
		: ApplicationInfo(applicationName, applicationName,
			VK_MAKE_VERSION(1, 0, 0), VK_MAKE_VERSION(1, 0, 0), apiVersion)
	{

	}
	ApplicationInfo(const char* applicationName, const char* engineName,
		uint32_t applicationVersion, uint32_t engineVersion)
		: ApplicationInfo(applicationName, engineName,
			applicationVersion, engineVersion, VK_API_VERSION_1_0)
	{

	}

	ApplicationInfo(const char* applicationName, const char* engineName,
		uint32_t applicationVersion, uint32_t engineVersion,
		uint32_t apiVersion)
	{
		this->sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		this->pApplicationName = applicationName;
		this->pEngineName = engineName;
		this->applicationVersion = applicationVersion;
		this->engineVersion = engineVersion;
		this->apiVersion = apiVersion;
		this->pNext = NULL;
	}

	~ApplicationInfo() { }
};

#endif