// Function : FUN_400fc7f4
// Address  : 0x400fc7f4
// Size     : 70 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_400fc7f4(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  (*(code *)&SUB_40092a98)(0x3ffbdcd4,0xffffffff);
  iVar1 = FUN_400fc730(param_1);
  if (iVar1 != 0) {
    iVar3 = _DAT_3ffc56ec;
    iVar2 = *(int *)(iVar1 + 8);
    if (_DAT_3ffc56ec != iVar1) {
      do {
        iVar2 = iVar3;
        iVar3 = *(int *)(iVar2 + 8);
      } while (iVar3 != iVar1);
      *(int *)(iVar2 + 8) = *(int *)(iVar1 + 8);
      memw();
      iVar2 = _DAT_3ffc56ec;
    }
    _DAT_3ffc56ec = iVar2;
    memw();
    (*(code *)&SUB_40094d80)();
  }
  (*(code *)&SUB_40092bec)(0x3ffbdcd4);
  return 0;
}

