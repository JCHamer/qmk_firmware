#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#define EE_HANDS

#define TAPPING_TERM			300
#define TAPPING_TERM_PER_KEY

#define QUICK_TAP_TERM			100

// https://github.com/qmk/qmk_firmware/issues/19420#issuecomment-1372134274
#define usb_lld_disconnect_bus(usbp) do {} while(0) 

//#define PERMISSIVE_HOLD

#define FORCE_NKRO

#endif
