project('pomodoro', 'c')
views = ['src/led.c', 'src/blinker.c', 'src/buzzerController.c', 'src/buzzer.c',
'src/reboundHandler.c', 'src/button.c', 'src/gpioHandler.c', 'src/poweroff.c']
controller = ['src/controller.c', 'src/pomodoro.c']
timer = ['src/millis.c', 'src/timer.c', 'src/delay.c']
bussines = ['src/selector.c', 'src/play.c', 'src/pause.c']
incdir = include_directories('../test/')
avr_stubs = ['test/avr/io.c', 'test/avr/interrupt.c', 'test/avr/sleep.c']

executable('main.ihx', 'src/main.c', views, controller, timer, bussines, 
avr_stubs, include_directories: incdir)

