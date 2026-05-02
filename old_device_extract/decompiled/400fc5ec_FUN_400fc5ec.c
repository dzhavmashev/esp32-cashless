// Function : FUN_400fc5ec
// Address  : 0x400fc5ec
// Size     : 50 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400fc5ec(void)

{
  int iVar1;
  
  iVar1 = FUN_400fc7ac(&DAT_3ffc56e4,0x400fc5d4);
  if (iVar1 == 0) {
    _DAT_3ffc56e8 = (*(code *)&SUB_4008fcc8)(1);
    if (_DAT_3ffc56e8 != 0) {
      return 0;
    }
    memw();
    FUN_400fc7f4(_DAT_3ffc56e4);
  }
  return 0x101;
}

