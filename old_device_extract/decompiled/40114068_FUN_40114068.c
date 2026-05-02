// Function : FUN_40114068
// Address  : 0x40114068
// Size     : 75 bytes


void FUN_40114068(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  
  *(undefined1 *)(param_2 + param_1) = 0xff;
  memw();
  while( true ) {
    uVar1 = param_1 + 1;
    param_1 = uVar1 & 0xffff;
    if ((0x43 < param_1) && (((uVar1 & 3) == 0 || (0x7f < param_1)))) break;
    *(undefined1 *)(param_2 + param_1) = 0;
    memw();
    memw();
  }
  memw();
  FUN_4010bd2c(param_3,param_1 + 0xf0 & 0xffff);
  return;
}

