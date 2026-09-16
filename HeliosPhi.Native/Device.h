#pragma once

#include <algorithm>
#include <stdexcept>
#include <utility>
#include <cstdint>
#include <vector>

#include <scif.h>

namespace HelioPhi
{
    class Device final
    {
    public:
        explicit Device(std::uint16_t nodeId) noexcept;
        ~Device() noexcept;

        Device(const Device&) = delete;
        Device& operator=(const Device&) = delete;

        Device(Device&& other) noexcept;
        Device& operator=(Device&& other) noexcept;

        static std::vector<Device> Discover();

        void Open();
        void Connect(std::uint16_t port);
        void Close() noexcept;

        [[nodiscard]] std::uint16_t NodeId() const noexcept;
        [[nodiscard]] bool IsOpen() const noexcept;
        [[nodiscard]] bool IsConnected() const noexcept;

    private:
        std::uint16_t nodeId_;
        scif_epd_t endpoint_;
        bool connected_;
    };
}