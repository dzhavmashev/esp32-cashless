// Function : FUN_4016f56c
// Address  : 0x4016f56c
// Size     : 126 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4016f56c(void)

{
  undefined2 local_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  
  FUN_4016e310();
  FUN_4018f6a0(0);
  FUN_4016e344();
  FUN_4018fc24();
  if ((DAT_3ffc7e6d == '\0') || (DAT_3ffc7e6f == '\0')) {
    (**(code **)(_DAT_3ffc7e64 + 0xc0))();
    local_30 = _DAT_3ffc3ad8;
    uStack_2e = _DAT_3ffc3ada;
    uStack_2c = _DAT_3ffc3adc;
    uStack_2a = _DAT_3ffc3ade;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xdc))(&local_30);
    (**(code **)(_DAT_3ffc7e64 + 0xd4))();
    (**(code **)(_DAT_3ffc7e64 + 0xcc))();
    (**(code **)(_DAT_3ffc7e64 + 0xc4))();
  }
  FUN_4016f4c8(2,4);
  return;
}

