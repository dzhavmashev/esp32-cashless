// Function : FUN_40188584
// Address  : 0x40188584
// Size     : 262 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40188584(uint param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  param_1 = param_1 & 0xff;
  if (param_1 == 4) {
    iVar2 = FUN_401633f8(2);
  }
  else {
    FUN_40163808(param_1);
    bVar1 = *(byte *)(_DAT_3ffc0034 + param_1 + 0x18);
    if ((param_1 == 0) &&
       (((*(uint *)(_DAT_3ffc0034 + 4) & 1 << (bVar1 & 0x1f)) == 0 ||
        (*(char *)(_DAT_3ffc0034 + (bVar1 + 1) * 0x30 + 1) == '\0')))) {
      iVar2 = FUN_401633f8(0);
      if (iVar2 != 0) {
        return iVar2;
      }
      iVar2 = FUN_401633f8(1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
    uVar7 = *(uint *)(param_1 * 4 + _DAT_3ffc0034 + 4);
    uVar5 = (1 << 0x20 - (0x20 - (bVar1 & 0x1f))) - 1U & uVar7;
    for (uVar7 = uVar7 ^ uVar5; uVar7 != 0;
        uVar7 = uVar7 & (1 << 0x20 - (0x20 - (uVar3 & 0x1f)) ^ 0xffffffffU)) {
      iVar4 = -LZCOUNT(-uVar7 & uVar7);
      uVar3 = iVar4 + 0x1f;
      memw();
      iVar2 = FUN_401633f8(uVar3);
      iVar6 = _DAT_3ffc0034;
      if (iVar2 != 0) {
        *(char *)(_DAT_3ffc0034 + param_1 + 0x18) = (char)uVar3;
        goto LAB_4018861f;
      }
    }
    while( true ) {
      if (uVar5 == 0) {
        return 0;
      }
      iVar4 = -LZCOUNT(-uVar5 & uVar5);
      uVar7 = iVar4 + 0x1f;
      iVar2 = FUN_401633f8(uVar7);
      iVar6 = _DAT_3ffc0034;
      if (iVar2 != 0) break;
      uVar5 = uVar5 & (1 << 0x20 - (0x20 - (uVar7 & 0x1f)) ^ 0xffffffffU);
    }
    *(char *)(_DAT_3ffc0034 + param_1 + 0x18) = (char)uVar7;
    memw();
    memw();
LAB_4018861f:
    *(undefined1 *)(iVar6 + (iVar4 + 0x20) * 0x30 + 1) = 1;
    memw();
  }
  memw();
  return iVar2;
}

