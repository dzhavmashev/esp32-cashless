// Function : FUN_400e818c
// Address  : 0x400e818c
// Size     : 32 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_400e818c(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (_DAT_3ffc5180 != 0) {
    uVar1 = func_0x4008f3f8(_DAT_3ffc5180,param_1,0,1,param_2);
    uVar1 = param_1 & uVar1;
  }
  return uVar1;
}

