// Function : FUN_40106748
// Address  : 0x40106748
// Size     : 62 bytes


void FUN_40106748(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  for (param_1 = (int *)*param_1;
      (param_1 != (int *)0x0 &&
      ((((param_2 != 0 && (iVar1 = (*(code *)&SUB_4008b33c)(param_1 + 0x18,param_2,6), iVar1 != 0))
        || ((param_3 != 0 &&
            (iVar1 = (*(code *)&SUB_4008b33c)(param_1 + 1,param_3,0x10), iVar1 != 0)))) ||
       ((param_4 != 0 && (param_1[0x1b] != param_4)))))); param_1 = (int *)*param_1) {
  }
  return;
}

