// Function : FUN_400f2f4c
// Address  : 0x400f2f4c
// Size     : 23 bytes


char FUN_400f2f4c(uint param_1)

{
  char cVar1;
  
  cVar1 = '=';
  if ((param_1 & 0xff) < 0x40) {
    cVar1 = "uartSetPins"[(param_1 & 0xff) + 4];
  }
  return cVar1;
}

