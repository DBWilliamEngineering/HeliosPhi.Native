#pragma once

#include <cstdint>

#define HELIOPHI_API __declspec(dllimport)

extern "C"
{
    HELIOPHI_API std::int32_t __cdecl HelioPhiGetDeviceCount();
}