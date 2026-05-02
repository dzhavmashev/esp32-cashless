// Function : FUN_40188374
// Address  : 0x40188374
// Size     : 104 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40188374(int param_1,char param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  code *pcVar5;
  
  for (uVar3 = *(uint *)(*(int *)(param_1 + 0x2c) + 0x14); uVar3 != 0;
      uVar3 = uVar3 & (uint)(0xfffffffefffffffe >> 0x20 - (uVar2 & 0x1f))) {
    uVar2 = 0x1f - LZCOUNT(-uVar3 & uVar3);
    uVar4 = 1 << 0x20 - (0x20 - (uVar2 & 0x1f));
    if (param_2 == '\0') {
      bVar1 = false;
      if ((uVar4 & *(uint *)(_DAT_3ffc0034 + 0x354)) != 0) {
        bVar1 = true;
      }
    }
    else {
      bVar1 = (uVar4 & *(uint *)(_DAT_3ffc0034 + 0x3bc)) != 0;
    }
    if ((bVar1) && (pcVar5 = *(code **)(uVar2 * 4 + _DAT_3ffc0034 + 0x35c), pcVar5 != (code *)0x0))
    {
      (*pcVar5)(param_1);
    }
  }
  return;
}

