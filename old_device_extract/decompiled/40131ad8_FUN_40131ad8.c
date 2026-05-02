// Function : FUN_40131ad8
// Address  : 0x40131ad8
// Size     : 40 bytes


undefined4 FUN_40131ad8(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  
  puStack_24 = (undefined1 *)&local_30;
  local_30 = param_2;
  if (param_2 < 1) {
    local_30 = -param_2;
  }
  uStack_2c = 0xffffffff;
  if (-1 < param_2) {
    uStack_2c = 1;
  }
  uStack_28 = 1;
  memw();
  uVar1 = FUN_401860ec(param_1,&uStack_2c);
  return uVar1;
}

