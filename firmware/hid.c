/* -*- c-file-style: "stroustrup"; indent-tabs-mode: nil; -*- */

#include <avr/pgmspace.h>
#include "usbdrv/usbdrv.h"

#include "hid_intern.h"


/* USB report descriptor, size must match usbconfig.h */
PROGMEM char usbHidReportDescriptor[40] = {
  G_USAGE_PAGE(1), 0x01,        /* Generic Desktop */
  L_USAGE(1), 0x04,             /* Joystick */
  M_COLLECTION(1), C_APPLICATION,
    L_USAGE(1), 0x01,           /* Pointer */
    M_COLLECTION(1), C_PHYSICAL,
      L_USAGE(1), 0x30,         /* X */
      L_USAGE(1), 0x31,         /* Y */
      G_LOGICAL_MINIMUM(1), 0x00,
      G_LOGICAL_MAXIMUM(1), 0x0F,
      G_REPORT_SIZE(1), 0x04,
      G_REPORT_COUNT(1), 0x02,
      M_INPUT(1), IOF_VARIABLE,
    M_END_COLLECTION(0),
    /* Feature Report: 128 bytes for generic use */
    L_USAGE(2), 0x00, 0x00,     /* Undefined */
    G_LOGICAL_MINIMUM(1), 0x00,
    G_LOGICAL_MAXIMUM(2), 0xFF, 0x00,
    G_REPORT_SIZE(1), 0x08,
    G_REPORT_COUNT(1), 0x80,
    M_FEATURE(1), IOF_VARIABLE,

  M_END_COLLECTION(0),
};
