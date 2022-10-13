
set(SOURCE_FILES src/BufRender.h
    src/CameraWorking.cpp
    src/CameraWorking.h
    src/Client.h
    src/Data/ActionWndData.h
    src/Data/CharacterData.h src/Data/CharacterData.cpp
    src/Data/DropGoldData.h
    src/Data/GachaItemSetData.h
    src/Data/GachaNpcData.h
    src/Data/GameGuideData.h
    src/Data/ItemData.h src/Data/ItemData.cpp
    src/Data/LevelData.h
    src/Data/LevelGoldData.h
    src/Data/MagicOptionData.h
    src/Data/MallItemMenuListData.h
    src/Data/MessageTipData.h
    src/Data/NPCChatData.h
    src/Data/NPCPosData.h
    src/Data/QuestData.h
    src/Data/RefPackageItemData.h
    src/Data/RefPricePolicyOfItem.h
    src/Data/RefScrapOfPackageItemData.h
    src/Data/RefShopdata.h
    src/Data/RefShopTabData.h
    src/Data/RefShopTabGroupData.h
    src/Data/ShopItemStockPeriod.h
    src/Data/ShopItemStockQuantity.h
    src/Data/TeleportBuilding.h
    src/Data/TeleportData.h
    src/Data/TeleportLink.h
    src/DxSound.h
    src/EntityManagerClient.h
    src/Game.cpp
    src/Game.h
    src/GEffSound.h
    src/GEffSoundBody.cpp
    src/GEffSoundBody.h
    src/GInterface.cpp
    src/GInterface.h
    src/GlobalDataManager.cpp src/GlobalDataManager.h
    src/GlobalHelpersThatHaveNoHomeYet.h
    src/GObj.h
    src/IDxSound.h
    src/IFAction.h
    src/IFApprenticeShip.h
    src/IFApprenticeShipSlot.h
    src/IFButton.cpp
    src/IFButton.h
    src/IFChatViewer.cpp src/IFChatViewer.h
    src/IFCloseButton.cpp
    src/IFCloseButton.h
    src/IFConsole.h
    src/IFDecoratedStatic.cpp
    src/IFDecoratedStatic.h
    src/IFDragableArea.cpp
    src/IFDragableArea.h
    src/IFEdit.h
    src/IFEquipment.h
    src/IFFade.h src/IFFade.cpp
    src/IFFrame.cpp
    src/IFFrame.h
    src/IFGauge.h
    src/IFHelperBubbleWindow.h
    src/IFInventory.cpp src/IFInventory.h
    src/IFMainFrame.cpp
    src/IFMainFrame.h
    src/IFMainPopup.cpp src/IFMainPopup.h
    src/IFNPCTalk.h
    src/IFNPCWindow.h
    src/IFParty.h
    src/IFPartySlot.h
    src/IFPlayerInfo.h src/IFPlayerInfo.cpp
    src/IFPlayerMiniInfo.cpp
    src/IFPlayerMiniInfo.h
    src/IFPractice.h
    src/IFQuest.h
    src/IFQuickStateHalfWnd.h
    src/IFQuickStateWnd.h
    src/IFScrollManager.h
    src/IFSelectableArea.h
    src/IFSkill.h src/IFSkill.cpp
    src/IFSkillBoard.h
    src/IFSkillPracticeBox.h
    src/IFSlotWithHelp.h
    src/IFSpinButtonCtrl.h
    src/IFStatic.cpp
    src/IFStatic.h
    src/IFStaticWithPictureClip.h
    src/IFSystemMessage.cpp
    src/IFSystemMessage.h
    src/IFStorageRoom.h
    src/IFStoreForPackage.h
    src/IFStretchWnd.cpp src/IFStretchWnd.h
    src/IFSupporterChatWnd.h
    src/IFTextBox.h
    src/IFTileWnd.cpp
    src/IFTileWnd.h
    src/IFTimerWnd.h
    src/IFWnd.cpp
    src/IFWnd.h
    src/IObject.h src/IObject.cpp
    src/IRMManager.cpp
    src/IRMManager.h
    src/is_this_important.cpp
    src/is_this_important.h
    src/MessageBoxManager.h
    src/NavigationDeadreckon.cpp
    src/NavigationDeadreckon.h
    src/PSilkroad.cpp
    src/PSilkroad.h
    src/PSOuterInterface.cpp
    src/PSOuterInterface.h
    src/PSVersionCheck.h
    src/RTLoading.cpp
    src/RTLoading.h
    src/StringUtils.h
    src/TextBoard.cpp
    src/TextBoard.h
    src/unsorted.cpp
    src/unsorted.h
    src/AlramGuideMgrWnd.cpp src/AlramGuideMgrWnd.h
    src/IFConfirmReputationGuide.cpp src/IFConfirmReputationGuide.h
    src/IFEventGuide.cpp src/IFEventGuide.h
    src/IFQuestInfoGuide.cpp src/IFQuestInfoGuide.h
    src/IFLetterAlarmGuide.h
    src/IFServerEventGuide.cpp src/IFServerEventGuide.h
    src/IFOpenMarketAlramGuide.cpp src/IFOpenMarketAlramGuide.h
    src/IFEventGuideSecond.cpp src/IFEventGuideSecond.h
    src/IFflorian0Guide.cpp src/IFflorian0Guide.h
    src/PSQuickStart.cpp
    src/PSQuickStart.h
    src/NIFUnderMenuBar.cpp src/NIFUnderMenuBar.h
    src/TextStringManager.cpp src/TextStringManager.h
    src/IFNotify.cpp src/IFNotify.h
    src/IFListCtrl.cpp src/IFListCtrl.h
    src/LinkedScroll.cpp src/LinkedScroll.h
    src/IFVerticalScroll.cpp src/IFVerticalScroll.h
    src/IFScrollBar.h
    src/IFTextBox.cpp src/IFTextBox.h
    src/IFSelectableArea.cpp src/IFSelectableArea.h
    src/IFChatModeViewer.cpp src/IFChatModeViewer.h
    src/ICPlayer.h src/ICPlayer.cpp
    src/SOItem.h src/SOItem.cpp
    src/ICUser.cpp src/ICUser.h
    src/IFEdit.cpp src/IFEdit.h
    src/SRO_MSG_DEF.h
    src/CharacterDependentData.cpp src/CharacterDependentData.h
    src/NIFCommunityWnd.cpp src/NIFCommunityWnd.h
    src/NIFBlockWnd.cpp src/NIFBlockWnd.h
    src/ICharactor.cpp src/ICharactor.h
    src/ClassLink.h
    src/IGIDObject.cpp src/IGIDObject.h
    src/IFNotify.cpp src/IFNotify.h
    src/NetProcessIn.cpp src/NetProcessIn.h
    src/NetProcessSecond.cpp src/NetProcessSecond.h
    src/NetProcessThird.cpp src/NetProcessThird.h
    src/PSMission.h
    src/GameCfg.cpp src/GameCfg.h
    src/LocalTime.cpp src/LocalTime.h
    src/IFCheckBox.cpp src/IFCheckBox.h
    src/IFChatOptionBoard.cpp src/IFChatOptionBoard.h
    src/PSCharacterSelect.cpp src/PSCharacterSelect.h
    src/CObjAnimation.h src/CObjAnimation.cpp
    src/AnimationCallback.h
    src/World.h src/World.cpp
    src/CompSimple.cpp src/CompSimple.h
    src/Keyframe.h src/Keyframe.cpp
    src/UserGuildInfo.cpp src/UserGuildInfo.h
    src/PartyData.h
    src/PartyMemberData.h
    src/IFWholeChat.cpp src/IFWholeChat.h
    src/IFBuffViewer.cpp src/IFBuffViewer.h
    src/IFTargetWindow.cpp src/IFTargetWindow.h
    src/IFTargetWindowPlayer.cpp src/IFTargetWindowPlayer.h
    src/IFTargetWindowJobPlayer.cpp src/IFTargetWindowJobPlayer.h
    src/IFTargetWindowSpecialMob.cpp src/IFTargetWindowSpecialMob.h
    src/IFTargetWindowCommonEnemy.cpp src/IFTargetWindowCommonEnemy.h
    src/IFTargetWindowFortressStructure.cpp src/IFTargetWindowFortressStructure.h
    src/ICNonuser.cpp src/ICNonuser.h
    src/ICMonster.cpp src/ICMonster.h
    src/ICCos.cpp src/ICCos.h src/Juicer/IFTestExample.h src/Juicer/IFTestExample.cpp src/IFNormalTile.h src/IFNormalTile.cpp src/IFWebItemAlram.cpp src/IFWebItemAlram.h src/IFSignLocationGuide.h src/IFSignLocationGuide.cpp src/IFMacroSystemGuide.cpp src/IFMacroSystemGuide.h src/IFMagicLampAlram.h src/IFMagicLampAlram.cpp src/IFAttendanceEventGuid.cpp src/IFAttendanceEventGuid.h src/IFSurvivalPVPEstimateTimeAlram.cpp src/IFSurvivalPVPEstimateTimeAlram.h src/IFFacebookLinkAlram.cpp src/IFFacebookLinkAlram.h src/IFDailyLoginAlram.cpp src/IFDailyLoginAlram.h)

add_library(ClientLib STATIC ${SOURCE_FILES})
target_link_libraries(ClientLib GFXMainFrame GFX3DFunction GFXFileManagerLIB NavMesh ClientNet SimpleViewer TypeId abi-testing imgui remodel ghidra)
target_include_directories(ClientLib PUBLIC src/)
