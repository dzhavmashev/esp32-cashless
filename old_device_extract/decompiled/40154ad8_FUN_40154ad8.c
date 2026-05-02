// Function : FUN_40154ad8
// Address  : 0x40154ad8
// Size     : 98 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40154ad8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _DAT_3ffc8804;
  iVar3 = *(int *)(_DAT_3ffc8804 + 0xec);
  if (param_2 == 0) {
    iVar2 = *(int *)(_DAT_3ffc8804 + 0x130) + -1;
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & 0xffffffef;
    *(int *)(iVar1 + 0x130) = iVar2;
    if (iVar2 == 0) {
      *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) & 0xffffffef;
      memw();
      FUN_401549d8();
    }
    FUN_401547bc(param_1,0);
    if (*(int *)(param_1 + 0x108) != 0) {
      FUN_401549d8(param_1,0);
    }
  }
  else {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) | 0x10;
    iVar2 = *(int *)(iVar1 + 0x130) + 1;
    *(int *)(iVar1 + 0x130) = iVar2;
    if (0 < iVar2) {
      *(uint *)(iVar3 + 0xc) = *(uint *)(iVar3 + 0xc) | 0x10;
      memw();
      return;
    }
  }
  return;
}

