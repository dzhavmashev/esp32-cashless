// Function : FUN_40127814
// Address  : 0x40127814
// Size     : 44 bytes


void FUN_40127814(int *param_1)

{
  int iVar1;
  
  while (param_1 != (int *)0x0) {
    FUN_40128d84(param_1[3],1);
    FUN_40128a7c(param_1[5],1);
    FUN_40128cf8(param_1[2]);
    iVar1 = *param_1;
    (*(code *)&SUB_40094d80)(param_1);
    param_1 = (int *)iVar1;
  }
  return;
}

