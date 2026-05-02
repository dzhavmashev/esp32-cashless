// Function : FUN_40158644
// Address  : 0x40158644
// Size     : 71 bytes


uint FUN_40158644(uint param_1)

{
  byte local_30 [48];
  
  param_1 = param_1 & 0xff;
  local_30[0] = 0xc9;
  memw();
  local_30[1] = 0x81;
  local_30[2] = 0x15;
  local_30[3] = 0x40;
  memw();
  if (3 < param_1) {
    memw();
    FUN_40147fe4(1,0x20,1,"",param_1);
    return param_1;
  }
  return (uint)local_30[param_1];
}

