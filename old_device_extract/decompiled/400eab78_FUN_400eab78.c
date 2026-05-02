// Function : FUN_400eab78
// Address  : 0x400eab78
// Size     : 32 bytes


void FUN_400eab78(int *param_1)

{
  int iVar1;
  int iVar2;
  
  while (iVar1 = *param_1, iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x2c);
    FUN_400ebbc0(iVar1 + 4);
    FUN_4016fa48(iVar1);
    *param_1 = iVar2;
  }
  return;
}

