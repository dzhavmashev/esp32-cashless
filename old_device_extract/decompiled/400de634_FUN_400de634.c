// Function : FUN_400de634
// Address  : 0x400de634
// Size     : 48 bytes


undefined2 FUN_400de634(int param_1,char *param_2)

{
  undefined2 auStack_22 [17];
  
  func_0x4008fecc(*(undefined4 *)(param_1 + 0xa0),auStack_22,0xffffffff);
  if (param_2 != (char *)0x0) {
    *param_2 = *param_2 + (char)auStack_22[0];
  }
  memw();
  memw();
  *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
  return auStack_22[0];
}

