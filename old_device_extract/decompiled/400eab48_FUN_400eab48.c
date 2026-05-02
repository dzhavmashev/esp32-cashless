// Function : FUN_400eab48
// Address  : 0x400eab48
// Size     : 47 bytes


void FUN_400eab48(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x678);
  if ((((piVar2 != (int *)0x0) && (*(int *)(param_1 + 0x688) == 0)) &&
      ((*(int **)(param_1 + 0x680) == (int *)0x0 || (*(int **)(param_1 + 0x680) != piVar2)))) &&
     (iVar1 = FUN_400f1a9c(), *(uint *)(param_1 + 0xac) < (uint)(iVar1 - *piVar2))) {
    *(undefined4 *)(param_1 + 0x680) = *(undefined4 *)(param_1 + 0x678);
  }
  return;
}

