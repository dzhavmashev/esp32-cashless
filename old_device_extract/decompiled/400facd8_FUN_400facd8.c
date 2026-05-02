// Function : FUN_400facd8
// Address  : 0x400facd8
// Size     : 33 bytes


void FUN_400facd8(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x10);
  while( true ) {
    if (iVar1 == 0) {
      return;
    }
    uVar2 = (**(code **)(**(int **)(iVar1 + 8) + 8))();
    iVar3 = (*(code *)&SUB_4008bdec)(uVar2,param_2);
    if (iVar3 == 0) break;
    iVar1 = *(int *)(iVar1 + 4);
  }
  return;
}

