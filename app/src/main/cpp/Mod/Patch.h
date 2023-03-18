#ifndef PATCH_H
#define PATCH_H

struct Patches // you'll have to define here the patches
{
    MemoryPatch cheatDetectedBanner, clearProgress, showClearProgress, awakeCheat, updateCheat, get_cheaterConfig, set_cheaterConfig,
    checkSig, coinThreshold, gemThreshold, removedWeaponNames, removedWeaponString, polygonEnabled, IsDeveloperBuild;
};

Patches patches;

void Patches()
{
    // antiban
    patches.cheatDetectedBanner = MemoryPatch::createWithHex(LibraryToLoad, offsets->cheatDetectedBanner, "1E FF 2F E1");
    patches.cheatDetectedBanner.Modify();
    patches.clearProgress = MemoryPatch::createWithHex(LibraryToLoad, offsets->clearProgress, "1E FF 2F E1");
    patches.clearProgress.Modify();
    patches.showClearProgress = MemoryPatch::createWithHex(LibraryToLoad, offsets->showClearProgress, "1E FF 2F E1");
    patches.showClearProgress.Modify();
    patches.awakeCheat = MemoryPatch::createWithHex(LibraryToLoad, offsets->awakeCheat, "1E FF 2F E1");
    patches.awakeCheat.Modify();
    patches.updateCheat = MemoryPatch::createWithHex(LibraryToLoad, offsets->updateCheat, "1E FF 2F E1");
    patches.updateCheat.Modify();
    patches.get_cheaterConfig = MemoryPatch::createWithHex(LibraryToLoad, offsets->get_cheaterConfig, "1E FF 2F E1");
    patches.get_cheaterConfig.Modify();
    patches.set_cheaterConfig = MemoryPatch::createWithHex(LibraryToLoad, offsets->set_cheaterConfig, "1E FF 2F E1");
    patches.set_cheaterConfig.Modify();
    patches.checkSig = MemoryPatch::createWithHex(LibraryToLoad, offsets->checkSig, "1E FF 2F E1");
    patches.checkSig.Modify();
    patches.coinThreshold = MemoryPatch::createWithHex(LibraryToLoad, offsets->coinThreshold, "1E FF 2F E1");
    patches.coinThreshold.Modify();
    patches.gemThreshold = MemoryPatch::createWithHex(LibraryToLoad, offsets->gemThreshold, "1E FF 2F E1");
    patches.gemThreshold.Modify();

    // removed weps
    // patches.removedWeaponNames = MemoryPatch::createWithHex(LibraryToLoad, offsets->removedWeaponNames, "1E FF 2F E1");
    // patches.removedWeaponNames.Modify();
    // patches.removedWeaponString = MemoryPatch::createWithHex(LibraryToLoad, offsets->removedWeaponString, "1E FF 2F E1");
    // patches.removedWeaponString.Modify();

    // polygon enable
    patches.polygonEnabled = MemoryPatch::createWithHex(LibraryToLoad, offsets->polygonEnabled, "01 00 A0 E3 1E FF 2F E1");
    patches.polygonEnabled.Modify();

    // is developer build (*works as antiban lmao)
    patches.IsDeveloperBuild = MemoryPatch::createWithHex(LibraryToLoad, offsets->IsDeveloperBuild, "01 00 A0 E3 1E FF 2F E1");
    patches.IsDeveloperBuild.Modify();
}

#endif