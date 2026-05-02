// Function : FUN_400e1028
// Address  : 0x400e1028
// Size     : 46 bytes


byte FUN_400e1028(int param_1,undefined4 *param_2)

{
  FUN_40184150(param_1);
  *(byte *)(param_1 + 0x20) = *(byte *)(param_1 + 0x20) & 0x80;
  FUN_400e1000(param_1 + 0x18,*param_2,param_1);
  return *(byte *)(param_1 + 0x10) ^ 1;
}

