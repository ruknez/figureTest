cmake_minimum_required(VERSION 3.12)


add_executable(main_cli main.cpp)
add_library(figures cFigure.cpp cRealFigures.cpp)

set_target_properties(main_cli figures PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_link_libraries(main_cli PRIVATE
figures
)

if (MSVC)
    target_compile_options(main_cli PRIVATE
        /W4
    )
    target_compile_options(figures PRIVATE
        /W4
    )
else ()
    target_compile_options(main_cli PRIVATE
        -Wall -O2 -Wextra -pedantic -Werror # -O2 решает (особеено в этом задании прирост производительности в 4 раза)
    )
    target_compile_options(figures PRIVATE
        -Wall -O2 -Wextra -pedantic -Werror
    )
endif()

#install(TARGETS sortIpV4HW2_cli RUNTIME DESTINATION bin)