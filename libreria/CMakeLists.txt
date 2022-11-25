## >>>>>>>>>>>>>>>
## >>>>>>>>>>>>>>>
add_library(libreria dummy.cpp structs.h funciones.h abrirPaciente.cpp resizePac.cpp abrirContacto.cpp resizeCont.cpp)
## <<<<<<<<<<<<<<<
## <<<<<<<<<<<<<<<

target_include_directories(libreria PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
