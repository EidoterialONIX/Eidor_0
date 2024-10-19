cmake_minimum_required(VERSION 3.30.0 FATAL_ERROR)


project(Eidor_0)

add_executable(Eidor_0 src/main.cpp 
src/camera.h src/camera.cpp 
src/collider.h src/collider.cpp  
src/collision.h src/collision.cpp 

src/EAGL/stb_image.h src/EAGL/stb_image.cpp 

src/EAGL/vectors.h src/EAGL/vectors.cpp 
src/EAGL/shader.h src/EAGL/shader.cpp 
src/EAGL/texture.h src/EAGL/texture.cpp 
src/EAGL/render.h src/EAGL/render.cpp 
src/EAGL/transform.h src/EAGL/transform.cpp 
src/EAGL/rect.h src/EAGL/rect.cpp 
src/EAGL/sprite.h src/EAGL/sprite.cpp 
src/EAGL/time.h src/EAGL/time.cpp
src/EAGL/color.h src/EAGL/color.cpp 
src/EAGL/surface.h src/EAGL/surface.cpp 
src/EAGL/font.h src/EAGL/font.cpp 
src/EAGL/text.h src/EAGL/text.cpp 
)

add_subdirectory(external/glad)
target_link_libraries(Eidor_0 glad)

add_subdirectory(external/glfw)
target_link_libraries(Eidor_0 glfw)