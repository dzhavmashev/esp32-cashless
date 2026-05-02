// Function : FUN_400ec284
// Address  : 0x400ec284
// Size     : 36 bytes


undefined4 FUN_400ec284(int *param_1)

{
  *(undefined1 *)((int)param_1 + 0x1a) = *(undefined1 *)(*param_1 + param_1[2]);
  *(undefined1 *)((int)param_1 + 0x19) = 0;
  param_1[4] = 0x400ec2a0;
  return 0;
}

