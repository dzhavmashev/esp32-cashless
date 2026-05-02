// Function : FUN_401851dc
// Address  : 0x401851dc
// Size     : 96 bytes


char FUN_401851dc(undefined1 *param_1,uint param_2)

{
  char cVar1;
  
  cVar1 = (param_2 & 8) != 0;
  if ((bool)cVar1) {
    *param_1 = 0;
    param_1[1] = 0x50;
    param_1[2] = 0xf2;
    param_1[3] = 4;
    memw();
    param_1 = param_1 + 4;
  }
  if ((param_2 & 2) != 0) {
    *param_1 = 0;
    cVar1 = cVar1 + '\x01';
    param_1[1] = 0x50;
    param_1[2] = 0xf2;
    param_1[3] = 2;
    memw();
    param_1 = param_1 + 4;
  }
  if ((param_2 & 1) != 0) {
    param_1[1] = 0x50;
    cVar1 = cVar1 + '\x01';
    *param_1 = 0;
    param_1[2] = 0xf2;
    param_1[3] = 0;
    memw();
  }
  memw();
  return cVar1;
}

