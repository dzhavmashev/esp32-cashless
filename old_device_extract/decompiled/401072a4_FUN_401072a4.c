// Function : FUN_401072a4
// Address  : 0x401072a4
// Size     : 36 bytes


undefined4 FUN_401072a4(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int local_30 [12];
  
  *(undefined4 *)(param_2 + 4) = param_1;
  local_30[1] = 0x401072e4;
  local_30[2] = 0x401072cc;
  local_30[3] = 0x401072c0;
  memw();
  local_30[0] = param_2;
  uVar1 = FUN_4010151c(param_1,local_30);
  return uVar1;
}

