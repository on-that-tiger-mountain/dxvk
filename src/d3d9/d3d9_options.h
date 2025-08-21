#pragma once

#include "../util/config/config.h"
#include "../dxvk/dxvk_device.h"

#include "d3d9_include.h"

namespace dxvk {

  struct D3D9Options {

    D3D9Options(const Rc<DxvkDevice>& device, const Config& config);

    /// Override PCI vendor and device IDs reported to the
    /// application. This may make apps think they are running
    /// on a different GPU than they do and behave differently.
    int32_t customVendorId;
    int32_t customDeviceId;
    std::string customDeviceDesc;

    /// Present interval. Overrides the value
    /// in D3DPRESENT_PARAMS used in swapchain present.
    int32_t presentInterval;

    /// Override maximum frame latency if the app specifies
    /// a higher value. May help with frame timing issues.
    int32_t maxFrameLatency;

    /// Set the max shader model the device can support in the caps.
    int32_t shaderModel;

    /// Whether or not managed resources should stay in memory until unlock, or until manually evicted.
    bool evictManagedOnUnlock;

    /// Whether or not to set the process as DPI aware in Windows when the API interface is created.
    bool dpiAware;
    
    /// Handle D3DLOCK_READONLY properly.
    ///
    /// Risen 1 writes to buffers mapped with readonly.
    bool allowLockFlagReadonly;

    /// True:  Copy our constant set into UBO if we are relative indexing ever.
    /// False: Copy our constant set into UBO if we are relative indexing at the start of a defined constant
    /// Why?:  In theory, FXC should never generate code where this would be an issue.
    bool strictConstantCopies;

    /// Whether or not we should care about pow(0, 0) = 1
    bool strictPow;

    /// Whether or not to do a fast path clear if we're close enough to the whole render target.
    bool lenientClear;

    /// Back buffer count for the Vulkan swap chain.
    /// Overrides buffer count in present parameters.
    int32_t numBackBuffers;

    /// Defer surface creation
    bool deferSurfaceCreation;

    /// Whether to transition to general
    /// for rendering hazards
    bool generalHazards;

    /// Anisotropic filter override
    ///
    /// Enforces anisotropic filtering with the
    /// given anisotropy value for all samplers.
    int32_t samplerAnisotropy;

    /// Max available memory override
    ///
    /// Changes the max initial value used in
    /// tracking and GetAvailableTextureMem
    uint32_t maxAvailableMemory;

    /// D3D9 Floating Point Emulation (anything * 0 = 0)
    bool d3d9FloatEmulation;

    /// Support the DF16 & DF24 texture format
    bool supportDFFormats;

    /// Support X4R4G4B4
    bool supportX4R4G4B4;

    /// Support D32
    bool supportD32;

    /// SWVP Constant Limits
    int32_t swvpFloatCount;
    int32_t swvpIntCount;
    int32_t swvpBoolCount;

    /// Disable D3DFMT_A8 for render targets.
    /// Specifically to work around a game
    /// bug in The Sims 2 that happens on native too!
    bool disableA8RT;

    /// Work around a NV driver quirk
    /// Fixes flickering/z-fighting in some games.
    bool invariantPosition;

    /// Whether or not to respect memory tracking for
    /// failing resource allocation.
    bool memoryTrackTest;

    /// Support VCACHE query
    bool supportVCache;

    /// Forced aspect ratio, disable other modes
    std::string forceAspectRatio;

    /// Enable dialog mode (ie. no exclusive fullscreen)
    bool enableDialogMode;

    /// Always use a spec constant to determine sampler type (instead of just in PS 1.x)
    /// Works around a game bug in Halo CE where it gives cube textures to 2d/volume samplers
    bool forceSamplerTypeSpecConstants;

    /// Forces an MSAA level on the swapchain
    int32_t forceSwapchainMSAA;

    /// Chinese Paladin 4
    bool playingChinesePaladin4;
  };

}