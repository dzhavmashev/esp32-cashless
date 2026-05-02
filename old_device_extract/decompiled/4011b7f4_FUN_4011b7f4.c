// Function : FUN_4011b7f4
// Address  : 0x4011b7f4
// Size     : 24 bytes


undefined4 FUN_4011b7f4(uint param_1)

{
  undefined4 uVar1;
  
  param_1 = param_1 & 0xffff;
  uVar1 = FUN_4010bbc4(0x4a,(uint)(param_1 < 0x224) * 0x224 + (param_1 >= 0x224) * param_1,0x280);
  return uVar1;
}

