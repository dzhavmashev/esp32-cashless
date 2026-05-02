// Function : FUN_40102db4
// Address  : 0x40102db4
// Size     : 65 bytes


int FUN_40102db4(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_40185144(param_1);
  *param_5 = iVar1;
  iVar2 = -1;
  if (iVar1 != 0) {
    *param_4 = 6;
    memw();
    iVar1 = (*(code *)&LAB_40185113_1)(param_1);
    iVar2 = -(uint)(iVar1 != param_2 || param_3 < iVar1);
  }
  return iVar2;
}

