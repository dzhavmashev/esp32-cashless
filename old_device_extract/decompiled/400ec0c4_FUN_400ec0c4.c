// Function : FUN_400ec0c4
// Address  : 0x400ec0c4
// Size     : 46 bytes


void FUN_400ec0c4(undefined2 *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  undefined4 uStack_28;
  undefined1 uStack_24;
  
  *param_1 = param_3;
  *(undefined4 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0;
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  uStack_28 = param_4;
  uStack_24 = param_5;
  FUN_400ec030(param_1,param_2,&uStack_28,1);
  return;
}

