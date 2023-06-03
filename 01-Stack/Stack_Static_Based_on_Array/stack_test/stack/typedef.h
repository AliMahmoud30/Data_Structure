#ifndef  TYPEDEF_H
#define  TYPEDEF_H


typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned long int   uint32_t;
typedef unsigned long long  uint64_t;

typedef signed char         sint8_t;
typedef signed short        sint16_t;
typedef signed long int     sint32_t;
typedef signed long long    sint64_t;

#define NULL        0
#define  ZERO        0(uint8_t)
typedef enum
{
    R_NOK,
    R_OK
}R_result;


#endif // TYPEDEF_H
