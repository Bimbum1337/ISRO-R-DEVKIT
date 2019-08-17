set(SOURCE_FILES src/BufRender.h
    src/CameraWorking.cpp
    src/CameraWorking.h
    src/Client.cpp
    src/Client.h
    src/DxSound.h
    src/EntityManager.h
    src/EntityManagerClient.h
    src/ETime.h
    src/Game.cpp
    src/Game.h
    src/GEffSound.h
    src/GEffSoundBody.cpp
    src/GEffSoundBody.h
    src/GFXMainFrame.cpp
    src/GFXMainFrame.h
    src/GInterface.cpp
    src/GInterface.h
    src/GlobalHelpersThatHaveNoHomeYet.h
    src/GObj.h
    src/GWnd.cpp
    src/GWnd.h
    src/GWndBase.cpp
    src/GWndBase.h
    src/IDxSound.h
    src/IEntity.h
    src/IFAction.h
    src/IFButton.cpp
    src/IFButton.h
    src/IFCloseButton.cpp
    src/IFCloseButton.h
    src/IFConsole.h
    src/IFDecoratedStatic.cpp
    src/IFDecoratedStatic.h
    src/IFDragableArea.cpp
    src/IFDragableArea.h
    src/IFEdit.h
    src/IFEquipment.h
    src/IFFade.h
    src/IFFrame.cpp
    src/IFFrame.h
    src/IFGauge.h
    src/IFHelperBubbleWindow.h
    src/IFInventory.h
    src/IFListCtrl.h
    src/IFMainFrame.cpp
    src/IFMainFrame.h
    src/IFMainPopup.h
    src/IFNPCTalk.h
    src/IFNPCWindow.h
    src/IFParty.h
    src/IFPartySlot.h
    src/IFPlayerInfo.h
    src/IFPlayerMiniInfo.cpp
    src/IFPlayerMiniInfo.h
    src/IFPractice.h
    src/IFQuest.h
    src/IFQuickStateHalfWnd.h
    src/IFQuickStateWnd.h
    src/IFScrollBar.h
    src/IFScrollManager.h
    src/IFSkill.h
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
    src/IFStretchWnd.h
    src/IFSupporterChatWnd.h
    src/IFTextBox.h
    src/IFTileWnd.cpp
    src/IFTileWnd.h
    src/IFTimerWnd.h
    src/IFVerticalScroll.h
    src/IFWnd.cpp
    src/IFWnd.h
    src/IObject.h
    src/IRMManager.cpp
    src/IRMManager.h
    src/is_this_important.cpp
    src/is_this_important.h
    src/MessageBoxManager.h
    src/MsgHandler.cpp
    src/MsgHandler.h
    src/multibyte.cpp
    src/multibyte.h
    src/NavigationDeadreckon.cpp
    src/NavigationDeadreckon.h
    src/Process.cpp
    src/Process.h
    src/PSilkroad.cpp
    src/PSilkroad.h
    src/PSOuterInterface.cpp
    src/PSOuterInterface.h
    src/PSVersionCheck.cpp
    src/PSVersionCheck.h
    src/RTLoading.cpp
    src/RTLoading.h
    src/StdAfx.cpp
    src/StdAfx.h
    src/StringUtils.h
    src/TextBoard.cpp
    src/TextBoard.h
    src/unsorted.cpp
    src/unsorted.h
    src/AlramGuideMgrWnd.cpp src/AlramGuideMgrWnd.h
    src/IFConfirmReputationGuide.cpp src/IFConfirmReputationGuide.h
    src/IFEventGuide.cpp src/IFEventGuide.h
    src/IFQuestInfoGuide.cpp src/IFQuestInfoGuide.h
    src/IFLetterAlarmGuide.cpp src/IFLetterAlarmGuide.h
    src/IFServerEventGuide.cpp src/IFServerEventGuide.h
    src/IFOpenMarketAlramGuide.cpp src/IFOpenMarketAlramGuide.h
    src/IFEventGuideSecond.cpp src/IFEventGuideSecond.h
    src/IFflorian0Guide.cpp src/IFflorian0Guide.h
    src/PSQuickStart.cpp
    src/PSQuickStart.h)

add_library(ClientLib STATIC ${SOURCE_FILES})
target_link_libraries(ClientLib GFX3DFunction GFXFileManagerLIB NavMesh abi-testing imgui remodel ghidra)
target_include_directories(ClientLib PUBLIC src/)
