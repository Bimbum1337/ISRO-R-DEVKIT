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
