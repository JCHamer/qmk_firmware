#ifndef CONFIG_USER_H
#define CONFIG_USER_H

#include "../../config.h"
//#include "jchamer.h"

//#include "./visualizer.h"

#undef  IGNORE_MOD_TAP_INTERRUPT
#define IGNORE_MOD_TAP_INTERRUPT

#undef  PERMISSIVE_HOLD
// #define PERMISSIVE_HOLD

#define ONESHOT_TAP_TOGGLE       2

#undef  TAPPING_TERM
#define TAPPING_TERM             200

#define FORCE_NKRO

#endif
