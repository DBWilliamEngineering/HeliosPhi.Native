#include "pch.h"
#include "Device.h"

namespace HelioPhi
{
    Device::Device(const std::uint16_t nodeId) noexcept
        : nodeId_(nodeId),
        endpoint_(SCIF_OPEN_FAILED),
        connected_(false)
    {
    }

    Device::~Device() noexcept
    {
        Close();
    }

    Device::Device(Device&& other) noexcept
        : nodeId_(other.nodeId_),
        endpoint_(other.endpoint_),
        connected_(other.connected_)
    {
        other.endpoint_ = SCIF_OPEN_FAILED;
        other.connected_ = false;
    }

    Device& Device::operator=(Device&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }

        Close();

        nodeId_ = other.nodeId_;
        endpoint_ = other.endpoint_;
        connected_ = other.connected_;

        other.endpoint_ = SCIF_OPEN_FAILED;
        other.connected_ = false;

        return *this;
    }

    std::vector<Device> Device::Discover()
    {
        std::uint16_t self = 0;

        //
        // Start with enough room for a reasonable number of MIC nodes.
        // We can make this dynamic later.
        //
        std::uint16_t nodes[32]{};

        const int count = scif_get_nodeIDs(
            nodes,
            std::size(nodes),
            &self);

        if (count < 0)
        {
            throw std::runtime_error(
                "[HeliosPhi] SCIF failed to enumerate available nodes.");
        }

        std::vector<Device> devices;
        devices.reserve(count);

        for (int i = 0; i < count; ++i)
        {
            //
            // Don't return the host itself as a Phi device.
            //
            if (nodes[i] == self)
            {
                continue;
            }

            devices.emplace_back(nodes[i]);
        }

        return devices;
    }

    void Device::Open()
    {
        if (IsOpen())
        {
            return;
        }

        endpoint_ = scif_open();

        if (endpoint_ == SCIF_OPEN_FAILED)
        {
            throw std::runtime_error(
                "[HeliosPhi] SCIF failed to create an endpoint.");
        }
    }

    void Device::Connect(const std::uint16_t port)
    {
        if (!IsOpen())
        {
            Open();
        }

        if (connected_)
        {
            return;
        }

        scif_portID destination{};

        destination.node = nodeId_;
        destination.port = port;

        const int result = scif_connect(
            endpoint_,
            &destination);

        if (result < 0)
        {
            throw std::runtime_error(
                "[HeliosPhi] SCIF failed to connect to the Xeon Phi.");
        }

        connected_ = true;
    }

    void Device::Close() noexcept
    {
        if (!IsOpen())
        {
            return;
        }

        scif_close(endpoint_);

        endpoint_ = SCIF_OPEN_FAILED;
        connected_ = false;
    }

    std::uint16_t Device::NodeId() const noexcept
    {
        return nodeId_;
    }

    bool Device::IsOpen() const noexcept
    {
        return endpoint_ != SCIF_OPEN_FAILED;
    }

    bool Device::IsConnected() const noexcept
    {
        return connected_;
    }
}