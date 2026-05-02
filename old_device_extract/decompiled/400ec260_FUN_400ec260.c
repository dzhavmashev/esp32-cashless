// Function : FUN_400ec260
// Address  : 0x400ec260
// Size     : 33 bytes


undefined4 FUN_400ec260(int *param_1)

{
  *(ushort *)(param_1 + 0x27) =
       (ushort)*(byte *)(*param_1 + param_1[2]) << 8 | *(ushort *)(param_1 + 0x27);
  param_1[4] = 0x400ec3c8;
  return 0;
}

