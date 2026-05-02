// Function : FUN_40185174
// Address  : 0x40185174
// Size     : 101 bytes


char FUN_40185174(undefined1 *param_1,uint param_2)

{
  char cVar1;
  
  cVar1 = (param_2 & 8) != 0;
  if ((bool)cVar1) {
    *param_1 = 0;
    param_1[1] = 0xf;
    param_1[2] = 0xac;
    param_1[3] = 4;
    memw();
    param_1 = param_1 + 4;
  }
  if ((param_2 & 2) != 0) {
    *param_1 = 0;
    cVar1 = cVar1 + '\x01';
    param_1[1] = 0xf;
    param_1[2] = 0xac;
    param_1[3] = 2;
    memw();
    param_1 = param_1 + 4;
  }
  if ((param_2 & 1) != 0) {
    param_1[1] = 0xf;
    cVar1 = cVar1 + '\x01';
    *param_1 = 0;
    param_1[2] = 0xac;
    param_1[3] = 0;
    memw();
  }
  memw();
  return cVar1;
}

