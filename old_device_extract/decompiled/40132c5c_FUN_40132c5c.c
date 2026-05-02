// Function : FUN_40132c5c
// Address  : 0x40132c5c
// Size     : 37 bytes


int FUN_40132c5c(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_3f41d570;
  while ((iVar1 = puVar2[1], iVar1 != 0 &&
         (((**(int **)(iVar1 + 0x1c) != param_1 || (*(int *)(iVar1 + 8) != param_2)) ||
          (*(int *)(iVar1 + 4) != param_3))))) {
    puVar2 = puVar2 + 2;
  }
  return iVar1;
}

