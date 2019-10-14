#ifndef DRIVERS_H
#define DRIVERS_H
#include <stdint.h>
#include "timer.h"
#define ON 1	/**< Encendido */
#define OFF 0	/**< Apagado*/

/** \file drivers.h 
 * \brief 
 * Drivers, para buzzer, led y pushbuttons*/
/** \brief Inicia el LED*/
void openLed(void);
/** Detiene LED*/
void closeLed(void);

/** \brief Toggle */
void toggleLed(void);

#endif
