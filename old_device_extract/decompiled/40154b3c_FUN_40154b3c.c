// Function : FUN_40154b3c
// Address  : 0x40154b3c
// Size     : 55 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40154b3c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc8804;
  iVar2 = *(int *)(_DAT_3ffc8804 + 0xec);
  FUN_401549d8(param_1,1);
  if ((*(uint *)(param_1 + 0xc) & 0x10) != 0) {
    iVar3 = *(int *)(iVar1 + 0x130) + -1;
    *(int *)(iVar1 + 0x130) = iVar3;
    if (iVar3 == 0) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) & 0xffffffef;
      memw();
      FUN_401549d8(iVar2);
    }
  }
  return;
}

