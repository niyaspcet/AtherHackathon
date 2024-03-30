#include "asdk_system.h"

#include "asdk_app.h"

int main()
{
    asdk_sys_enable_interrupts();
    
    app_init();
    app_loop();
}
