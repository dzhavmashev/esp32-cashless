// Function : FUN_40188498
// Address  : 0x40188498
// Size     : 233 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_40188498(char param_1,char param_2,char param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  param_4 = param_4 & 0xff;
  uVar5 = _DAT_3ffc0034[param_4 + 1];
  uVar4 = *_DAT_3ffc0034;
  if (uVar5 == 0) {
    bVar1 = *(byte *)((int)_DAT_3ffc0034 + param_4 + 0x18);
    if ((uVar4 & 1 << (bVar1 & 0x1f)) == 0) {
      FUN_401634e0((uint)bVar1);
      return (uint)bVar1;
    }
  }
  else {
    do {
      uVar2 = 0x1f - LZCOUNT(-uVar5 & uVar5);
      if ((((char)_DAT_3ffc0034[uVar2 * 0xc + 0xb] == param_3) &&
          (*(char *)((int)_DAT_3ffc0034 + uVar2 * 0x30 + 0x2d) == param_2)) &&
         (*(char *)((int)_DAT_3ffc0034 + uVar2 * 0x30 + 0x2e) == param_1)) goto LAB_4018857e;
      uVar5 = uVar5 & (1 << 0x20 - (0x20 - (uVar2 & 0x1f)) ^ 0xffffffffU);
    } while (uVar5 != 0);
  }
  uVar5 = (uVar4 | 7) ^ 0xffff;
  uVar3 = (1 << 0x20 - (0x20 - (*(byte *)((int)_DAT_3ffc0034 + param_4 + 0x18) & 0x1f))) - 1U &
          uVar5;
  uVar5 = uVar5 ^ uVar3;
  uVar2 = 0x10;
  if (uVar3 != 0 || uVar5 != 0) {
    if (uVar3 != 0) {
      uVar5 = uVar3;
    }
    uVar2 = -LZCOUNT(uVar5) + 0x1f;
    uVar3 = (1 << 0x20 - (0x20 - (uVar2 & 0x1f))) - 1U & uVar4;
    if (uVar3 == 0) {
      uVar2 = (int)((uVar2 - LZCOUNT(uVar4 ^ uVar3)) + 0x2d) >> 1;
      if (0xf < (int)uVar2) {
        uVar2 = uVar2 - 0xd;
      }
    }
    else {
      uVar2 = (-LZCOUNT(uVar5) + 0x3f) - LZCOUNT(uVar3) >> 1;
    }
    FUN_401634e0(uVar2);
LAB_4018857e:
    uVar2 = uVar2 & 0xff;
  }
  return uVar2;
}

