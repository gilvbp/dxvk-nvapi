#pragma once

#include "../nvapi_private.h"
#include "../vkd3d-proton/vkd3d-proton_interfaces.h"
#include "../util/com_pointer.h"

namespace dxvk {

    class NvapiD3d12Device {

    public:                                          
        static bool CreateCubinComputeShaderWithName(ID3D12Device* device, const void* cubinData, NvU32 cubinSize, NvU32 blockX, NvU32 blockY, NvU32 blockZ, const char* shaderName, NVDX_ObjectHandle* pShader);
        static bool DestroyCubinComputeShader(ID3D12Device* device, NVDX_ObjectHandle shader);
        static bool GetCudaTextureObject(ID3D12Device* device, D3D12_CPU_DESCRIPTOR_HANDLE srvHandle, D3D12_CPU_DESCRIPTOR_HANDLE samplerHandle, NvU32* cudaTextureHandle);
        static bool GetCudaSurfaceObject(ID3D12Device* device, D3D12_CPU_DESCRIPTOR_HANDLE uavHandle, NvU32* cudaSurfaceHandle);
        static bool LaunchCubinShader(ID3D12GraphicsCommandList* commandList, NVDX_ObjectHandle shader, NvU32 blockX, NvU32 blockY, NvU32 blockZ, const void* params, NvU32 paramSize);
        static bool CaptureUAVInfo(ID3D12Device* device, NVAPI_UAV_INFO* uavInfo);
        static bool IsFatbinPTXSupported(ID3D12Device* device);

    private:
        inline static std::unordered_map<ID3D12Device*, ID3D12DeviceExt*> m_cubinDeviceMap;

        [[nodiscard]] static Com<ID3D12DeviceExt> GetCubinDevice(ID3D12Device* device);
        [[nodiscard]] static Com<ID3D12DeviceExt> GetDeviceExt(ID3D12Device* device, D3D12_VK_EXTENSION extension);
    };
}