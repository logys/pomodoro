project('pomodoro', 'c')
add_global_arguments('-mmcu=attiny85', language : 'c')
[host_machine]
system = 'linux'
cpu_family = 'avr'
cpu = 'attiny85'
endian = 'little'

views = ['src/led.c', 'src/blinker.c', 'src/buzzerController.c', 'src/buzzer.c',
'src/reboundHandler.c', 'src/button.c', 'src/gpioHandler.c', 'src/poweroff.c']
controller = ['src/controller.c', 'src/pomodoro.c']
timer = ['src/millis.c', 'src/timer.c', 'src/delay.c']
bussines = ['src/selector.c', 'src/play.c', 'src/pause.c']
incdir = include_directories('/usr/avr/include')

executable('main.elf', 'src/main.c', views, controller, timer, bussines, 
include_directories: incdir)
  
