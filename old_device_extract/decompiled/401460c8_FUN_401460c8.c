// Function : FUN_401460c8
// Address  : 0x401460c8
// Size     : 33 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401460c8(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_4014605c();
  uVar2 = 0;
  if (iVar1 == 0) {
    if (_DAT_3ffbfc30 != 3) {
      FUN_401460a4();
      return 0;
    }
    FUN_401460a4();
    uVar2 = 1;
  }
  return uVar2;
}

