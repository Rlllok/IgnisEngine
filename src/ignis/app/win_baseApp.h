#pragma once

#include <vector>

#include <vulkan/vulkan.h>
#include <windows.h>

#include "ignis/vk/instance.h"
#include "ignis/vk/device.h"
#include "ignis/vk/swapchain.h"
#include "ignis/vk/viewport.h"
#include "ignis/vk/commandPool.h"
#include "ignis/window/win_window.h"
#include "ignis/utils/win_timer.h"

class IBaseApp
{
public:
    virtual void initVulkan() = 0;

    virtual void start() = 0;

    virtual void resizeHandle(const int newWidth, const int newHeight) = 0;
    
protected:
    WinTimer timer;

    bool bFinished = false;
    bool bMinimized = false;

    Instance*           instance = nullptr;
    Device*             device = nullptr;
    CommandPool*        commandPool = nullptr;

    Viewport* viewport = nullptr;

protected:
    virtual void draw(double deltaTime) = 0;
    virtual void onClose() = 0;
};