// Function : FUN_4018ddf8
// Address  : 0x4018ddf8
// Size     : 47 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4018ddf8(int param_1)

{
  undefined4 uVar1;
  
  if (_DAT_3ffc56f4 == param_1) {
    uVar1 = 0x103;
  }
  else if (_DAT_3ffc56f4 == 0) {
    uVar1 = 0;
    _DAT_3ffc56f4 = param_1;
  }
  else {
    uVar1 = 0x101;
  }
  memw();
  return uVar1;
}

