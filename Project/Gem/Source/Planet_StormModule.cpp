#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Planet_StormSystemComponent.h"

#include <Planet_Storm/Planet_StormTypeIds.h>

namespace Planet_Storm
{
    class Planet_StormModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Planet_StormModule, Planet_StormModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(Planet_StormModule, AZ::SystemAllocator);

        Planet_StormModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Planet_StormSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Planet_StormSystemComponent>(),
            };
        }
    };
}// namespace Planet_Storm

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), Planet_Storm::Planet_StormModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_Planet_Storm, Planet_Storm::Planet_StormModule)
#endif
