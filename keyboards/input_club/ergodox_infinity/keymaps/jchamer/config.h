#ifndef CONFIG_USER_H
#define CONFIG_USER_H

//#include "../../config.h"

//#undef  PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD

#define EE_HANDS

#define ONESHOT_TAP_TOGGLE       2

#undef  TAPPING_TERM
#define TAPPING_TERM             200

// https://github.com/qmk/qmk_firmware/issues/19420#issuecomment-1372134274
#define usb_lld_disconnect_bus(usbp) do {} while(0) 

#define PERMISSIVE_HOLD

#define FORCE_NKRO

#endif
