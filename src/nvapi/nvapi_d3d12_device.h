#pragma once

#include "../nvapi_private.h"
#include "../interfaces/vkd3d-proton_interfaces.h"
#include "../util/com_pointer.h"

namespace dxvk {

    class NvapiD3d12Device {

        struct CommandListExtWithVersion {
            ID3D12GraphicsCommandListExt1* CommandListExt;
            uint32_t InterfaceVersion;
        };

      public:
        static std::optional<LUID> GetLuid(IUnknown* unknown);

        static bool CreateGraphicsPipelineState(ID3D12Device* device, const D3D12_GRAPHICS_PIPELINE_STATE_DESC* pipelineStateDescription, NvU32 numberOfExtensions, const NVAPI_D3D12_PSO_EXTENSION_DESC** extensions, ID3D12PipelineState** pipelineState);
        static bool SetDepthBoundsTestValues(ID3D12GraphicsCommandList* commandList, float minDepth, float maxDepth);

        static bool CreateCubinComputeShaderWithName(ID3D12Device* device, const void* cubinData, NvU32 cubinSize, NvU32 blockX, NvU32 blockY, NvU32 blockZ, const char* shaderName, NVDX_ObjectHandle* pShader);
        static bool CreateCubinComputeShaderEx(ID3D12Device* device, const void* cubinData, NvU32 cubinSize, NvU32 blockX, NvU32 blockY, NvU32 blockZ, NvU32 smemSize, const char* shaderName, NVDX_ObjectHandle* pShader);
        static bool DestroyCubinComputeShader(ID3D12Device* device, NVDX_ObjectHandle shader);
        static bool GetCudaTextureObject(ID3D12Device* device, D3D12_CPU_DESCRIPTOR_HANDLE srvHandle, D3D12_CPU_DESCRIPTOR_HANDLE samplerHandle, NvU32* cudaTextureHandle);
        static bool GetCudaSurfaceObject(ID3D12Device* device, D3D12_CPU_DESCRIPTOR_HANDLE uavHandle, NvU32* cudaSurfaceHandle);
        static bool NotifyOutOfBandCommandQueue(ID3D12CommandQueue* commandQueue, D3D12_OUT_OF_BAND_CQ_TYPE type);
        static bool LaunchCubinShader(ID3D12GraphicsCommandList* commandList, NVDX_ObjectHandle shader, NvU32 blockX, NvU32 blockY, NvU32 blockZ, const void* params, NvU32 paramSize);
        static bool CaptureUAVInfo(ID3D12Device* device, NVAPI_UAV_INFO* uavInfo);
        static bool IsFatbinPTXSupported(ID3D12Device* device);

        static void Reset();

      private:
        inline static std::unordered_map<ID3D12Device*, ID3D12DeviceExt*> m_cubinDeviceMap;
        inline static std::unordered_map<ID3D12CommandQueue*, ID3D12CommandQueueExt*> m_commandQueueMap;
        inline static std::unordered_map<ID3D12GraphicsCommandList*, CommandListExtWithVersion> m_commandListMap;
        inline static std::unordered_map<NVDX_ObjectHandle, NvU32> m_cubinSmemMap;

        inline static std::mutex m_commandListMutex;
        inline static std::mutex m_commandQueueMutex;
        inline static std::mutex m_cubinDeviceMutex;
        inline static std::mutex m_cubinSmemMutex;

        [[nodiscard]] static Com<ID3D12DeviceExt> GetCubinDevice(ID3D12Device* device);
        [[nodiscard]] static Com<ID3D12DeviceExt> GetDeviceExt(ID3D12Device* device, D3D12_VK_EXTENSION extension);
        [[nodiscard]] static Com<ID3D12CommandQueueExt> GetCommandQueueExt(ID3D12CommandQueue* commandQueue);
        [[nodiscard]] static std::optional<CommandListExtWithVersion> GetCommandListExt(ID3D12GraphicsCommandList* commandList);
    };
}
