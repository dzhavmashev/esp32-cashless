// Function : FUN_401899f4
// Address  : 0x401899f4
// Size     : 132 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_401899f4(void)

{
  if (DAT_3ffc7d64 != '\0') {
    DAT_3ffc7d64 = 0;
    memw();
    memw();
    return;
  }
  if (DAT_3ffc7d65 != '\0') {
    DAT_3ffc7d65 = DAT_3ffc7d64;
    memw();
    if (_DAT_3ffc7d68 != 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0x10c))();
      memw();
      _DAT_3ff73c04 = _DAT_3ff73c04 | 0xf0;
      memw();
      memw();
      _DAT_3ff73084 = _DAT_3ff73084 & 0x7fffffff;
      memw();
      memw();
      FUN_40189908(_DAT_3ffc7d68);
      FUN_40166934(_DAT_3ffc7d6c,_DAT_3ffc7d70);
      FUN_401899c4();
      memw();
      _DAT_3ff73084 = _DAT_3ff73084 | 0x80000000;
      memw();
    }
  }
  memw();
  return;
}

