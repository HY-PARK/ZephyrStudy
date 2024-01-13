#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#include <zephyr/drivers/gpio.h>


/* 1000 msec = 1 sec */
#define SLEEP_TIME_MS   1000


#define LD1_NODE DT_NODELABEL(green_led_0)
#define LD2_NODE DT_NODELABEL(orange_led_0)
#define LD3_NODE DT_NODELABEL(red_led_0)

#define LD4_NODE DT_ALIAS(led0)

static const struct gpio_dt_spec ld1 = GPIO_DT_SPEC_GET(LD1_NODE, gpios);
static const struct gpio_dt_spec ld2 = GPIO_DT_SPEC_GET(LD2_NODE, gpios);
static const struct gpio_dt_spec ld3 = GPIO_DT_SPEC_GET(LD3_NODE, gpios);
static const struct gpio_dt_spec ld4 = GPIO_DT_SPEC_GET(LD4_NODE, gpios);

int main(void)
{
	gpio_pin_configure_dt(&ld1, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&ld2, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&ld3, GPIO_OUTPUT_ACTIVE);
	gpio_pin_configure_dt(&ld4, GPIO_OUTPUT_ACTIVE);


	while (1) {
		gpio_pin_toggle_dt(&ld1);
		gpio_pin_toggle_dt(&ld2);
		gpio_pin_toggle_dt(&ld3);
		gpio_pin_toggle_dt(&ld4);
		k_msleep(SLEEP_TIME_MS);
	}
	return 0;
}