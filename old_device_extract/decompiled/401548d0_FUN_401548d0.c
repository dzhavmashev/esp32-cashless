// Function : FUN_401548d0
// Address  : 0x401548d0
// Size     : 89 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_401548d0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc8804;
  iVar2 = FUN_4015483c(param_1 + 0x108);
  if (iVar2 != 0) {
    iVar3 = FUN_40187c04();
    if (iVar3 == 0) {
      *(undefined4 *)(iVar2 + 0x28) = 0;
      *_DAT_3ffc8998 = iVar2;
      _DAT_3ffc8998 = (int *)(iVar2 + 0x28);
    }
    else {
      FUN_4015fb20(iVar2);
      _DAT_3ffc794e = _DAT_3ffc794e + 1;
      memw();
      memw();
    }
    *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
    param_1 = iVar1 + 0x100;
    *(int *)(iVar1 + 0x13c) = *(int *)(iVar1 + 0x13c) + 1;
  }
  memw();
  return param_1;
}

