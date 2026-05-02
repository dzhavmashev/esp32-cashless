// Function : FUN_4017c0dc
// Address  : 0x4017c0dc
// Size     : 36 bytes


uint FUN_4017c0dc(undefined4 param_1,ushort *param_2,byte *param_3,int param_4)

{
  uint uVar1;
  ushort local_30 [24];
  
  if (param_2 == (ushort *)0x0) {
    param_2 = local_30;
  }
  uVar1 = 0;
  if ((param_3 != (byte *)0x0) && (uVar1 = 0xfffffffe, param_4 != 0)) {
    *param_2 = (ushort)*param_3;
    uVar1 = (uint)(*param_3 != 0);
  }
  return uVar1;
}

