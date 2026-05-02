// Function : FUN_4014659c
// Address  : 0x4014659c
// Size     : 53 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014659c(void)

{
  _DAT_3ffc87ec = (**(code **)(_DAT_3ffc1a34 + 0x164))(1,0x20);
  if (_DAT_3ffc87ec == 0) {
    memw();
    FUN_40147fe4(6,1,1,"ot stop");
    return 0x101;
  }
  FUN_40146560();
  return 0;
}

