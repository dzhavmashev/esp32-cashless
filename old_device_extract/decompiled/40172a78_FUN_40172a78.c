// Function : FUN_40172a78
// Address  : 0x40172a78
// Size     : 84 bytes


float FUN_40172a78(float param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = ((uint)param_1 >> 0x17 & 0xff) - 0x7f;
  if ((int)uVar1 < 0x17) {
    if ((int)uVar1 < 0) {
      param_1 = (float)((uint)param_1 & 0x80000000);
      if (uVar1 == 0xffffffff) {
        param_1 = (float)((uint)param_1 | 0x3f800000);
      }
    }
    else {
      uVar2 = 0x7fffff >> (uVar1 & 0x1f);
      if ((uVar2 & (uint)param_1) != 0) {
        param_1 = (float)((uVar2 ^ 0xffffffff) & (0x400000 >> (uVar1 & 0x1f)) + (int)param_1);
      }
    }
  }
  else if (uVar1 == 0x80) {
    param_1 = param_1 + param_1;
  }
  return param_1;
}

