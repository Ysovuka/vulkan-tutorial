#include "engine.h"

#include <iostream>
#include <stdexcept>

#define APPLICATION_SHORT_NAME "Vulkan Engine"

int main(int argc, char *argv[])
{
	VulkanEngine engine;

	try {
		engine.run();
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		system("pause");
		return EXIT_FAILURE;
	}
	//// Initialize the VkApplicationInfo structure
	//ApplicationInfo applicationInfo(APPLICATION_SHORT_NAME);

	//// Initialize the VkInstanceCreateInfo structure
	//InstanceCreateInfo instanceInfo(&applicationInfo);

	//VkInstance instance;
	//VkResult results;

	//results = vkCreateInstance(&instanceInfo, NULL, &instance);
	//if (results == VK_ERROR_INCOMPATIBLE_DRIVER)
	//{
	//	std::cout << "cannot find a compatible Vulkan driver." << std::endl;
	//	exit(-1);
	//}
	//else if (results)
	//{
	//	std::cout << "unknown error";
	//	exit(-1);
	//}

	//system("pause");
	//vkDestroyInstance(instance, NULL);
	system("pause");
	return 0;
}