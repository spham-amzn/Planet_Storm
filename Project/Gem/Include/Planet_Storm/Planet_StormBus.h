
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

#include <Planet_Storm/Planet_StormTypeIds.h>

namespace Planet_Storm
{
    class Planet_StormRequests
    {
    public:
        AZ_RTTI(Planet_StormRequests, Planet_StormRequestsTypeId);
        virtual ~Planet_StormRequests() = default;
        // Put your public methods here
    };
    
    class Planet_StormBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Planet_StormRequestBus = AZ::EBus<Planet_StormRequests, Planet_StormBusTraits>;
    using Planet_StormInterface = AZ::Interface<Planet_StormRequests>;

} // namespace Planet_Storm
