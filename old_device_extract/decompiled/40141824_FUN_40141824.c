// Function : FUN_40141824
// Address  : 0x40141824
// Size     : 43 bytes


int FUN_40141824(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int local_24 [9];
  
  iVar1 = FUN_40141738(param_1,param_2,local_24,2);
  if (iVar1 == 0) {
    iVar1 = FUN_4013183c(param_3,*param_1,local_24[0]);
    *param_1 = *param_1 + local_24[0];
  }
  memw();
  return iVar1;
}

