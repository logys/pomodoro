set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR "riscv")

set(CMAKE_C_COMPILER /home/antonio/Builds/riscv/bin/riscv64-unknown-elf-gcc)

set(CMAKE_C_FLAGS 
	"-g -Os -ffunction-sections\
	-static-libgcc -lgcc\
	-march=rv32ec_zicsr \
	-mabi=ilp32e \
	-DTINYVECTOR\
	-nostdlib\
	-flto -ffat-lto-objects\
	"
	CACHE INTERNAL "C Compiler Flags")
set(CMAKE_EXE_LINKER_FLAGS
	"-Wl,--gc-sections -flto -Wl,-flto\
	-T${PROJECT_SOURCE_DIR}/ch32v003/ch32v003fun.ld"
	CACHE INTERNAL "Linker options")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
