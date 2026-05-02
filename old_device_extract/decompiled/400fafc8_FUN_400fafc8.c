// Function : FUN_400fafc8
// Address  : 0x400fafc8
// Size     : 35 bytes


void FUN_400fafc8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    (*(code *)&LAB_401849ef_1)(param_1,iVar1);
    (*(code *)&SUB_40094d80)(iVar1);
    iVar1 = iVar2;
  }
  return;
}

