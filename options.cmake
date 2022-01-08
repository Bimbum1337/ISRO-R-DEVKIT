option(CONFIG_TRANSLATIONS_DEBUG "Print Tokens instead of translated strings" OFF)
if (CONFIG_TRANSLATIONS_DEBUG)
    add_definitions(-DCONFIG_TRANSLATIONS_DEBUG)
endif()

option(CONFIG_OLD_UNDERBAR "Turn the old EXP Bar ON/OFF" OFF)
if (CONFIG_OLD_UNDERBAR)
    add_definitions(-DCONFIG_OLD_UNDERBAR)
endif()

option(CONFIG_CHATVIEWER "Use the custom chatviewer supplied in SRO_DevKit" OFF)
if (CONFIG_CHATVIEWER)
    add_definitions(-DCONFIG_CHATVIEWER)
endif()

option(CONFIG_CHATVIEWER_BADWORDFILTER "Enable the Bad Word Filter" ON)
if(CONFIG_CHATVIEWER_BADWORDFILTER)
    add_definitions(-DCONFIG_CHATVIEWER_BADWORDFILTER)
endif()

option(CONFIG_IMGUI "Enable ImGui" ON)
if (CONFIG_IMGUI)
    add_definitions(-DCONFIG_IMGUI)
endif()

option(CONFIG_DEBUG_REDIRECT_PUTDUMP "Redirect the PutDump output to the console" ON)
if (CONFIG_DEBUG_REDIRECT_PUTDUMP)
    add_definitions(-DCONFIG_DEBUG_REDIRECT_PUTDUMP)
endif()

option(CONFIG_DEBUG_CONSOLE "Show the debug console" ON)
if (CONFIG_DEBUG_CONSOLE)
    add_definitions(-DCONFIG_DEBUG_CONSOLE)
endif()

option(CONFIG_DEBUG_NET_RECEIVE "Print NetProcess debug messages on receive" OFF)
if (CONFIG_DEBUG_NET_RECEIVE)
    add_definitions(-DCONFIG_DEBUG_NET_RECEIVE)
endif ()

option(CONFIG_OLD_MAINPOPUP "Classic MainPopup with icons on the side" OFF)
if (CONFIG_OLD_MAINPOPUP)
    add_definitions(-DCONFIG_OLD_MAINPOPUP)
endif ()

option(CONFIG_WHOLE_CHAT "Replace global chat dialog with custom one" OFF)
if (CONFIG_WHOLE_CHAT)
    add_definitions(-DCONFIG_WHOLE_CHAT)
endif ()

option(CONFIG_MAINPOP_PLAYERINFO "Use Playerinfor implementation in SRO_DevKit" OFF)
if (CONFIG_MAINPOP_PLAYERINFO)
    add_definitions(-DCONFIG_MAINPOP_PLAYERINFO)
endif()
