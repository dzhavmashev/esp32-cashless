// Function : FUN_40155438
// Address  : 0x40155438
// Size     : 94 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40155438(char param_1)

{
  int iVar1;
  
  while (iVar1 = _DAT_3ffc8994, _DAT_3ffc8994 != 0) {
    FUN_40147fe4(1,8,5,0x3f43609b,_DAT_3ffc8994);
    _DAT_3ffc8994 = *(int *)(_DAT_3ffc8994 + 0x28);
    if (_DAT_3ffc8994 == 0) {
      _DAT_3ffc8998 = &DAT_3ffc8994;
    }
    *(undefined4 *)(iVar1 + 0x28) = 0;
    if (param_1 == '\0') {
      FUN_40147fe4(1,0x40,3,0x3f434ef9);
      FUN_4015fb44(iVar1);
    }
    else {
      memw();
      FUN_4015fb20(iVar1);
    }
  }
  return;
}

