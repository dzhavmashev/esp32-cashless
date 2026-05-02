// Function : FUN_40184548
// Address  : 0x40184548
// Size     : 47 bytes


int FUN_40184548(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  param_1[2] = 0;
  do {
    if ((uint)param_1[1] <= (uint)param_1[2]) {
      iVar1 = 0;
      break;
    }
    iVar1 = (*(code *)param_1[4])(param_1);
    param_1[2] = param_1[2] + 1;
  } while (iVar1 == 0);
  *param_4 = *param_4 + param_1[2];
  return iVar1;
}

