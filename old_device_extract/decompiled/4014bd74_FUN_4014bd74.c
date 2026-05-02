// Function : FUN_4014bd74
// Address  : 0x4014bd74
// Size     : 52 bytes


undefined4 FUN_4014bd74(undefined1 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0xdd;
  param_1[1] = 0x1e;
  param_1[2] = 0;
  param_1[3] = 0x90;
  param_1[4] = 0x4c;
  param_1[5] = 0x33;
  memw();
  memw();
  uVar1 = FUN_4014a350(param_1 + 6,param_2);
  return uVar1;
}

