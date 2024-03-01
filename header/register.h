// Based on DM74LS273 8-Bit Register with Clear
// link: https://ece-classes.usc.edu/ee459/library/datasheets/DM74LS273.pdf

struct Register
{
    // Clock pulse input
    unsigned int cp;

    // Asynchronous Master Reset Input (Active LOW)
    unsigned int mr;

    // Data inputs
    unsigned int D0 : 1;
    unsigned int D1 : 1;
    unsigned int D2 : 1;
    unsigned int D3 : 1;
    unsigned int D4 : 1;
    unsigned int D5 : 1;
    unsigned int D6 : 1;
    unsigned int D7 : 1;

    // Data outputs
    /*Information meeting the setup and hold time requirements of the D inputs is
    transferred to the Q outputs on the LOW-to-HIGH transition of the clock input.*/
    unsigned int Q0 : 1;
    unsigned int Q1 : 1;
    unsigned int Q2 : 1;
    unsigned int Q3 : 1;
    unsigned int Q4 : 1;
    unsigned int Q5 : 1;
    unsigned int Q6 : 1;
    unsigned int Q7 : 1;
};
