#include <zephyr/drivers/gpio.h>
#include <zephyr/kernel.h>
#include <zephyr/pm/device.h>

#include <zephyr/logging/log.h>
LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

#include <app_version.h>


void main(void)
{
	LOG_INF("🚀 MAIN START (%s) 🚀", APP_VERSION_FULL);
}
