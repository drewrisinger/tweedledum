# Distributed under the MIT License (See accompanying file /LICENSE)

set(SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Visualization/string_utf8.cpp
)

target_sources(tweedledum PUBLIC ${SRC})
if(TWEEDLEDUM_PYBINDS)
    target_sources(_tweedledum PUBLIC ${SRC})
endif()
