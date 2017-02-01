#include <stdio.h>

#include "unimotion.h"

int main() {

    // ========================================================
    // Sample howTo Use unimotion library
    // ========================================================

    char *name;
    int x, y, z;
    x = y = z = 0;

    // -------------------------------------------------------
    // Detecting Computer

    fprintf(stderr, "Detecting SMS\n");
    int type = detect_sms();
    if (type == unknown) {
        fprintf(stderr, "Could not detect an SMS\n");
    }

    switch (type) {
        case powerbook:
            name = "powerbook";
            break;
        case ibook:
            name = "ibook";
            break;
        case highrespb:
            name = "highrespb";
            break;
        case macbookpro:
            name = "macbookpro";
            break;
        default:
            name = "???";
            break;
    }
    fprintf(stderr, "Detected SMS type %d (%s)\n", type, name);

    // -------------------------------------------------------
    // Reading Values of Sudden Motion Sensor

    int ok = 0;
    ok = read_sms_raw(type, &x, &y, &z);
    if (ok) {
        printf("%d %d %d\n",x,y,z);
    }

    // -------------------------------------------------------

    return 0;
}