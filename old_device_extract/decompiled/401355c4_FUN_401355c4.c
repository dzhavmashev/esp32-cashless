// Function : FUN_401355c4
// Address  : 0x401355c4
// Size     : 47 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401355c4(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  if (_DAT_3ffc7888 == 0) {
    iVar1 = 0;
    for (piVar3 = &DAT_3f41e048; iVar2 = *piVar3, *(int *)(iVar1 * 4 + 0x3ffc788c) = iVar2,
        iVar2 != 0; piVar3 = piVar3 + 3) {
      iVar1 = iVar1 + 1;
    }
    _DAT_3ffc7888 = 1;
    memw();
  }
  return;
}

