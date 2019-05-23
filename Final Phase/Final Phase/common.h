/*
 * common.h
 *
 * Created: 4/22/2017 12:46:01 PM
 *  Author: A.Aboelmakarem
 */ 


#ifndef COMMON_H_
#define COMMON_H_

#define SET_BIT(reg,bitnum) reg|=(1<<bitnum)
#define CLR_BIT(reg,bitnum) reg&=~(1<<bitnum)
#define GET_BIT(reg,bitnum) (reg&(1<<bitnum))>>bitnum



#endif /* COMMON_H_ */