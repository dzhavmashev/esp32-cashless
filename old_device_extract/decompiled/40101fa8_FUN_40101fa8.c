// Function : FUN_40101fa8
// Address  : 0x40101fa8
// Size     : 54 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40101fa8(void)

{
  int iVar1;
  undefined *puStack_28;
  undefined4 uStack_24;
  
  FUN_40101dec();
  iVar1 = 0;
  if (_DAT_3ffbde90 != 1) {
    uStack_24 = 0;
    puStack_28 = &DAT_40101f88;
    memw();
    iVar1 = FUN_4015a968(&puStack_28);
    if (iVar1 == 0) {
      _DAT_3ffbde90 = 1;
      memw();
    }
  }
  FUN_40101dd8();
  return iVar1;
}

