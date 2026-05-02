// Function : FUN_40145488
// Address  : 0x40145488
// Size     : 225 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_40145488(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_DAT_3ffc17c4 + 0x30))();
  if (iVar1 != 0) {
    uVar2 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    FUN_40168698(0x3ffc17f6,uVar2,"1fd20f4",0x21c);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = (*(code *)&SUB_40086fec)();
  if (iVar1 != 0) {
    return -1;
  }
  DAT_3ffc78e0 = DAT_3ffc78e0 + '\x01';
  memw();
  if (DAT_3ffc78e0 != '\x02') {
    memw();
LAB_4014552c:
    memw();
    (*(code *)&SUB_40087048)();
    return 0;
  }
  iVar1 = FUN_40145390();
  if (iVar1 == 0) {
    (*(code *)&SUB_40094bc8)();
  }
  iVar1 = FUN_40145ddc();
  if ((iVar1 == 0) && (iVar1 = FUN_40145e50(), iVar1 == 0)) {
    memw();
    _DAT_3ffc1904 = iVar1;
    _DAT_3ffc1908 = iVar1;
    _DAT_3ffc1900 = (**(code **)(_DAT_3ffc17c4 + 4))();
    if (_DAT_3ffc1900 != 0) {
      _DAT_3ffc1910 = 1;
      goto LAB_4014552c;
    }
    memw();
    uVar2 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    FUN_40168698(0x3ffc17d4,uVar2);
    iVar1 = 0x101;
  }
  FUN_40145e14();
  FUN_40145f18();
  if (_DAT_3ffc1900 != 0) {
    (**(code **)(_DAT_3ffc17c4 + 8))();
    _DAT_3ffc1900 = 0;
  }
  DAT_3ffc78e0 = DAT_3ffc78e0 + -1;
  memw();
  memw();
  (*(code *)&SUB_40087048)();
  return iVar1;
}

