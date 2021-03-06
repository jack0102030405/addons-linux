#ifndef __SL_PADMUX_H
#define __SL_PADMUX_H

/* NOTE: SHOULD SYNCHRONIZED UPDATING WITH KERNEL */

#define PIN_NUM				6 * 32
#define PAD_ID_NUM			4
#define GPIO_NAME_LENTH		9
#define USED_BY_PADS_SIZE	7

enum silan_pad_ids{
	/* reg 17 */
	SILAN_PADMUX_START			= 17 * 32 + 0,
	SILAN_PADMUX_SDRAM			= 17 * 32 + 0,
	SILAN_PADMUX_ETH1_GMII		= 17 * 32 + 1,
	SILAN_PADMUX_ETH0_RGMII		= 17 * 32 + 2,
	SILAN_PADMUX_ETH1_RGMII		= 17 * 32 + 3,
	SILAN_PADMUX_ETH1_RMII		= 17 * 32 + 4,
	SILAN_PADMUX_VIU_PORT0		= 17 * 32 + 5,
	SILAN_PADMUX_TS				= 17 * 32 + 6,
	SILAN_PADMUX_USB_OTG		= 17 * 32 + 7,
	SILAN_PADMUX_SSP			= 17 * 32 + 9,
	SILAN_PADMUX_SPI_NORMAL		= 17 * 32 + 10,
	SILAN_PADMUX_ETH0_MII		= 17 * 32 + 11,
	SILAN_PADMUX_ETH0_RMII		= 17 * 32 + 12,
	SILAN_PADMUX_SCI			= 17 * 32 + 13,
	SILAN_PADMUX_TCON			= 17 * 32 + 14,
	SILAN_PADMUX_BT656			= 17 * 32 + 15,
	SILAN_PADMUX_I2S_T4			= 17 * 32 + 16,
	SILAN_PADMUX_APWM_CH0		= 17 * 32 + 17,
	SILAN_PADMUX_SPDIF_IN		= 17 * 32 + 18,
	SILAN_PADMUX_SPDIF_OUT		= 17 * 32 + 19,
	SILAN_PADMUX_UART0			= 17 * 32 + 20,
	SILAN_PADMUX_UART1			= 17 * 32 + 21,
	SILAN_PADMUX_UART2			= 17 * 32 + 22,
	SILAN_PADMUX_I2C0			= 17 * 32 + 24,
	SILAN_PADMUX_I2C1			= 17 * 32 + 25,
	SILAN_PADMUX_UART3			= 17 * 32 + 26,
	SILAN_PADMUX_UART3_FL		= 17 * 32 + 27,
	SILAN_PADMUX_I2C2			= 17 * 32 + 28,
	SILAN_PADMUX_BT601			= 17 * 32 + 29,
	SILAN_PADMUX_VSYNC			= 17 * 32 + 30,
	SILAN_PADMUX_BT1120			= 17 * 32 + 31,
	/* reg 18 */
	SILAN_PADMUX_EMMC			= 18 * 32 + 0,
	SILAN_PADMUX_SD				= 18 * 32 + 1,
	SILAN_PADMUX_SDIO			= 18 * 32 + 2,
	SILAN_PADMUX_PWM0			= 18 * 32 + 4,
	SILAN_PADMUX_PWM1			= 18 * 32 + 5,
	SILAN_PADMUX_PWM2			= 18 * 32 + 6,
	SILAN_PADMUX_HDMI			= 18 * 32 + 7,
	SILAN_PADMUX_VIU_PORT2		= 18 * 32 + 8,
	SILAN_PADMUX_VIU_PORT3		= 18 * 32 + 9,
	SILAN_PADMUX_HDMI_DIG		= 18 * 32 + 10,
	SILAN_PADMUX_I2S_MIC		= 18 * 32 + 11,
	SILAN_PADMUX_I2S_MCLK		= 18 * 32 + 12,
	SILAN_PADMUX_CAN			= 18 * 32 + 13,
	SILAN_PADMUX_SDIO_WR_PRT	= 18 * 32 + 14,
	SILAN_PADMUX_UART6			= 18 * 32 + 15,
	SILAN_PADMUX_HDMI_TEST		= 18 * 32 + 16,
	SILAN_PADMUX_PWM3			= 18 * 32 + 17,
	SILAN_PADMUX_ISP			= 18 * 32 + 18,
	SILAN_PADMUX_VIU_PORT1		= 18 * 32 + 19,
	SILAN_PADMUX_SERIAL_TS		= 18 * 32 + 20,
	SILAN_PADMUX_EMMC_DETECT	= 18 * 32 + 21,
	SILAN_PADMUX_EMMC_POWER		= 18 * 32 + 22,
	SILAN_PADMUX_EMMC_WR_PRT	= 18 * 32 + 23,
	SILAN_PADMUX_SD_POWER		= 18 * 32 + 24,
	SILAN_PADMUX_I2C3			= 18 * 32 + 25,
	SILAN_PADMUX_I2C4			= 18 * 32 + 26,
	SILAN_PADMUX_I2S_HDMI		= 18 * 32 + 27,
	SILAN_PADMUX_USB_HOST		= 18 * 32 + 28,
    SILAN_PADMUX_UART4			= 18 * 32 + 29,
    SILAN_PADMUX_UART5			= 18 * 32 + 30,
	SILAN_PADMUX_TS_ERROR		= 18 * 32 + 31,

	/* This should always be the last */
	SILAN_PADMUX_END
};

typedef enum {
	PAD_OFF,
	PAD_ON,
} PAD_ON_OFF;

struct silan_pin_info 
{
	/* show gpio name */
	unsigned char gpio_name[GPIO_NAME_LENTH];
	/* it count how many pad want to use this pin */
	unsigned char count;
	/* low number stand for high priority, this byte store the highest priority */
	unsigned char current_priority;
	/* store the pads which using this pin */
	unsigned char *used_by_pad[USED_BY_PADS_SIZE];
};

struct silan_module_pad
{
	/* the pad id in enum  */
	enum silan_pad_ids	pad_id[PAD_ID_NUM];
	/* the priority of pad in pins funciton */
	u8 priority;
	/* the pin controled by this pad */
	unsigned char *pin;
};

enum silan_gpio_ids {
	SILAN_GPIO_START,
	/* GPIO1 */
	SILAN_GPIO1_00	= 0 * 32 + 0,
	SILAN_GPIO1_01	= 0 * 32 + 1,
	SILAN_GPIO1_02	= 0 * 32 + 2,
	SILAN_GPIO1_03	= 0 * 32 + 3,
	SILAN_GPIO1_04	= 0 * 32 + 4,
	SILAN_GPIO1_05	= 0 * 32 + 5,
	SILAN_GPIO1_06	= 0 * 32 + 6,
	SILAN_GPIO1_07	= 0 * 32 + 7,
	SILAN_GPIO1_08	= 0 * 32 + 8,
	SILAN_GPIO1_09	= 0 * 32 + 9,
	SILAN_GPIO1_10	= 0 * 32 + 10,
	SILAN_GPIO1_11	= 0 * 32 + 11,
	SILAN_GPIO1_12	= 0 * 32 + 12,
	SILAN_GPIO1_13	= 0 * 32 + 13,
	SILAN_GPIO1_14	= 0 * 32 + 14,
	SILAN_GPIO1_15	= 0 * 32 + 15,
	SILAN_GPIO1_16	= 0 * 32 + 16,
	SILAN_GPIO1_17	= 0 * 32 + 17,
	SILAN_GPIO1_18	= 0 * 32 + 18,
	SILAN_GPIO1_19	= 0 * 32 + 19,
	SILAN_GPIO1_20	= 0 * 32 + 20,
	SILAN_GPIO1_21	= 0 * 32 + 21,
	SILAN_GPIO1_22	= 0 * 32 + 22,
	SILAN_GPIO1_23	= 0 * 32 + 23,
	SILAN_GPIO1_24	= 0 * 32 + 24,
	SILAN_GPIO1_25	= 0 * 32 + 25,
	SILAN_GPIO1_26	= 0 * 32 + 26,
	SILAN_GPIO1_27	= 0 * 32 + 27,
	SILAN_GPIO1_28	= 0 * 32 + 28,
	SILAN_GPIO1_29	= 0 * 32 + 29,
	SILAN_GPIO1_30	= 0 * 32 + 30,
	SILAN_GPIO1_31	= 0 * 32 + 31,
	/* GPIO2 */
	SILAN_GPIO2_00	= 1 * 32 + 0,
	SILAN_GPIO2_01	= 1 * 32 + 1,
	SILAN_GPIO2_02	= 1 * 32 + 2,
	SILAN_GPIO2_03	= 1 * 32 + 3,
	SILAN_GPIO2_04	= 1 * 32 + 4,
	SILAN_GPIO2_05	= 1 * 32 + 5,
	SILAN_GPIO2_06	= 1 * 32 + 6,
	SILAN_GPIO2_07	= 1 * 32 + 7,
	SILAN_GPIO2_08	= 1 * 32 + 8,
	SILAN_GPIO2_09	= 1 * 32 + 9,
	SILAN_GPIO2_10	= 1 * 32 + 10,
	SILAN_GPIO2_11	= 1 * 32 + 11,
	SILAN_GPIO2_12	= 1 * 32 + 12,
	SILAN_GPIO2_13	= 1 * 32 + 13,
	SILAN_GPIO2_14	= 1 * 32 + 14,
	SILAN_GPIO2_15	= 1 * 32 + 15,
	SILAN_GPIO2_16	= 1 * 32 + 16,
	SILAN_GPIO2_17	= 1 * 32 + 17,
	SILAN_GPIO2_18	= 1 * 32 + 18,
	SILAN_GPIO2_19	= 1 * 32 + 19,
	SILAN_GPIO2_20	= 1 * 32 + 20,
	SILAN_GPIO2_21	= 1 * 32 + 21,
	SILAN_GPIO2_22	= 1 * 32 + 22,
	SILAN_GPIO2_23	= 1 * 32 + 23,
	SILAN_GPIO2_24	= 1 * 32 + 24,
	SILAN_GPIO2_25	= 1 * 32 + 25,
	SILAN_GPIO2_26	= 1 * 32 + 26,
	SILAN_GPIO2_27	= 1 * 32 + 27,
	SILAN_GPIO2_28	= 1 * 32 + 28,
	SILAN_GPIO2_29	= 1 * 32 + 29,
	SILAN_GPIO2_30	= 1 * 32 + 30,
	SILAN_GPIO2_31	= 1 * 32 + 31,
	/* GPIO3 */
	SILAN_GPIO3_00	= 2 * 32 + 0,
	SILAN_GPIO3_01	= 2 * 32 + 1,
	SILAN_GPIO3_02	= 2 * 32 + 2,
	SILAN_GPIO3_03	= 2 * 32 + 3,
	SILAN_GPIO3_04	= 2 * 32 + 4,
	SILAN_GPIO3_05	= 2 * 32 + 5,
	SILAN_GPIO3_06	= 2 * 32 + 6,
	SILAN_GPIO3_07	= 2 * 32 + 7,
	SILAN_GPIO3_08	= 2 * 32 + 8,
	SILAN_GPIO3_09	= 2 * 32 + 9,
	SILAN_GPIO3_10	= 2 * 32 + 10,
	SILAN_GPIO3_11	= 2 * 32 + 11,
	SILAN_GPIO3_12	= 2 * 32 + 12,
	SILAN_GPIO3_13	= 2 * 32 + 13,
	SILAN_GPIO3_14	= 2 * 32 + 14,
	SILAN_GPIO3_15	= 2 * 32 + 15,
	SILAN_GPIO3_16	= 2 * 32 + 16,
	SILAN_GPIO3_17	= 2 * 32 + 17,
	SILAN_GPIO3_18	= 2 * 32 + 18,
	SILAN_GPIO3_19	= 2 * 32 + 19,
	SILAN_GPIO3_20	= 2 * 32 + 20,
	SILAN_GPIO3_21	= 2 * 32 + 21,
	SILAN_GPIO3_22	= 2 * 32 + 22,
	SILAN_GPIO3_23	= 2 * 32 + 23,
	SILAN_GPIO3_24	= 2 * 32 + 24,
	SILAN_GPIO3_25	= 2 * 32 + 25,
	SILAN_GPIO3_26	= 2 * 32 + 26,
	SILAN_GPIO3_27	= 2 * 32 + 27,
	SILAN_GPIO3_28	= 2 * 32 + 28,
	SILAN_GPIO3_29	= 2 * 32 + 29,
	SILAN_GPIO3_30	= 2 * 32 + 30,
	SILAN_GPIO3_31	= 2 * 32 + 31,
	/* GPIO4 */
	SILAN_GPIO4_00	= 3 * 32 + 0,
	SILAN_GPIO4_01	= 3 * 32 + 1,
	SILAN_GPIO4_02	= 3 * 32 + 2,
	SILAN_GPIO4_03	= 3 * 32 + 3,
	SILAN_GPIO4_04	= 3 * 32 + 4,
	SILAN_GPIO4_05	= 3 * 32 + 5,
	SILAN_GPIO4_06	= 3 * 32 + 6,
	SILAN_GPIO4_07	= 3 * 32 + 7,
	SILAN_GPIO4_08	= 3 * 32 + 8,
	SILAN_GPIO4_09	= 3 * 32 + 9,
	SILAN_GPIO4_10	= 3 * 32 + 10,
	SILAN_GPIO4_11	= 3 * 32 + 11,
	SILAN_GPIO4_12	= 3 * 32 + 12,
	SILAN_GPIO4_13	= 3 * 32 + 13,
	SILAN_GPIO4_14	= 3 * 32 + 14,
	SILAN_GPIO4_15	= 3 * 32 + 15,
	SILAN_GPIO4_16	= 3 * 32 + 16,
	SILAN_GPIO4_17	= 3 * 32 + 17,
	SILAN_GPIO4_18	= 3 * 32 + 18,
	SILAN_GPIO4_19	= 3 * 32 + 19,
	SILAN_GPIO4_20	= 3 * 32 + 20,
	SILAN_GPIO4_21	= 3 * 32 + 21,
	SILAN_GPIO4_22	= 3 * 32 + 22,
	SILAN_GPIO4_23	= 3 * 32 + 23,
	SILAN_GPIO4_24	= 3 * 32 + 24,
	SILAN_GPIO4_25	= 3 * 32 + 25,
	SILAN_GPIO4_26	= 3 * 32 + 26,
	SILAN_GPIO4_27	= 3 * 32 + 27,
	SILAN_GPIO4_28	= 3 * 32 + 28,
	SILAN_GPIO4_29	= 3 * 32 + 29,
	SILAN_GPIO4_30	= 3 * 32 + 30,
	SILAN_GPIO4_31	= 3 * 32 + 31,
	/* GPIO5 */
	SILAN_GPIO5_00	= 4 * 32 + 0,
	SILAN_GPIO5_01	= 4 * 32 + 1,
	SILAN_GPIO5_02	= 4 * 32 + 2,
	SILAN_GPIO5_03	= 4 * 32 + 3,
	SILAN_GPIO5_04	= 4 * 32 + 4,
	SILAN_GPIO5_05	= 4 * 32 + 5,
	SILAN_GPIO5_06	= 4 * 32 + 6,
	SILAN_GPIO5_07	= 4 * 32 + 7,
	SILAN_GPIO5_08	= 4 * 32 + 8,
	SILAN_GPIO5_09	= 4 * 32 + 9,
	SILAN_GPIO5_10	= 4 * 32 + 10,
	SILAN_GPIO5_11	= 4 * 32 + 11,
	SILAN_GPIO5_12	= 4 * 32 + 12,
	SILAN_GPIO5_13	= 4 * 32 + 13,
	SILAN_GPIO5_14	= 4 * 32 + 14,
	SILAN_GPIO5_15	= 4 * 32 + 15,
	SILAN_GPIO5_16	= 4 * 32 + 16,
	SILAN_GPIO5_17	= 4 * 32 + 17,
	SILAN_GPIO5_18	= 4 * 32 + 18,
	SILAN_GPIO5_19	= 4 * 32 + 19,
	SILAN_GPIO5_20	= 4 * 32 + 20,
	SILAN_GPIO5_21	= 4 * 32 + 21,
	SILAN_GPIO5_22	= 4 * 32 + 22,
	SILAN_GPIO5_23	= 4 * 32 + 23,
	SILAN_GPIO5_24	= 4 * 32 + 24,
	SILAN_GPIO5_25	= 4 * 32 + 25,
	SILAN_GPIO5_26	= 4 * 32 + 26,
	SILAN_GPIO5_27	= 4 * 32 + 27,
	SILAN_GPIO5_28	= 4 * 32 + 28,
	SILAN_GPIO5_29	= 4 * 32 + 29,
	SILAN_GPIO5_30	= 4 * 32 + 30,
	SILAN_GPIO5_31	= 4 * 32 + 31,
	/* GPIO6 */
	SILAN_GPIO6_00	= 5 * 32 + 0,
	SILAN_GPIO6_01	= 5 * 32 + 1,
	SILAN_GPIO6_02	= 5 * 32 + 2,
	SILAN_GPIO6_03	= 5 * 32 + 3,
	SILAN_GPIO6_04	= 5 * 32 + 4,
	SILAN_GPIO6_05	= 5 * 32 + 5,
	SILAN_GPIO6_06	= 5 * 32 + 6,
	SILAN_GPIO6_07	= 5 * 32 + 7,
	SILAN_GPIO6_08	= 5 * 32 + 8,
	SILAN_GPIO6_09	= 5 * 32 + 9,
	SILAN_GPIO6_10	= 5 * 32 + 10,
	SILAN_GPIO6_11	= 5 * 32 + 11,
	SILAN_GPIO6_12	= 5 * 32 + 12,
	SILAN_GPIO6_13	= 5 * 32 + 13,
	SILAN_GPIO6_14	= 5 * 32 + 14,
	SILAN_GPIO6_15	= 5 * 32 + 15,
	SILAN_GPIO6_16	= 5 * 32 + 16,
	SILAN_GPIO6_17	= 5 * 32 + 17,
	SILAN_GPIO6_18	= 5 * 32 + 18,
	SILAN_GPIO6_19	= 5 * 32 + 19,
	SILAN_GPIO6_20	= 5 * 32 + 20,
	SILAN_GPIO6_21	= 5 * 32 + 21,
	SILAN_GPIO6_22	= 5 * 32 + 22,
	SILAN_GPIO6_23	= 5 * 32 + 23,
	SILAN_GPIO6_24	= 5 * 32 + 24,
	SILAN_GPIO6_25	= 5 * 32 + 25,
	SILAN_GPIO6_26	= 5 * 32 + 26,
	SILAN_GPIO6_27	= 5 * 32 + 27,
	SILAN_GPIO6_28	= 5 * 32 + 28,
	SILAN_GPIO6_29	= 5 * 32 + 29,
	SILAN_GPIO6_30	= 5 * 32 + 30,
	SILAN_GPIO6_31	= 5 * 32 + 31,
	/* This should always be the last */
	SILAN_GPIO_END
};

#define GPIO_PIN(n)     ((unsigned int)(1 << (n)))  /* Pin(n) selected, n >=0 && n < 32 */

#endif
