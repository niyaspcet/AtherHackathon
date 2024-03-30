#ifndef APP_H
#define APP_H

#include "default_config.h"
#include "eb_wrapper.h"
#include "Com_SymbolicNames_PBcfg.h"
#include "system.h"

#include <stdbool.h>
#include "asdk_platform.h"
#include "asdk_error.h"

void app_init(void);
void app_loop(void);

#endif
