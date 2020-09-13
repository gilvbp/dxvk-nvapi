extern "C" {
    using namespace dxvk;

    NvAPI_Status __cdecl NvAPI_D3D11_SetDepthBoundsTest(IUnknown* pDeviceOrContext, NvU32 bEnable, float fMinDepth, float fMaxDepth) {
        constexpr auto n = "NvAPI_D3D11_SetDepthBoundsTest";

        if (pDeviceOrContext == nullptr)
            return InvalidArgument(n);

        auto success = NvapiD3d11Device::SetDepthBoundsTest(pDeviceOrContext, bEnable, fMinDepth, fMaxDepth);

        static bool alreadyLogged = false;
        if (!alreadyLogged) {
            alreadyLogged = true;
            return success ? Ok(n) : Error(n);
        }

        return success ? Ok() : Error();
    }

    NvAPI_Status __cdecl NvAPI_D3D11_BeginUAVOverlap(IUnknown *pDeviceOrContext) {
        constexpr auto n = "NvAPI_D3D11_BeginUAVOverlap";

        if (pDeviceOrContext == nullptr)
            return InvalidArgument(n);

        auto success = NvapiD3d11Device::BeginUAVOverlap(pDeviceOrContext);

        static bool alreadyLogged = false;
        if (!alreadyLogged) {
            alreadyLogged = true;
            return success ? Ok(n) : Error(n);
        }

        return success ? Ok() : Error();
    }

    NvAPI_Status __cdecl NvAPI_D3D11_EndUAVOverlap(IUnknown *pDeviceOrContext) {
        constexpr auto n = "NvAPI_D3D11_EndUAVOverlap";

        if (pDeviceOrContext == nullptr)
            return InvalidArgument(n);

        auto success = NvapiD3d11Device::EndUAVOverlap(pDeviceOrContext);

        static bool alreadyLogged = false;
        if (!alreadyLogged) {
            alreadyLogged = true;
            return success ? Ok(n) : Error(n);
        }

        return success ? Ok() : Error();
    }

    NvAPI_Status __cdecl NvAPI_D3D11_MultiDrawInstancedIndirect(ID3D11DeviceContext *pDevContext11, NvU32 drawCount, ID3D11Buffer *pBuffer, NvU32 alignedByteOffsetForArgs, NvU32 alignedByteStrideForArgs) {
        constexpr auto n = "NvAPI_D3D11_MultiDrawInstancedIndirect";

        if (pDevContext11 == nullptr || pBuffer == nullptr)
            return InvalidArgument(n);

        auto success = NvapiD3d11Device::MultiDrawInstancedIndirect(pDevContext11, drawCount, pBuffer, alignedByteOffsetForArgs, alignedByteStrideForArgs);

        static bool alreadyLogged = false;
        if (!alreadyLogged) {
            alreadyLogged = true;
            return success ? Ok(n) : Error(n);
        }

        return success ? Ok() : Error();
    }

    NvAPI_Status __cdecl NvAPI_D3D11_MultiDrawIndexedInstancedIndirect(ID3D11DeviceContext *pDevContext11, NvU32 drawCount, ID3D11Buffer *pBuffer, NvU32 alignedByteOffsetForArgs, NvU32 alignedByteStrideForArgs) {
        constexpr auto n = "NvAPI_D3D11_MultiDrawIndexedInstancedIndirect";

        if (pDevContext11 == nullptr || pBuffer == nullptr)
            return InvalidArgument(n);

        auto success = NvapiD3d11Device::MultiDrawIndexedInstancedIndirect(pDevContext11, drawCount, pBuffer, alignedByteOffsetForArgs, alignedByteStrideForArgs);

        static bool alreadyLogged = false;
        if (!alreadyLogged) {
            alreadyLogged = true;
            return success ? Ok(n) : Error(n);
        }

        return success ? Ok() : Error();
    }

    NvAPI_Status __cdecl NvAPI_D3D11_IsNvShaderExtnOpCodeSupported(IUnknown* pDeviceOrContext, NvU32 code, bool* supported) {
        constexpr auto n = "NvAPI_D3D11_IsNvShaderExtnOpCodeSupported";

        if (pDeviceOrContext == nullptr || supported == nullptr)
                return InvalidArgument(n);

        *supported = false;

        return Ok(str::format(n, " ", code));
    }
}
