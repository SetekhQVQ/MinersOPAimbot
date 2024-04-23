#pragma once
#include "..\InputUtil.h"
#include "..\globals.h"
#include <map>
#include <array>

namespace ESP
{
    static std::map<std::string, std::string> espItems = {
        { "Ammo Pack", "R-弹药包" },
        { "artifact_muted", "A-督察红晶：低效" },
        { "artifact_bold", "A-督察红晶：高效" },
        { "artifact_aggressive", "A-督察红晶：特效" },
        { "Bulkhead", "U-舱壁门控制器" },
        { "BULKHEAD_KEY", "U-舱壁门钥匙" },
        { "Cargo Crate", "Cargo Crate" },
        { "Cargo Crate High Security", "Cargo Crate HISEC" },
        { "Collection Case", "Collection Case" },
        { "Cryo Hardcase", "Cryogenic Case" },
        { "结沫榴弹", "T-结沫榴弹" },
        { "C-Foam Tripmine", "T-结沫绊雷" },
        { "DATA_CUBE", "Data Cube" },
        { "DATA SPHERE", "Data Sphere" },
        { "Disinfection Pack", "R-消毒包" },
        { "爆炸绊雷", "T-爆炸绊雷" },
        { "驱雾器", "T-驱雾器" },
        { "Fog Repeller Turbine", "U-大驱雾器" },
        { "发光棒", "T-发光棒" },
        { "GLP Hormone", "GLP Canister" },
        { "Hard drive", "Hard Drive" },
        { "HSU", "HSU" },
        { "I2-LP注射器", "T-I2-LP注射器"},
        { "IIx注射器", "T-IIx注射器"},
        { "IMPRINTED NEONATE HSU", "Imprinted Neonate HSU" },
        { "KEYCARD", "U-钥匙卡" },
        { "熔锁器", "T-熔锁器" },
        { "远程手电筒", "T-远程手电筒" },
        { "MATTER_WAVE_PROJECTOR", "Matter Wave Projector" },
        { "MediPack", "R-医疗包" },
        { "NEONATE_HSU", "Neonate HSU" },
        { "OSIP Hormone", "OSIP Hormone" },
        { "Partial Decoder", "Partial Decoder" },
        { "Personnel ID", "Personnel ID" },
        { "Plant Sample", "Plant Sample" },
        { "Power Cell", "U-电池" },
        { "Terminal", "U-终端" },
        { "Tool Refill Pack", "R-工具包" },
    };

    struct WorldESPItem
    {
        bool enabled = false;
        int renderDistance = 250;
        ImVec4 renderColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 outlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
    };

    struct WorldPickupItem
    {
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldPickupItem(app::LG_PickupItem_Sync* pickupItem, float distance = -1.0f)
        {
            this->pickupItem = pickupItem;
            this->distance = distance;
        }

        void update()
        {
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldPickupItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldArtifactItem
    {
        app::ArtifactPickup_Core* artifactItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldArtifactItem(app::ArtifactPickup_Core* artifactItem, float distance = -1.0f)
        {
            this->artifactItem = artifactItem;
            this->distance = distance;
        }

        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(artifactItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldArtifactItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldCarryItem
    {
        app::CarryItemPickup_Core* carryItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldCarryItem(app::CarryItemPickup_Core* carryItem, float distance = -1.0f)
        {
            this->carryItem = carryItem;
            this->distance = distance;
        }

        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(carryItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldCarryItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldKeyItem
    {
        app::KeyItemPickup_Core* keyItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldKeyItem(app::KeyItemPickup_Core* keyItem, float distance = -1.0f)
        {
            this->keyItem = keyItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(keyItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldKeyItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldGenericItem
    {
        app::GenericSmallPickupItem_Core* genericItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;

        WorldGenericItem(app::GenericSmallPickupItem_Core* genericItem, float distance = -1.0f)
        {
            this->genericItem = genericItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(genericItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldGenericItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldResourceItem
    {
        app::ResourcePackPickup* resourceItem;
        app::LG_PickupItem_Sync* pickupItem;
        app::pPickupItemState state;
        float distance;
        
        WorldResourceItem(app::ResourcePackPickup* resourceItem, float distance = -1.0f)
        {
            this->resourceItem = resourceItem;
            this->distance = distance;
        }
        
        void update()
        {
            this->pickupItem = reinterpret_cast<app::LG_PickupItem_Sync*>(resourceItem->fields.m_sync);
            this->state = app::LG_PickupItem_Sync_GetCurrentState(this->pickupItem, NULL);
            this->distance = app::Vector3_Distance(this->state.placement.position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldResourceItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldTerminalItem
    {
        app::LG_ComputerTerminal* terminalItem;
        float distance;

        WorldTerminalItem(app::LG_ComputerTerminal* terminalItem, float distance = -1.0f)
        {
            this->terminalItem = terminalItem;
            this->distance = distance;
        }

        void update()
        {
            this->distance = app::Vector3_Distance(terminalItem->fields.m_position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldTerminalItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldHSUItem
    {
        app::LG_HSU* hsuItem;
        app::LG_GenericTerminalItem* terminalItem;
        app::Vector3 position;
        float distance;

        WorldHSUItem(app::LG_HSU* hsuItem)
        {
            this->hsuItem = hsuItem;
        }

        void update()
        {
            this->terminalItem = reinterpret_cast<app::LG_GenericTerminalItem*>(hsuItem->fields.m_terminalItem);
            this->position = app::LG_GenericTerminalItem_get_LocatorBeaconPosition(this->terminalItem, NULL);
            this->distance = app::Vector3_Distance(this->position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldHSUItem& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct WorldBulkheadDC
    {
        app::LG_BulkheadDoorController_Core* bulkheadDC;
        app::LG_GenericTerminalItem* terminalItem;
        app::Vector3 position;
        float distance;

        WorldBulkheadDC(app::LG_BulkheadDoorController_Core* bulkheadDC)
        {
            this->bulkheadDC = bulkheadDC;
        }

        void update()
        {
            this->terminalItem = reinterpret_cast<app::LG_GenericTerminalItem*>(bulkheadDC->fields.m_terminalItem);
            this->position = app::LG_GenericTerminalItem_get_LocatorBeaconPosition(this->terminalItem, NULL);
            this->distance = app::Vector3_Distance(this->position, G::localPlayer->fields.m_goodPosition, NULL);
        }

        bool operator>(const WorldBulkheadDC& rhs) const
        {
            return this->distance > rhs.distance;
        }
    };

    struct AgentESPSection
    {
        std::string type;
        bool show = true;
        
        bool showBoxes = true;
        ImVec4 boxesColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 boxesOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);

        bool showHealthBar = true;
        int healthBarThickness = 3;
        bool healthBarText = true;
        bool healthBarTextFull = true;
        ImVec4 healthBarTextColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 healthBarTextOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        
        bool showInfo = true;
        bool showName = true;
        bool showType = true;
        bool showHealth = true;
        bool showDistance = true;
        ImVec4 textColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        ImVec4 textOutlineColor = ImVec4(0.0f, 0.0f, 0.0f, 1.0f);
        
        int renderDistance = 250;

        bool showSkeleton = true;
        ImVec4 skeletonColor = ImVec4(1.0f, 1.0f, 1.0f, 1.0f);
        int skeletonRenderDistance = 250;
        float skeletonThickness = 1.0f;

        AgentESPSection(std::string type)
        {
            this->type = type;
        }
    };

    struct AgentESP
    {
        KeyBindToggle toggleKey;
        AgentESPSection visibleSec = AgentESPSection("Visible");
        AgentESPSection nonVisibleSec = AgentESPSection("NonVisible");
    };

    extern std::map<std::string, std::string> espItemsReverse;
    extern std::map<std::string, WorldESPItem*> espItemsMap;

    extern KeyBindToggle worldESPToggleKey;
    extern AgentESP enemyESP;

    extern std::vector<WorldPickupItem> worldItems;
    extern std::vector<WorldArtifactItem> worldArtifacts;
    extern std::vector<WorldCarryItem> worldCarryItems;
    extern std::vector<WorldKeyItem> worldKeys;
    extern std::vector<WorldGenericItem> worldGenerics;
    extern std::vector<WorldResourceItem> worldResourcePacks;
    extern std::vector<WorldHSUItem> worldHSUItems;

    extern std::vector<WorldBulkheadDC> worldBulkheadDCs;
    extern std::vector<WorldTerminalItem> worldTerminals;

    void Init();
    void UpdateInput();
}
