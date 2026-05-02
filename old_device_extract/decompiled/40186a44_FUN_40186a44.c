// Function : FUN_40186a44
// Address  : 0x40186a44
// Size     : 49 bytes


undefined4 FUN_40186a44(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  *param_2 = *param_1;
  *(undefined1 *)(param_2 + 1) = *(undefined1 *)(param_1 + 1);
  memw();
  *(undefined2 *)((int)param_2 + 6) = *(undefined2 *)((int)param_1 + 6);
  memw();
  param_2[2] = param_1[9];
  param_2[3] = param_1[0xd];
  uVar1 = param_1[0x14];
  param_2[4] = param_1[0xf];
  param_2[5] = uVar1;
  memw();
  return 0;
}

