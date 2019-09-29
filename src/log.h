#ifndef LOG_H
#define LOG_H

/** \file log.h
 * \brief cabecera de logging*/

#define BUZZ 0	/**< sistema buzzer*/
#define PUSH 1	/**< sistema PUSH*/
#define ERROR 0	/**< Nivel ERROR*/
#define DEBUG 1	/**< Nivel DEBUG*/

#define ON 1
#define OFF 0

/** \brief Interfaz del sistema de logging
 * \param sistema BUZZ, PUSH
 * \param nivel ERROR, DEBUG
 * \param mensaje "mensaje a enviar"*/
void logLed(short const sistema, short const nivel, char const *mensaje);
/** \brief Activa el logging globalmente*/
void logGlobalOn(void);
/** \brief Desactiva el logging globalmente*/
void logGlobalOff(void);
void openLog(void);
void closeLog(void);
/*Enciende y/o apaga led Log*/
void writeLog(short const estado);
short int readLog(void);

#endif
