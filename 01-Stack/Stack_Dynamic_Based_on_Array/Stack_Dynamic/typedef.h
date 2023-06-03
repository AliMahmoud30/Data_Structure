/*************************************************/
/** Author : Ali Morsy                           */
/** Date   : 29-4-2023                           */
/** VER    : V1.0                                */
/*************************************************/


#ifndef TYPEDEF_H
#define TYPEDEF_H
#define     ZERO    0
typedef unsigned char           uint8_t;
typedef unsigned short          uint16_t;
typedef unsigned long int       uint32_t;
typedef unsigned long long      uint64_t;

typedef signed char             sint8_t;
typedef signed short            sint16_t;
typedef signed long int         sint32_t;
typedef signed long long        sint64_t;

typedef enum
{
    R_NOK,
    R_OK
}Return_Status_t;

#endif // TYPEDEF_H
