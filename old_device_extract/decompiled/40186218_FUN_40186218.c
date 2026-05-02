// Function : FUN_40186218
// Address  : 0x40186218
// Size     : 34 bytes


void FUN_40186218(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  while (uVar1 < (uint)(param_2 - param_3)) {
    *(char *)(param_1 + uVar1 + param_3) = (char)(param_2 - param_3);
    memw();
    uVar1 = uVar1 + 1 & 0xff;
    memw();
  }
  return;
}

