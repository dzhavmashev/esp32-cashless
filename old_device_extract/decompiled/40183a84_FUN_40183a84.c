// Function : FUN_40183a84
// Address  : 0x40183a84
// Size     : 29 bytes


uint FUN_40183a84(int *param_1)

{
  uint uVar1;
  
  if ((*(byte *)((int)param_1 + 0xf) & 0x80) == 0) {
    uVar1 = 0;
    if (*param_1 != 0) {
      uVar1 = param_1[2];
    }
  }
  else {
    uVar1 = (uint)param_1[3] >> 0x18 & 0x7f;
  }
  return uVar1;
}

