// Function : FUN_40131d74
// Address  : 0x40131d74
// Size     : 42 bytes


undefined4 FUN_40131d74(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  
  puStack_24 = (undefined1 *)&local_30;
  local_30 = param_3;
  if (param_3 < 1) {
    local_30 = -param_3;
  }
  uStack_2c = 0xffffffff;
  if (-1 < param_3) {
    uStack_2c = 1;
  }
  uStack_28 = 1;
  memw();
  uVar1 = FUN_40131d30(param_1,param_2,&uStack_2c);
  return uVar1;
}

