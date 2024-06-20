/*
 * Macros.h
 *
 *  Created on: Sep 23, 2023
 *      Author: ahett
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(Reg,BitNo)	Reg|=(1<<BitNo)
#define CLR_BIT(Reg,BitNo)	Reg&=(~(1<<BitNo))
#define TOG_BIT(Reg,BitNo)	Reg^=(1<<BitNo)
#define GET_BIT(Reg,BitNo)	((Reg>>BitNo)&1)


#endif /* MACROS_H_ */
