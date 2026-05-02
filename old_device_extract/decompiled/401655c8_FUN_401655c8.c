// Function : FUN_401655c8
// Address  : 0x401655c8
// Size     : 103 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_401655c8(char param_1)

{
  if (param_1 == '\0') {
    if (_DAT_3ffc1bb8 != 0) {
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      _DAT_3ffc1bb8 = 0;
    }
    memw();
    return 0;
  }
  if (_DAT_3ffc1bb8 != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
  }
  _DAT_3ffc1bb8 = (**(code **)(_DAT_3ffc1a34 + 0x15c))(0x23c);
  if (_DAT_3ffc1bb8 == 0) {
    memw();
    FUN_40147fe4(6,0x800,1," %s %u\n");
    return 0x101;
  }
  (*(code *)&SUB_4008b530)(_DAT_3ffc1bb8,0,0x23c);
  return 0;
}

