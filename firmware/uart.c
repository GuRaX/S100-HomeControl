/** uart.c  created by Arne Schröder 29.09.2009
 *  These file provides basic UART I/O functions
 *  on a later developement state may with send and receive buffer
 *  but till now only basic functions (init, putc, putstr).
 *  @todo   - implement send and receive buffer.
 *          - implement variable boutrate
 */

/* PROTOTYPES */
void initUART(char)
void putc(char);
void putstr(char*);



/* IMPLEMENTATION */

/**
 *
 */
void initUART(char baudrate)
{
    UCSRA = 0x00;
    UCSRB = (1<<TXEN) | (1<<RXEN); 
    UCSRC = (1<<UCSZ1)  | (1<<UCSZ0); 
    UBRRL = 0x67;                        /* should be depended on baudrate  */
}


/**
 *
 */
void putc(char c)
{
    while (!(UCSRA & UDRE));
    UCR = c;
}



/**
 *
 */
void putstr(char *str)
{
    while (str != 0)
    {
        putc(str);
        *str++;
    }
}



