// Function : FUN_40184640
// Address  : 0x40184640
// Size     : 44 bytes


bool FUN_40184640(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (*(int **)(param_1 + 8) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x18))();
    bVar2 = true;
    if (iVar1 < 1) {
      iVar1 = (**(code **)(**(int **)(param_1 + 8) + 0x40))();
      bVar2 = iVar1 != 0;
    }
  }
  return bVar2;
}

