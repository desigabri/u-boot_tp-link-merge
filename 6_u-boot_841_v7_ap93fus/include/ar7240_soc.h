#ifndef _AR7240_SOC_H
#define _AR7240_SOC_H

#include <config.h>

#ifdef CONFIG_AR7240_EMU
#define AR7240_EMU 1
#endif

/*
 * Address map
 */
#define AR7240_PCI_MEM_BASE             0x10000000  /* 128M */
#define AR7240_APB_BASE                 0x18000000  /* 384M */
#define AR7240_GE0_BASE                 0x19000000  /* 16M */
#define AR7240_GE1_BASE                 0x1a000000  /* 16M */
#define AR7240_USB_EHCI_BASE            0x1b000000
#define AR7240_USB_OHCI_BASE            0x1c000000
#define AR7240_SPI_BASE                 0x1f000000

/*
 * APB block
 */
#define AR7240_DDR_CTL_BASE             AR7240_APB_BASE+0x00000000
#define AR7240_CPU_BASE                 AR7240_APB_BASE+0x00010000
#define AR7240_UART_BASE                AR7240_APB_BASE+0x00020000
#define AR7240_USB_CONFIG_BASE          AR7240_APB_BASE+0x00030000
#define AR7240_GPIO_BASE                AR7240_APB_BASE+0x00040000
#define AR7240_PLL_BASE                 AR7240_APB_BASE+0x00050000
#define AR7240_RESET_BASE               AR7240_APB_BASE+0x00060000
#define AR7240_PCI_LCL_BASE             AR7240_APB_BASE+0x000f0000

/*
 * DDR block
 */

#define AR7240_DDR_CONFIG               AR7240_DDR_CTL_BASE+0
#define AR7240_DDR_CONFIG2              AR7240_DDR_CTL_BASE+4
#define AR7240_DDR_MODE                 AR7240_DDR_CTL_BASE+0x08
#define AR7240_DDR_EXT_MODE             AR7240_DDR_CTL_BASE+0x0c
#define AR7240_DDR_CONTROL              AR7240_DDR_CTL_BASE+0x10
#define AR7240_DDR_REFRESH              AR7240_DDR_CTL_BASE+0x14
#define AR7240_DDR_RD_DATA_THIS_CYCLE   AR7240_DDR_CTL_BASE+0x18
#define AR7240_DDR_TAP_CONTROL0         AR7240_DDR_CTL_BASE+0x1c
#define AR7240_DDR_TAP_CONTROL1         AR7240_DDR_CTL_BASE+0x20
#define AR7240_DDR_TAP_CONTROL2         AR7240_DDR_CTL_BASE+0x24
#define AR7240_DDR_TAP_CONTROL3         AR7240_DDR_CTL_BASE+0x28

#define AR7240_DDR_CONFIG_16BIT             (1 << 31)
#define AR7240_DDR_CONFIG_PAGE_OPEN         (1 << 30)
#define AR7240_DDR_CONFIG_CAS_LAT_SHIFT      27
#define AR7240_DDR_CONFIG_TMRD_SHIFT         23
#define AR7240_DDR_CONFIG_TRFC_SHIFT         17
#define AR7240_DDR_CONFIG_TRRD_SHIFT         13
#define AR7240_DDR_CONFIG_TRP_SHIFT          9
#define AR7240_DDR_CONFIG_TRCD_SHIFT         5
#define AR7240_DDR_CONFIG_TRAS_SHIFT         0

#define AR7240_DDR_CONFIG2_BL2          (2 << 0)
#define AR7240_DDR_CONFIG2_BL4          (4 << 0)
#define AR7240_DDR_CONFIG2_BL8          (8 << 0)

#define AR7240_DDR_CONFIG2_BT_IL        (1 << 4)
#define AR7240_DDR_CONFIG2_CNTL_OE_EN   (1 << 5)
#define AR7240_DDR_CONFIG2_PHASE_SEL    (1 << 6)
#define AR7240_DDR_CONFIG2_DRAM_CKE     (1 << 7)
#define AR7240_DDR_CONFIG2_TWR_SHIFT    8
#define AR7240_DDR_CONFIG2_TRTW_SHIFT   12
#define AR7240_DDR_CONFIG2_TRTP_SHIFT   17
#define AR7240_DDR_CONFIG2_TWTR_SHIFT   21
#define AR7240_DDR_CONFIG2_HALF_WIDTH_L (1 << 31)

#define AR7240_DDR_TAP_DEFAULT          0x18

/*
 * PLL
 */
#define AR7240_CPU_PLL_CONFIG           AR7240_PLL_BASE
#define AR7240_USB_PLL_CONFIG           AR7240_PLL_BASE+0x4
#define AR7240_PCIE_PLL_CONFIG          AR7240_PLL_BASE+0x10
#define AR7240_CPU_CLOCK_CONTROL        AR7240_PLL_BASE+8

#define AR7240_USB_PLL_GE0_OFFSET       AR7240_PLL_BASE+0x10
#define AR7240_USB_PLL_GE1_OFFSET       AR7240_PLL_BASE+0x14

#define PLL_CONFIG_PLL_DIV_SHIFT        0
#define PLL_CONFIG_PLL_DIV_MASK         (0x3ff<< PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_SHIFT    10
#define PLL_CONFIG_PLL_REF_DIV_MASK     (0xf << PLL_CONFIG_PLL_REF_DIV_SHIFT)
#define PLL_CONFIG_PLL_BYPASS_SHIFT     16
#define PLL_CONFIG_PLL_BYPASS_MASK      (0x1 << PLL_CONFIG_PLL_BYPASS_SHIFT)
#define PLL_CONFIG_PLL_UPDATE_SHIFT     17
#define PLL_CONFIG_PLL_UPDATE_MASK      (0x1 << PLL_CONFIG_PLL_UPDATE_SHIFT)
#define PLL_CONFIG_PLL_NOPWD_SHIFT      18
#define PLL_CONFIG_PLL_NOPWD_MASK       (0x1 << PLL_CONFIG_PLL_NOPWD_SHIFT)
#define PLL_CONFIG_AHB_DIV_SHIFT        19
#define PLL_CONFIG_AHB_DIV_MASK         (0x1 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_DDR_DIV_SHIFT        22
#define PLL_CONFIG_DDR_DIV_MASK         (0x1 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_PLL_RESET_SHIFT      25
#define PLL_CONFIG_PLL_RESET_MASK       (0x1 << PLL_CONFIG_PLL_RESET_SHIFT)

#define CLOCK_CONTROL_CLOCK_SWITCH_SHIFT  0
#define CLOCK_CONTROL_CLOCK_SWITCH_MASK  (1 << CLOCK_CONTROL_CLOCK_SWITCH_SHIFT)
#define CLOCK_CONTROL_RST_SWITCH_SHIFT    1
#define CLOCK_CONTROL_RST_SWITCH_MASK    (1 << CLOCK_CONTROL_RST_SWITCH_SHIFT)

/*
** PLL config for different CPU/DDR/AHB frequencies
*/
#define PLL_CONFIG_PLL_NOPWD_VAL        (1 << PLL_CONFIG_PLL_NOPWD_SHIFT)

#if (CFG_PLL_FREQ == CFG_PLL_400_400_200)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x28 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_400_400_100)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x1 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x28 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_360_360_180)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x24 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_350_350_175)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x23 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)


#elif (CFG_PLL_FREQ == CFG_PLL_340_340_170)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x22 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_320_320_160)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x20 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_320_320_80)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x1 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x20 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_300_300_150)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x1e << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_300_300_75)

#define PLL_CONFIG_DDR_DIV_VAL     (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL     (0x1 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL     (0x1e << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#elif (CFG_PLL_FREQ == CFG_PLL_200_200_100)

#define PLL_CONFIG_DDR_DIV_VAL   (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL   (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL    (0x14 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#else /* default is 400/400/200 */

#define PLL_CONFIG_DDR_DIV_VAL   (0x0 << PLL_CONFIG_DDR_DIV_SHIFT)
#define PLL_CONFIG_AHB_DIV_VAL   (0x0 << PLL_CONFIG_AHB_DIV_SHIFT)
#define PLL_CONFIG_PLL_DIV_VAL    (0x28 << PLL_CONFIG_PLL_DIV_SHIFT)
#define PLL_CONFIG_PLL_REF_DIV_VAL (0x2 << PLL_CONFIG_PLL_REF_DIV_SHIFT)

#endif

/*
 * PLL block
 */
#define AR7240_PLL_CONFIG               AR7240_PLL_BASE+0x0

/*
 * CLOCK
 */
#define AR7240_CPU_CLOCK_CONTROL        AR7240_PLL_BASE+8

/*
 * FIFO flushes
 */
#define AR7240_DDR_GE0_FLUSH            AR7240_DDR_CTL_BASE+0x9c
#define AR7240_DDR_GE1_FLUSH            AR7240_DDR_CTL_BASE+0xa0
#define AR7240_DDR_PCI_FLUSH            AR7240_DDR_CTL_BASE+0xa8

/*
 * USB block
 */
#define AR7240_USB_FLADJ_VAL            AR7240_USB_CONFIG_BASE
#define AR7240_USB_CONFIG               AR7240_USB_CONFIG_BASE+0x4
#define AR7240_USB_WINDOW               0x1000000

/*
 * PCI block
 */
#define AR7240_PCI_WINDOW           0x8000000       /* 128MB */
#define AR7240_PCI_WINDOW0_OFFSET   AR7240_DDR_CTL_BASE+0x7c
#define AR7240_PCI_WINDOW1_OFFSET   AR7240_DDR_CTL_BASE+0x80
#define AR7240_PCI_WINDOW2_OFFSET   AR7240_DDR_CTL_BASE+0x84
#define AR7240_PCI_WINDOW3_OFFSET   AR7240_DDR_CTL_BASE+0x88
#define AR7240_PCI_WINDOW4_OFFSET   AR7240_DDR_CTL_BASE+0x8c
#define AR7240_PCI_WINDOW5_OFFSET   AR7240_DDR_CTL_BASE+0x90
#define AR7240_PCI_WINDOW6_OFFSET   AR7240_DDR_CTL_BASE+0x94
#define AR7240_PCI_WINDOW7_OFFSET   AR7240_DDR_CTL_BASE+0x98

#define AR7240_PCI_WINDOW0_VAL      0x10000000
#define AR7240_PCI_WINDOW1_VAL      0x11000000
#define AR7240_PCI_WINDOW2_VAL      0x12000000
#define AR7240_PCI_WINDOW3_VAL      0x13000000
#define AR7240_PCI_WINDOW4_VAL      0x14000000
#define AR7240_PCI_WINDOW5_VAL      0x15000000
#define AR7240_PCI_WINDOW6_VAL      0x16000000
#define AR7240_PCI_WINDOW7_VAL      0x07000000


/*
 * CRP. To access the host controller config and status registers
 */
#define AR7240_PCI_CRP   	   0x180c0000
#define AR7240_PCI_DEV_CFGBASE     0x14000000

#define AR7240_PCI_CRP_AD_CBE               AR7240_PCI_CRP
#define AR7240_PCI_CRP_WRDATA               AR7240_PCI_CRP+0x4
#define AR7240_PCI_CRP_RDDATA               AR7240_PCI_CRP+0x8
#define AR7240_PCI_ERROR            AR7240_PCI_CRP+0x1c
#define AR7240_PCI_ERROR_ADDRESS    AR7240_PCI_CRP+0x20
#define AR7240_PCI_AHB_ERROR            AR7240_PCI_CRP+0x24
#define AR7240_PCI_AHB_ERROR_ADDRESS    AR7240_PCI_CRP+0x28

#define AR7240_CRP_CMD_WRITE             0x00010000
#define AR7240_CRP_CMD_READ              0x00000000

/*
 * PCI CFG. To generate config cycles
 */
#define AR7240_PCI_CFG_AD           AR7240_PCI_CRP+0xc
#define AR7240_PCI_CFG_CBE          AR7240_PCI_CRP+0x10
#define AR7240_PCI_CFG_WRDATA       AR7240_PCI_CRP+0x14
#define AR7240_PCI_CFG_RDDATA       AR7240_PCI_CRP+0x18
#define AR7240_CFG_CMD_READ         0x0000000a
#define AR7240_CFG_CMD_WRITE        0x0000000b

#define AR7240_PCI_IDSEL_ADLINE_START           17

#define AR7240_PCI_LCL_RESET        AR7240_PCI_LCL_BASE+0x18

/*
 * gpio configs
 */
#define AR7240_GPIO_OE                  AR7240_GPIO_BASE+0x0
#define AR7240_GPIO_IN                  AR7240_GPIO_BASE+0x4
#define AR7240_GPIO_OUT                 AR7240_GPIO_BASE+0x8
#define AR7240_GPIO_SET                 AR7240_GPIO_BASE+0xc
#define AR7240_GPIO_CLEAR               AR7240_GPIO_BASE+0x10
#define AR7240_GPIO_INT_ENABLE          AR7240_GPIO_BASE+0x14
#define AR7240_GPIO_INT_TYPE            AR7240_GPIO_BASE+0x18
#define AR7240_GPIO_INT_POLARITY        AR7240_GPIO_BASE+0x1c
#define AR7240_GPIO_INT_PENDING         AR7240_GPIO_BASE+0x20
#define AR7240_GPIO_INT_MASK            AR7240_GPIO_BASE+0x24
#define AR7240_GPIO_FUNC                AR7240_GPIO_BASE+0x28

/*
 * IRQ Map.
 * There are 4 conceptual ICs in the system. We generally give a block of 16
 * irqs to each IC.
 * CPU:                     0    - 0xf
 *      MISC:               0x10 - 0x1f
 *          GPIO:           0x20 - 0x2f
 *      PCI :               0x30 - 0x40
 *
 */
#define AR7240_CPU_IRQ_BASE         0x00
#define AR7240_MISC_IRQ_BASE        0x10
#define AR7240_GPIO_IRQ_BASE        0x20
#define AR7240_PCI_IRQ_BASE         0x30

/*
 * The IPs. Connected to CPU (hardware IP's; the first two are software)
 */
#define AR7240_CPU_IRQ_PCI                  AR7240_CPU_IRQ_BASE+2
#define AR7240_CPU_IRQ_USB                  AR7240_CPU_IRQ_BASE+3
#define AR7240_CPU_IRQ_GE0                  AR7240_CPU_IRQ_BASE+4
#define AR7240_CPU_IRQ_GE1                  AR7240_CPU_IRQ_BASE+5
#define AR7240_CPU_IRQ_MISC                 AR7240_CPU_IRQ_BASE+6
#define AR7240_CPU_IRQ_TIMER                AR7240_CPU_IRQ_BASE+7

/*
 * Interrupts connected to the CPU->Misc line.
 */
#define AR7240_MISC_IRQ_TIMER               AR7240_MISC_IRQ_BASE+0
#define AR7240_MISC_IRQ_ERROR               AR7240_MISC_IRQ_BASE+1
#define AR7240_MISC_IRQ_GPIO                AR7240_MISC_IRQ_BASE+2
#define AR7240_MISC_IRQ_UART                AR7240_MISC_IRQ_BASE+3
#define AR7240_MISC_IRQ_WATCHDOG            AR7240_MISC_IRQ_BASE+4
#define AR7240_MISC_IRQ_COUNT                 5

#define MIMR_TIMER                          0x01
#define MIMR_ERROR                          0x02
#define MIMR_GPIO                           0x04
#define MIMR_UART                           0x08
#define MIMR_WATCHDOG                       0x10

#define MISR_TIMER                          MIMR_TIMER
#define MISR_ERROR                          MIMR_ERROR
#define MISR_GPIO                           MIMR_GPIO
#define MISR_UART                           MIMR_UART
#define MISR_WATCHDOG                       MIMR_WATCHDOG

/*
 * Interrupts connected to the Misc->GPIO line
 */
#define AR7240_GPIO_IRQn(_gpio)             AR7240_GPIO_IRQ_BASE+(_gpio)
#define AR7240_GPIO_IRQ_COUNT                 16

/*
 * Interrupts connected to CPU->PCI
 */
#define AR7240_PCI_IRQ_DEV0                  AR7240_PCI_IRQ_BASE+0
#define AR7240_PCI_IRQ_DEV1                  AR7240_PCI_IRQ_BASE+1
#define AR7240_PCI_IRQ_DEV2                  AR7240_PCI_IRQ_BASE+2
#define AR7240_PCI_IRQ_CORE                  AR7240_PCI_IRQ_BASE+3
#define AR7240_PCI_IRQ_COUNT                 4

/*
 * PCI interrupt mask and status
 */
#define PIMR_DEV0                           0x01
#define PIMR_DEV1                           0x02
#define PIMR_DEV2                           0x04
#define PIMR_CORE                           0x10

#define PISR_DEV0                           PIMR_DEV0
#define PISR_DEV1                           PIMR_DEV1
#define PISR_DEV2                           PIMR_DEV2
#define PISR_CORE                           PIMR_CORE

#define AR7240_GPIO_COUNT                   16

/*
 * Reset block
 */
#define AR7240_GENERAL_TMR            AR7240_RESET_BASE+0
#define AR7240_GENERAL_TMR_RELOAD     AR7240_RESET_BASE+4
#define AR7240_WATCHDOG_TMR_CONTROL   AR7240_RESET_BASE+8
#define AR7240_WATCHDOG_TMR           AR7240_RESET_BASE+0xc
#define AR7240_MISC_INT_STATUS        AR7240_RESET_BASE+0x10
#define AR7240_MISC_INT_MASK          AR7240_RESET_BASE+0x14
#define AR7240_GLOBAL_INT_STATUS      AR7240_RESET_BASE+0x18
#define AR7240_RESET                  AR7240_RESET_BASE+0x1c
#define AR7240_REV_ID                 (AR7240_RESET_BASE + 0x90)
#define AR7240_REV_ID_MASK            0xff
#define AR7240_REV_1_0                0xc0
#define AR7240_REV_1_1                0xc1

/*
 * AR7240_RESET bit defines
 */
#define AR7240_RESET_EXTERNAL               (1 << 28)
#define AR7240_RESET_FULL_CHIP              (1 << 24)
#define AR7240_RESET_CPU_NMI                (1 << 21)
#define AR7240_RESET_CPU_COLD_RESET_MASK    (1 << 20)
#define AR7240_RESET_DDR                    (1 << 16)
#define AR7240_RESET_GE1_MAC                (1 << 13)
#define AR7240_RESET_GE1_PHY                (1 << 12) /* Not valid */
#define AR7240_RESET_PCIE_PHY_SERIAL        (1 << 10)
#define AR7240_RESET_GE0_MAC                (1 << 9)
#define AR7240_RESET_GE0_PHY                (1 << 8) /* Switch reset */
#define AR7240_RESET_PCIE_PHY               (1 << 7)
#define AR7240_RESET_PCIE                   (1 << 6)
#define AR7240_RESET_USB_HOST               (1 << 5)
#define AR7240_RESET_USB_OHCI_DLL           (1 << 3)

#define AR7240_MII0_CTRL                    0x18070000
#define AR7240_MII1_CTRL                    0x18070004

#define K1BASE KSEG1

#ifndef __ASSEMBLY__
typedef enum {
    AR7240_DDR_16B_LOW,
    AR7240_DDR_16B_HIGH,
    AR7240_DDR_32B,
}ar7240_ddr_width_t;

#define ar7240_reg_rd(_phys)    (*(volatile unsigned int *)KSEG1ADDR(_phys))
#define ar7240_reg_wr_nf(_phys, _val) \
                    ((*(volatile unsigned int *)KSEG1ADDR(_phys)) = (_val))

#define ar7240_reg_wr(_phys, _val) do {     \
                    ar7240_reg_wr_nf(_phys, _val);  \
                    ar7240_reg_rd(_phys);       \
}while(0);

#define ar7240_write_pci_window(_no)             \
  ar7240_reg_wr(AR7240_PCI_WINDOW##_no##_OFFSET, AR7240_PCI_WINDOW##_no##_VAL);

#define BIT(_x) (1 << (_x))

#define ar7240_reg_rmw_set(_reg, _mask)  do {                        \
    ar7240_reg_wr((_reg), (ar7240_reg_rd((_reg)) | (_mask)));      \
    ar7240_reg_rd((_reg));                                           \
}while(0);

#define ar7240_reg_rmw_clear(_reg, _mask)  do {                        \
    ar7240_reg_wr((_reg), (ar7240_reg_rd((_reg)) & ~(_mask)));      \
    ar7240_reg_rd((_reg));                                           \
}while(0);

#define ar7240_get_bit(_reg, _bit)  (ar7240_reg_rd((_reg)) & (1 << (_bit)))

#define ar7240_flush_ge(_unit) do {                             \
    u32     reg = (_unit) ? AR7240_DDR_GE1_FLUSH : AR7240_DDR_GE0_FLUSH;   \
    ar7240_reg_wr(reg, 1);                 \
    while((ar7240_reg_rd(reg) & 0x1));   \
    ar7240_reg_wr(reg, 1);                 \
    while((ar7240_reg_rd(reg) & 0x1));   \
}while(0);

#define ar7240_flush_pci() do {                             \
    ar7240_reg_wr(AR7240_DDR_PCI_FLUSH, 1);                 \
    while((ar7240_reg_rd(AR7240_DDR_PCI_FLUSH) & 0x1));   \
    ar7240_reg_wr(AR7240_DDR_PCI_FLUSH, 1);                 \
    while((ar7240_reg_rd(AR7240_DDR_PCI_FLUSH) & 0x1));   \
}while(0);

#endif  /*__ASSEMBLY*/
#endif
