#include "player.h"
#include "..\globals.h"

#include <iostream>

namespace Player
{
    KeyBindToggle godmodeToggleKey;
    KeyBindToggle infiAmmoToggleKey;
    KeyBindToggle glueInstantToggleKey;
    KeyBindToggle instaHackToggleKey;
    KeyBindToggle fullAutoToggleKey;
    KeyBindToggle noRecoilToggleKey;
    KeyBindToggle noSpreadToggleKey;
    KeyBindToggle noShakeToggleKey;
    KeyBindToggle noFogToggleKey;
    KeyBindToggle fullBrightToggleKey;
    KeyBindToggle quickBioToggleKey;

    KeyBind giveHealthKey;
    KeyBind giveDisinKey;
    KeyBind giveAmmoKey;
    KeyBind giveClassAmmoKey;
    KeyBind giveResourcePackRelKey;
    KeyBind giveCurrentConsumableKey;

    void UpdateInput()
    {
        godmodeToggleKey.handleToggle();
        infiAmmoToggleKey.handleToggle();
        glueInstantToggleKey.handleToggle();
        instaHackToggleKey.handleToggle();
        fullAutoToggleKey.handleToggle();
        noRecoilToggleKey.handleToggle();
        noSpreadToggleKey.handleToggle();
        noShakeToggleKey.handleToggle();
        noFogToggleKey.handleToggle();
        fullBrightToggleKey.handleToggle();
        quickBioToggleKey.handleToggle();

        if (giveHealthKey.isPressed())
            GiveLocalHealth();
        if (giveDisinKey.isPressed())
            GiveLocalDisinfection();
        if (giveAmmoKey.isPressed())
            GiveLocalAmmo();
        if (giveClassAmmoKey.isPressed())
            GiveLocalClassAmmo();
        if (giveResourcePackRelKey.isPressed())
            GiveLocalResourcePackRel();
        if (giveCurrentConsumableKey.isPressed())
            GiveLocalCurrentConsumable();

    }

    void _GiveLocalHealth()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        if (!localPlayer)
            return;

        app::PlayerAgent_GiveHealth(localPlayer, localPlayer, 0.2f, nullptr);
    }

    void _GiveLocalDisinfection()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        if (!localPlayer)
            return;

        app::PlayerAgent_GiveDisinfection(localPlayer, localPlayer, 0.2f, nullptr);
    }

    void _GiveLocalAmmo()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        auto playerBackpack = app::PlayerBackpackManager_get_LocalBackpack(nullptr);
        if (!localPlayer || !playerBackpack)
            return;

        app::PlayerAgent_GiveAmmoRel(localPlayer, localPlayer, 0.2f, 0.2f, 0.0f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::ResourcePackRel, 99.0f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::CurrentConsumable, 99.0f, nullptr);
    }

    void _GiveLocalClassAmmo()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        auto playerBackpack = app::PlayerBackpackManager_get_LocalBackpack(nullptr);
        if (!localPlayer || !playerBackpack)
            return;

        app::PlayerAgent_GiveAmmoRel(localPlayer, localPlayer, 0.0f, 0.0f, 0.2f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::ResourcePackRel, 99.0f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::CurrentConsumable, 99.0f, nullptr);
    }

    void _GiveLocalResourcePackRel()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        auto playerBackpack = app::PlayerBackpackManager_get_LocalBackpack(nullptr);
        if (!localPlayer || !playerBackpack)
            return;

        //app::PlayerAgent_GiveAmmoRel(localPlayer, localPlayer, 0.0f, 0.0f, 0.2f, nullptr);
        app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::ResourcePackRel, 99.0f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::CurrentConsumable, 99.0f, nullptr);
    }

    void _GiveLocalCurrentConsumable()
    {
        auto localPlayer = app::PlayerManager_2_GetLocalPlayerAgent(nullptr);
        auto playerBackpack = app::PlayerBackpackManager_get_LocalBackpack(nullptr);
        if (!localPlayer || !playerBackpack)
            return;

        //app::PlayerAgent_GiveAmmoRel(localPlayer, localPlayer, 0.0f, 0.0f, 0.2f, nullptr);
        //app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::ResourcePackRel, 99.0f, nullptr);
        app::PlayerAmmoStorage_UpdateAmmoInPack(playerBackpack->fields.AmmoStorage, app::AmmoType__Enum::CurrentConsumable, 99.0f, nullptr);
    }

    void GiveLocalHealth()
    {
        G::callbacks.push([] { _GiveLocalHealth(); });
    }

    void GiveLocalDisinfection()
    {
        G::callbacks.push([] { _GiveLocalDisinfection(); });
    }

    void GiveLocalAmmo()
    {
        G::callbacks.push([] { _GiveLocalAmmo(); });
    }

    void GiveLocalClassAmmo()
    {
        G::callbacks.push([] { _GiveLocalClassAmmo(); });
    }

    void GiveLocalResourcePackRel()
    {
        G::callbacks.push([] { _GiveLocalResourcePackRel(); });
    }

    void GiveLocalCurrentConsumable()
    {
        G::callbacks.push([] { _GiveLocalCurrentConsumable(); });
    }
}
