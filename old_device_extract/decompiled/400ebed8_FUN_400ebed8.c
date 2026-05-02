// Function : FUN_400ebed8
// Address  : 0x400ebed8
// Size     : 61 bytes


void FUN_400ebed8(undefined2 *param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  
  *param_1 = 0;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  iVar1 = FUN_400ebc28(param_1,0,1);
  if (iVar1 != 0) {
    **(byte **)(param_1 + 2) = param_3 | **(byte **)(param_1 + 2);
  }
  *(bool *)param_2 = iVar1 == 0;
  return;
}

