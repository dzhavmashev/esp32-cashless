// Function : FUN_4014195c
// Address  : 0x4014195c
// Size     : 50 bytes


int FUN_4014195c(undefined4 *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = FUN_40141738(param_1,param_2,param_3,3);
  if (iVar1 == 0) {
    if (*param_3 != 0) {
      *param_3 = *param_3 + -1;
      if (*(char *)*param_1 == '\0') {
        *param_1 = (char *)*param_1 + 1;
        memw();
        return 0;
      }
    }
    iVar1 = -0x68;
  }
  return iVar1;
}

