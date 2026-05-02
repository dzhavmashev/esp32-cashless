// Function : FUN_4011b0cc
// Address  : 0x4011b0cc
// Size     : 103 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_4011b0cc(int param_1)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 == 3) {
    if (_DAT_3ffc6510 != 0) {
      (*(code *)&SUB_40094c54)("e mutex",0x241,"== NULL","memory\n");
    }
    _DAT_3ffc6510 = (*(code *)&SUB_40091388)();
    bVar1 = true;
    memw();
  }
  else if (param_1 == 4) {
    bVar1 = _DAT_3ffc6510 != 0;
  }
  else if (param_1 == 0) {
    bVar1 = true;
    if (_DAT_3ffc6510 != 0) {
      iVar2 = (*(code *)&SUB_40091388)();
      bVar1 = true;
      if (_DAT_3ffc6510 != iVar2) {
        bVar1 = false;
      }
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

