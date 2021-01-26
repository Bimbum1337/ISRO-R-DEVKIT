set(SOURCE_FILES
        include/remodel/Field.h
        include/remodel/GlobalPtr.h
        include/remodel/GlobalVar.h
        include/remodel/MemberFunctionHook.h
        include/remodel/StaticAddressHook.h)

add_library(remodel INTERFACE)
target_include_directories(remodel INTERFACE include/)
