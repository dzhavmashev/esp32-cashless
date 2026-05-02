// Function : FUN_40161378
// Address  : 0x40161378
// Size     : 92 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40161378(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_3ffca1ed == '\0') {
    return 0xfffffffe;
  }
  iVar2 = _DAT_3ffca204;
  if (_DAT_3ffca1fc != 0) {
    if (_DAT_3ffca1fc == 1) {
      uVar1 = (uint)DAT_3ffca1e3;
    }
    else {
      if (_DAT_3ffca1fc != 2) goto LAB_401613a4;
      uVar1 = (uint)_DAT_3ffca1f8;
    }
    iVar2 = uVar1 * _DAT_3ffca204;
  }
LAB_401613a4:
  if ((int)(uint)_DAT_3ffca1f4 % ((iVar2 + 0x40000) / iVar2) != 0) {
    return 0;
  }
  FUN_4016a298(1);
  iVar2 = FUN_4016a278();
  DAT_3ffc072b = (char)(iVar2 + 2 >> 2);
  memw();
  memw();
  return 0;
}

