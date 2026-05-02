// Function : FUN_400d4228
// Address  : 0x400d4228
// Size     : 61 bytes


undefined4 FUN_400d4228(ushort *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = param_2 & 0xffff;
  if ((uVar2 + 0x2800 & 0xffff) < 0x400) {
    *param_1 = (ushort)param_2 & 0x3ff;
    uVar1 = 0;
  }
  else {
    if ((uVar2 + 0x2400 & 0xffff) < 0x400) {
      uVar2 = ((uint)*param_1 << 10 | param_2 & 0x3ff) + 0x10000;
    }
    *(uint *)(param_1 + 2) = uVar2;
    uVar1 = 1;
  }
  return uVar1;
}

