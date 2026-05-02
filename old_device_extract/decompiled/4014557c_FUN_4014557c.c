// Function : FUN_4014557c
// Address  : 0x4014557c
// Size     : 160 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_4014557c(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(_DAT_3ffc17c4 + 0x30))();
  if (iVar1 != 0) {
    uVar2 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
    FUN_40168698(0x3ffc17c8,uVar2,"1fd20f4",0x259);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = (*(code *)&SUB_40086fec)();
  if (iVar1 == 0) {
    DAT_3ffc78e0 = DAT_3ffc78e0 + -1;
    memw();
    if (DAT_3ffc78e0 != '\0') {
      memw();
      _DAT_3ffc1910 = iVar1;
      (*(code *)&SUB_4008783c)();
      (*(code *)&SUB_400877f0)();
      if ((_DAT_3ffc1904 != (char *)0x0) && (*_DAT_3ffc1904 == '\x01')) {
        (*(code *)&SUB_40087710)();
      }
      FUN_40145e14();
      FUN_40145f18();
      if (_DAT_3ffc1900 != 0) {
        (**(code **)(_DAT_3ffc17c4 + 8))();
        _DAT_3ffc1900 = 0;
        memw();
      }
    }
    memw();
    (*(code *)&SUB_40087048)();
    return 0;
  }
  return 0xffffffff;
}

