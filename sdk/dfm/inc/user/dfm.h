/*
 * dfm.h
 *
 *  Created on: 2022-05-21 17:33
 *      Author: Jack Chen <redchenjs@live.com>
 */

#ifndef INC_USER_DFM_H_
#define INC_USER_DFM_H_

#define DFM_GATE_TIME_SHIFT *(volatile uint32_t *)(0x43C00000)
#define DFM_GATE_TIME_TOTAL *(volatile uint32_t *)(0x43C00004)

#define DFM_DATA_REG		*(volatile uint32_t *)(0x43C00008)
#define DFM_DATA_REF_CLK	*(volatile uint32_t *)(0x43C00008)
#define DFM_DATA_SIG_CLK	*(volatile uint32_t *)(0x43C0000C)

#define DFM_REF_CLK_MHZ		(250000000)

extern void dfm_task(void *pvParameters);

#endif /* INC_USER_DFM_H_ */
