// Function : FUN_40129da0
// Address  : 0x40129da0
// Size     : 30 bytes


void FUN_40129da0(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x44) != 0) {
    FUN_401291f4();
    iVar1 = 0;
    do {
      iVar2 = iVar1 + 1;
      FUN_40129090(param_1,iVar1);
      iVar1 = iVar2;
    } while (iVar2 != 4);
  }
  return;
}

