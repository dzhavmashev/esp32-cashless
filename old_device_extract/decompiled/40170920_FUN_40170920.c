// Function : FUN_40170920
// Address  : 0x40170920
// Size     : 111 bytes


undefined8 FUN_40170920(int param_1,uint param_2)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  if ((~param_2 & 0x7ff00000) == 0) {
    if ((param_2 & 0xfffff) != 0 || param_1 != 0) {
      return 0xffffffffffffffff;
    }
  }
  else {
    uVar3 = param_2 >> 0x14 & 0x7ff;
    iVar4 = uVar3 - 0x3ff;
    if (iVar4 < 0x40) {
      if (iVar4 < 0) {
        return 0;
      }
      uVar1 = (CONCAT44(param_2,param_1) | 0x7ff0000000000000) >> 0x15;
      uVar2 = (uint)uVar1;
      uVar3 = uVar3 - 0x3fe;
      if (uVar3 == 0x40) {
        if ((int)(param_2 | 0x7ff00000) < 0) {
          return 0x8000000000000000;
        }
        return CONCAT44(uVar2,param_1 << 0xb);
      }
      iVar4 = 0x20 - (uVar3 & 0x1f);
      if ((int)uVar3 < 0x20) {
        uVar3 = uVar2 >> iVar4;
        uVar2 = 0;
      }
      else {
        uVar3 = (uint)((uVar1 << 0x20 | (ulonglong)(uint)(param_1 << 0xb)) >> iVar4);
        uVar2 = uVar2 >> iVar4;
      }
      if ((int)(param_2 | 0x7ff00000) < 0) {
        uVar3 = -uVar3;
        uVar2 = -uVar2;
        if (uVar3 != 0) {
          uVar2 = uVar2 - 1;
        }
      }
      return CONCAT44(uVar2,uVar3);
    }
  }
  if ((int)param_2 < 0) {
    return 0x8000000000000000;
  }
  return 0xffffffffffffffff;
}

