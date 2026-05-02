// Function : FUN_40184b58
// Address  : 0x40184b58
// Size     : 39 bytes


undefined4 FUN_40184b58(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 < 0x7e) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x50) + 0x10))
                      (*(int **)(param_1 + 0x50),param_2 * 0x20 + 0x40 + *(int *)(param_1 + 8),
                       param_3,0x20);
  }
  return uVar1;
}

