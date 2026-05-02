// Function : FUN_40121604
// Address  : 0x40121604
// Size     : 47 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40121604(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  memw();
  uVar1 = _DAT_3ff5a018 & 3;
  if ((uVar1 == 0) || (uVar1 == 3)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    if (uVar1 != 1) {
      uVar2 = 2;
    }
  }
  return uVar2;
}

