// Function : FUN_40184b80
// Address  : 0x40184b80
// Size     : 44 bytes


undefined4 FUN_40184b80(int param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  if (param_2 < 0x7e) {
    *param_3 = *(uint *)(param_1 + (param_2 >> 4) * 4) >> ((param_2 & 0xf) << 1) & 3;
    uVar1 = 0;
  }
  memw();
  return uVar1;
}

