// Function : FUN_40162f2c
// Address  : 0x40162f2c
// Size     : 288 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40162f2c(byte param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  
  uVar4 = 4;
  if (param_1 < 8) {
    if ((param_1 == 0) || (param_1 == 3)) {
      uVar4 = 2;
    }
    else {
      uVar4 = 3;
      if (2 < param_1) {
        uVar4 = (uint)(param_1 < 6);
      }
    }
  }
  iVar2 = *(int *)(uVar4 * 4 + _DAT_3ffc0034 + 800);
  *(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) =
       *(uint *)(*(int *)(iVar2 + 0x2c) + 0x10) & 0xff0fffff | (param_2 & 0xf) << 0x14;
  *(undefined1 *)(*(int *)(iVar2 + 0x2c) + 6) = 0;
  memw();
  *(undefined1 *)(*(int *)(iVar2 + 0x2c) + 7) = 0;
  memw();
  *(undefined1 *)(*(int *)(iVar2 + 0x2c) + 5) = 0;
  memw();
  iVar5 = *(int *)(iVar2 + 0x2c);
  if (((DAT_3ffc1a44 == '\0') || (memw(), DAT_3ffc1a3c != '\0')) || (_DAT_3ffc1a40 == 0)) {
    memw();
    iVar3 = _DAT_3ff73c00 + _DAT_3ffc1a30;
  }
  else {
    memw();
    iVar3 = (**(code **)(_DAT_3ffc1a34 + 0x110))();
  }
  *(int *)(iVar5 + 0x18) = iVar3;
  memw();
  FUN_401647d0(*(undefined4 *)(iVar2 + 0x24),*(undefined4 *)(iVar2 + 0x2c));
  puVar6 = *(uint **)(iVar2 + 4);
  memw();
  puVar6[1] = uVar4 * 0x24 + 0x3ffc1adc;
  uVar1 = *(ushort *)(iVar2 + 0x16);
  memw();
  *puVar6 = *puVar6 | 0x80000000;
  memw();
  memw();
  *puVar6 = *puVar6 | 0x40000000;
  memw();
  memw();
  *puVar6 = *puVar6 & 0xdfffffff;
  memw();
  memw();
  *puVar6 = *puVar6 & 0xff000fff | (uVar1 & 0xfff) << 0xc;
  memw();
  FUN_40187dd4(iVar2,*(uint *)(*(int *)(iVar2 + 0x2c) + 4) >> 4 & 0xf);
  return;
}

