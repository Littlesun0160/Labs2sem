cmake_minimum_required(VERSION 3.25) # Проверка версии CMake.
									 # Если версия установленой программы
									 # старее указаной, произайдёт аварийный выход.

set(PROJECT_NAME lab3)				 # имя проекта		 
project("${PROJECT_NAME}")


set(CMAKE_CXX_STANDARD 17)			 # устанавливаем 17 стандарт языка
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_executable("${PROJECT_NAME}" main.cpp
							complex.hpp)
	
target_link_libraries("${PROJECT_NAME}" opengl32
								freetype
								winmm
								gdi32
								openal32
								flac
								vorbisenc
								vorbisfile
								vorbis
								ogg)