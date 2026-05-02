// Function : FUN_400e3ea8
// Address  : 0x400e3ea8
// Size     : 60 bytes


undefined4 FUN_400e3ea8(undefined4 param_1,int param_2)

{
  int iVar1;
  
  FUN_400f0be8(param_1,&DAT_3f42161d);
  if ((param_2 == 0) || (iVar1 = (*(code *)&LAB_40183af3_1)(param_2), iVar1 == 0)) {
    FUN_400d5948(param_2,param_1);
  }
  else {
    FUN_400f0d70(param_1,iVar1);
  }
  return param_1;
}

