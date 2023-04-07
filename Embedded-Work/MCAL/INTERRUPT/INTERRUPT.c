#include "INTERRUPT.h"

ERROR_int Enable_INT(void) {
    SET_BIT(SREG, enable);
    return OK;
}

ERROR_int Enable_INT0(uint8_t INT_STATE) {
    Enable_INT();
    SET_BIT(GICR, INT0);
    if (INT_STATE == FALLING) {
        SET_BIT(MCUCR, ISC01);
        CLR_BIT(MCUCR, ISC00);
    } else if (INT_STATE == RISING) {
        SET_BIT(MCUCR, ISC00);
        SET_BIT(MCUCR, ISC01);
    } else {
        return ERROR;
    }
    return OK;
}

ERROR_int Enable_INT1(uint8_t INT_STATE) {
    Enable_INT();
    SET_BIT(GICR, INT1);
    if (INT_STATE == FALLING) {
        CLR_BIT(MCUCR, ISC10);
        SET_BIT(MCUCR, ISC11);
    } else if (INT_STATE == RISING) {
        SET_BIT(MCUCR, ISC10);
        SET_BIT(MCUCR, ISC11);
    } else {
        return ERROR;
    }
    return OK;
}

ERROR_int Enable_INT2(uint8_t INT_STATE) {
    Enable_INT();
    SET_BIT(GICR, INT2);
    if (INT_STATE == FALLING) {
        CLR_BIT(MCUCSR, ISC2);
    } else if (INT_STATE == RISING) {
        SET_BIT(MCUCSR, ISC2);
    } else {
        return ERROR;
    }
    return OK;
}

ERROR_int Disable_INT(void) {
    cli();
    return OK;
}
