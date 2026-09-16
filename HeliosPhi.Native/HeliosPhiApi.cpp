#include "pch.h"
#include "HeliosPhiApi.h"

#include "Device.h"

std::int32_t __cdecl HelioPhiGetDeviceCount()
{
    try
    {
        const auto devices = HelioPhi::Device::Discover();

        return static_cast<std::int32_t>(devices.size());
    }
    catch (...)
    {
        return -1;
    }
}