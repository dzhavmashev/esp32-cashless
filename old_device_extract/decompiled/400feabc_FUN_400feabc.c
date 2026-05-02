// Function : FUN_400feabc
// Address  : 0x400feabc
// Size     : 53 bytes


void FUN_400feabc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < param_1; iVar2 = iVar2 + 1) {
    iVar1 = FUN_400fea78(iVar2);
    if (((iVar1 != 0) && (*(code **)(iVar1 + 0xa0) != (code *)0x0)) &&
       (*(char *)(param_2 + iVar2 * 0x1c) != '\0')) {
      (**(code **)(iVar1 + 0xa0))(*(undefined4 *)(param_3 + iVar2 * 4));
    }
  }
  return;
}

