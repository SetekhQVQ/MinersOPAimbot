#pragma once
#include "..\InputUtil.h"


namespace Player
{
    extern KeyBindToggle godmodeToggleKey;
    extern KeyBindToggle infiAmmoToggleKey;
    extern KeyBindToggle glueInstantToggleKey;
    extern KeyBindToggle instaHackToggleKey;
    extern KeyBindToggle fullAutoToggleKey;
    extern KeyBindToggle noRecoilToggleKey;
    extern KeyBindToggle noSpreadToggleKey;
    extern KeyBindToggle noShakeToggleKey;
    extern KeyBindToggle noFogToggleKey;
    extern KeyBindToggle fullBrightToggleKey;
    extern KeyBindToggle quickBioToggleKey;

    extern KeyBind giveHealthKey;
    extern KeyBind giveDisinKey;
    extern KeyBind giveAmmoKey;
    extern KeyBind giveClassAmmoKey;
    extern KeyBind giveResourcePackRelKey;
    extern KeyBind giveCurrentConsumableKey;

    void UpdateInput();

    void GiveLocalHealth();
    void GiveLocalDisinfection();
    void GiveLocalAmmo();
    void GiveLocalClassAmmo();
    void GiveLocalResourcePackRel();
    void GiveLocalCurrentConsumable();
}
