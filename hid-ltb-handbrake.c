// SPDX-License-Identifier: GPL-2.0-or-later
/*
 *  HID driver for ltbhb handbrake
 *
 *  Copyright (c) 2025 Oleg Makarenko
 */

#include <linux/device.h>
#include <linux/input.h>
#include <linux/hid.h>
#include <linux/module.h>
#include <linux/usb.h>

#define USB_VENDOR_ID_ltbhb               0x2023
#define USB_PRODUCT_ID_ltbhb_HANDBRAKE    0x0803


static int ltbhb_input_mapping(struct hid_device *hdev, struct hid_input *hi,
		struct hid_field *field, struct hid_usage *usage,
		unsigned long **bit, int *max)
{
    if ((usage->hid & HID_USAGE_PAGE) == HID_UP_BUTTON) {
        return -1;
    }
    return 0;
}


static const struct hid_device_id ltbhb_devices[] = {
	{ HID_USB_DEVICE(USB_VENDOR_ID_ltbhb, USB_PRODUCT_ID_ltbhb_HANDBRAKE) },
	{ }
};

MODULE_DEVICE_TABLE(hid, ltbhb_devices);

static struct hid_driver ltbhb_driver = {
	.name = "hid-ltbhb",
	.id_table = ltbhb_devices,
    .input_mapping = ltbhb_input_mapping,
};
module_hid_driver(ltbhb_driver);

MODULE_DESCRIPTION("HID driver for LTB handbrake");
MODULE_LICENSE("GPL");
