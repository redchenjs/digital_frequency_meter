/*
 * disp.c
 *
 *  Created on: 2022-05-21 17:32
 *      Author: Jack Chen <redchenjs@live.com>
 */

#include <stdio.h>
#include <string.h>

#include "xil_types.h"
#include "xil_cache.h"
#include "xparameters.h"

#include "FreeRTOS.h"
#include "task.h"

#include "core/log.h"
#include "user/dfm.h"

#define TAG "dfmT"

void dfm_task(void *pvParameters)
{
	double sig_freq = 0.0;

	uint32_t ref_clk_cnt = 0;
	uint32_t sig_clk_cnt = 0;

    DFM_GATE_TIME_SHIFT = 49999999;
    DFM_GATE_TIME_TOTAL = 249999999;

    LOG_I(TAG, "Gate Time Shift: %lu", DFM_GATE_TIME_SHIFT + 1);
    LOG_I(TAG, "Gate Time Total: %lu", DFM_GATE_TIME_TOTAL + 1);

    LOG_I(TAG, "started.");

    while (1) {
        vTaskDelay(200 / portTICK_PERIOD_MS);

        DFM_DATA_REG = DFM_REF_CLK_MHZ;

        ref_clk_cnt = DFM_DATA_REF_CLK;
        sig_clk_cnt = DFM_DATA_SIG_CLK;

        LOG_W(TAG, "Ref Clk: %lu", ref_clk_cnt);
        LOG_W(TAG, "Sig Clk: %lu", sig_clk_cnt);

        sig_freq = (double)sig_clk_cnt / ref_clk_cnt * DFM_REF_CLK_MHZ;

        LOG_I(TAG, "Sig Freq: %.3f", sig_freq);
    }
}
