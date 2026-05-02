// Function : FUN_40146820
// Address  : 0x40146820
// Size     : 42 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40146820(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_401460c8();
  uVar2 = 0x3001;
  if ((iVar1 != 0) && (uVar2 = 0x102, param_1 != (uint *)0x0)) {
    FUN_4014605c();
    *param_1 = (uint)*_DAT_3ffbfc54;
    memw();
    FUN_401460a4();
    uVar2 = 0;
  }
  return uVar2;
}

