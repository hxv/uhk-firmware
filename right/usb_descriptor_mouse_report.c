#include <stdint.h>
#include "usb_report_item_macros.h"
#include "usb_descriptor_mouse_report.h"

uint8_t UsbMouseReportDescriptor[USB_MOUSE_REPORT_DESCRIPTOR_LENGTH] = {
    HID_RI_USAGE_PAGE(8, HID_RI_USAGE_PAGE_GENERIC_DESKTOP),
    HID_RI_USAGE(8, HID_RI_USAGE_MOUSE),
    HID_RI_COLLECTION(8, HID_RI_COLLECTION_APPLICATION),
        HID_RI_USAGE(8, HID_RI_USAGE_POINTER),
        HID_RI_COLLECTION(8, HID_RI_COLLECTION_PHYSICAL),

            // Mouse buttons
            HID_RI_USAGE_PAGE(8, HID_RI_USAGE_PAGE_MOUSE_BUTTONS),
            HID_RI_USAGE_MINIMUM(8, 0x01),
            HID_RI_USAGE_MAXIMUM(8, USB_MOUSE_REPORT_DESCRIPTOR_BUTTONS),
            HID_RI_LOGICAL_MINIMUM(8, 0x00),
            HID_RI_LOGICAL_MAXIMUM(8, 0x01),
            HID_RI_REPORT_COUNT(8, USB_MOUSE_REPORT_DESCRIPTOR_BUTTONS),
            HID_RI_REPORT_SIZE(8, 0x01),
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),

            // Mouse buttons padding
            HID_RI_REPORT_COUNT(8, 0x01),
            HID_RI_REPORT_SIZE(8, USB_MOUSE_REPORT_DESCRIPTOR_BUTTONS_PADDING),
            HID_RI_INPUT(8, HID_IOF_CONSTANT),

            // Mouse X and Y coordinates
            HID_RI_USAGE_PAGE(8, HID_RI_USAGE_PAGE_GENERIC_DESKTOP),
            HID_RI_USAGE(8, HID_RI_USAGE_X),
            HID_RI_USAGE(8, HID_RI_USAGE_Y),
            HID_RI_LOGICAL_MINIMUM(16, USB_MOUSE_REPORT_DESCRIPTOR_MIN_AXIS_VALUE),
            HID_RI_LOGICAL_MAXIMUM(16, USB_MOUSE_REPORT_DESCRIPTOR_MAX_AXIS_VALUE),
            HID_RI_PHYSICAL_MINIMUM(16, USB_MOUSE_REPORT_DESCRIPTOR_MIN_AXIS_PHYSICAL_VALUE),
            HID_RI_PHYSICAL_MAXIMUM(16, USB_MOUSE_REPORT_DESCRIPTOR_MAX_AXIS_PHYSICAL_VALUE),
            HID_RI_REPORT_COUNT(8, 0x02),
            HID_RI_REPORT_SIZE(8, (((USB_MOUSE_REPORT_DESCRIPTOR_MIN_AXIS_VALUE >= -128) && (USB_MOUSE_REPORT_DESCRIPTOR_MAX_AXIS_VALUE <= 127)) ? 8 : 16)),
            HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),

            HID_RI_COLLECTION(8, HID_RI_COLLECTION_LOGICAL),

                // Vertical wheel resolution multiplier
                HID_RI_USAGE(8, HID_RI_USAGE_RESOLUTION_MULTIPLIER),
                HID_RI_LOGICAL_MINIMUM(8, 0x00),
                HID_RI_LOGICAL_MAXIMUM(8, 0x01),
                HID_RI_PHYSICAL_MINIMUM(8, 0x01),
                HID_RI_PHYSICAL_MAXIMUM(8, 0x04),
                HID_RI_REPORT_SIZE(8, 0x02),
                HID_RI_REPORT_COUNT(8, 0x01),
                HID_RI_PUSH(0),
                HID_RI_FEATURE(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),

                // Vertical wheel
                HID_RI_USAGE(8, HID_RI_USAGE_WHEEL),
                HID_RI_LOGICAL_MINIMUM(8, -127),
                HID_RI_LOGICAL_MAXIMUM(8, 127),
                HID_RI_PHYSICAL_MINIMUM(8, 0x00),
                HID_RI_PHYSICAL_MAXIMUM(8, 0x00),
                HID_RI_REPORT_SIZE(8, 0x08),
                HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),

            HID_RI_END_COLLECTION(0),
            HID_RI_COLLECTION(8, HID_RI_COLLECTION_LOGICAL),

                // Horizontal wheel resolution multiplier
                HID_RI_USAGE(8, HID_RI_USAGE_RESOLUTION_MULTIPLIER),
                HID_RI_POP(0),
                HID_RI_FEATURE(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),

                // Padding
                HID_RI_PHYSICAL_MINIMUM(8, 0x00),
                HID_RI_PHYSICAL_MAXIMUM(8, 0x00),
                HID_RI_REPORT_SIZE(8, 0x04),
                HID_RI_FEATURE(8, HID_IOF_CONSTANT | HID_IOF_VARIABLE | HID_IOF_ABSOLUTE),

                // Horizontal wheel
                HID_RI_USAGE_PAGE(8, HID_RI_USAGE_PAGE_CONSUMER),
                HID_RI_USAGE(16, HID_RI_USAGE_AC_PAN),
                HID_RI_LOGICAL_MINIMUM(8, -127),
                HID_RI_LOGICAL_MAXIMUM(8, 127),
                HID_RI_REPORT_SIZE(8, 0x08),
                HID_RI_INPUT(8, HID_IOF_DATA | HID_IOF_VARIABLE | HID_IOF_RELATIVE),

                HID_RI_END_COLLECTION(0),
        HID_RI_END_COLLECTION(0),
    HID_RI_END_COLLECTION(0)
};
