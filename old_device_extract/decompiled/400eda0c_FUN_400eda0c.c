// Function : FUN_400eda0c
// Address  : 0x400eda0c
// Size     : 98 bytes


void FUN_400eda0c(int *param_1,char param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)&LAB_40184637_1)(param_1);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)param_1[2] + 0x18))();
    if (0 < iVar1) {
      (**(code **)(*(int *)param_1[2] + 0x14))();
    }
    if (((((char)param_1[9] == '\0') || ((char)param_1[0x27] == '\0')) &&
        ((**(code **)(*(int *)param_1[2] + 0x3c))(), param_2 == '\0')) &&
       (param_1[2] = 0, param_1[1] != 0)) {
      iVar1 = *param_1;
      *param_1 = 0;
      if (iVar1 != 0) {
        FUN_40184628();
      }
      iVar1 = param_1[1];
      param_1[1] = 0;
      if (iVar1 != 0) {
        FUN_40184618();
      }
    }
  }
  return;
}

