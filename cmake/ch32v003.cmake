set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR "riscv")

set(CMAKE_C_COMPILER /home/antonio/Builds/riscv32-unknown-elf.gcc-12.1.0/bin/riscv32-unknown-elf-gcc)

set(CMAKE_C_FLAGS 
	"-g -Wall -Os -Wextra -pipe\
	-static-libgcc -lgcc\
	-march=rv32i \
	-mabi=ilp32 \
	-DTINYVECTOR\
	-ffunction-sections\
	"
	CACHE INTERNAL "C Compiler Flags")
set(CMAKE_EXE_LINKER_FLAGS
	"-Wl,--gc-sections -nostartfiles --static\
	-specs=nano.specs -specs=nosys.specs\
	"
	CACHE INTERNAL "Linker options")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
