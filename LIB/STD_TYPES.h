/*
 * STD.TYPES.h
 *
 *  Created on: Sep 23, 2023
 *      Author: ahett
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char boolean;
typedef unsigned char uint8;
typedef unsigned char u8;
typedef unsigned char  STD_TYPE;
typedef unsigned short int unit16;
typedef unsigned short int u16;
typedef unsigned long  int unit32;
typedef unsigned long  int u32;
typedef unsigned long long unit64;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;
typedef signed long long s64;
typedef float float32;
typedef float f32;
typedef double float64;
typedef double f64;

#define ISR(VectNum)      void  VectNum(void)__attribute__((signal)); \
      	  	  	  	  	  void VectNum(void)

#define OK  0
#define NOK  1
#define NULL_POINTER  2

#define NULL   ((void*)0)
#endif /* STD_TYPES_H_ */
