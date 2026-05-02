// Function : FUN_40162aa0
// Address  : 0x40162aa0
// Size     : 71 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40162aa0(undefined4 param_1,uint param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  iVar1 = _DAT_3ffc0034;
  uVar3 = 1;
  uVar2 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
  if (((*(uint *)(_DAT_3ffc0034 + 0x354) & uVar2) == 0) &&
     ((uVar2 & *(uint *)(_DAT_3ffc0034 + 0x3bc)) == 0)) {
    if (param_3 == '\0') {
      *(uint *)(_DAT_3ffc0034 + 0x354) = *(uint *)(_DAT_3ffc0034 + 0x354) | uVar2;
    }
    else {
      *(uint *)(_DAT_3ffc0034 + 0x3bc) = uVar2 | *(uint *)(_DAT_3ffc0034 + 0x3bc);
      memw();
    }
    uVar3 = 0;
    *(undefined4 *)((param_2 & 0xff) * 4 + iVar1 + 0x35c) = param_1;
  }
  memw();
  return uVar3;
}

