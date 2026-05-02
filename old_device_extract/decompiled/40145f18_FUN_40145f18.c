// Function : FUN_40145f18
// Address  : 0x40145f18
// Size     : 240 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_40145f18(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  if (_DAT_3ffc1a10 == 0) {
    if (_DAT_3ffc1a14 != 0) {
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc1980,uVar1,"_core.c",0x1ba);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (_DAT_3ffc1a18 != 0) {
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc1974,uVar1,"_core.c",0x1bb);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar1 = 0x103;
  }
  else {
    if ((_DAT_3ffc1a14 == 0) || (_DAT_3ffc1a18 == 0)) {
      uVar1 = (**(code **)(_DAT_3ffc17c4 + 0x4c))();
      FUN_40168698(0x3ffc198c,uVar1,"_core.c",0x1b9);
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar1 = (**(code **)(_DAT_3ffc17c4 + 0xc))();
    iVar2 = _DAT_3ffc1a1c;
    while (iVar2 != 0) {
      iVar3 = *(int *)(iVar2 + 4);
      memw();
      (*(code *)&SUB_40087890)(iVar2);
      iVar2 = iVar3;
    }
    (**(code **)(_DAT_3ffc17c4 + 0x10))(_DAT_3ffc1a10,uVar1);
    if (_DAT_3ffc1a18 != 0) {
      (**(code **)(_DAT_3ffc17c4 + 0x38))();
      _DAT_3ffc1a18 = 0;
    }
    if (_DAT_3ffc1a14 != 0) {
      memw();
      (**(code **)(_DAT_3ffc17c4 + 8))();
      _DAT_3ffc1a14 = 0;
    }
    uVar1 = 0;
    if (_DAT_3ffc1a10 != 0) {
      memw();
      (**(code **)(_DAT_3ffc17c4 + 8))();
      _DAT_3ffc1a10 = 0;
      memw();
      return 0;
    }
  }
  return uVar1;
}

