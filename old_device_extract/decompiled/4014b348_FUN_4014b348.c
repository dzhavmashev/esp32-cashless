// Function : FUN_4014b348
// Address  : 0x4014b348
// Size     : 114 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4014b348(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_30 [12];
  
  iVar1 = _DAT_3ffc8804;
  iVar3 = 600000;
  if (_DAT_3ffc8800 != 0) {
    FUN_4014b1ec(*(undefined4 *)(_DAT_3ffc8800 + 0xe4),local_30);
    iVar3 = local_30[0];
  }
  if (iVar1 != 0) {
    for (uVar2 = *(uint *)(iVar1 + 300); uVar2 != 0;
        uVar2 = uVar2 & (1 << 0x20 - (0x20 - (0x1fU - LZCOUNT(-uVar2 & uVar2) & 0x1f)) ^ 0xffffffffU
                        )) {
      FUN_4014b1ec(*(undefined4 *)(LZCOUNT(-uVar2 & uVar2) * -4 + iVar1 + 0x168),local_30);
      iVar3 = (uint)(iVar3 < local_30[0]) * iVar3 + (uint)(iVar3 >= local_30[0]) * local_30[0];
    }
  }
  if (DAT_3ffc8a37 != '\0') {
    FUN_4014a324();
  }
  if (iVar3 != 600000) {
    FUN_4014b2fc((uint)(iVar3 < 100000) * 100000 + (uint)(iVar3 >= 100000) * iVar3);
  }
  return;
}

