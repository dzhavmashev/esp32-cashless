// Function : FUN_4011fae0
// Address  : 0x4011fae0
// Size     : 267 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_4011fae0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  memw();
  _DAT_3ffc6740 = param_1;
  iVar1 = FUN_4011eb44(0x11,0xc02,0x40085b94,0,&DAT_3ffc6744);
  if (iVar1 == 0) {
    memw();
    _DAT_3ff5f098 = _DAT_3ff5f098 | 8;
    memw();
    memw();
    iVar1 = (*(code *)&SUB_400842d0)();
    (*(code *)&SUB_40085d14)(iVar1 / 1000000);
    iVar1 = FUN_4011e56c();
    memw();
    _DAT_3ff5f074 = iVar1 << 7 | _DAT_3ff5f074 & 0x3f;
    memw();
    memw();
    iVar3 = (*(code *)&SUB_40084424)(_DAT_3ffc6744);
    iVar1 = 0;
    if (iVar3 != 0) {
      (*(code *)&SUB_4008effc)(iVar3,"o low\"",0xff,"handle)","0x%0x)\n");
      iVar1 = (*(code *)&SUB_4008fc58)(1,0x3ffc6bb4);
      if (iVar1 == 0x3ffc6bb4) goto LAB_4011fbb8;
      pcVar4 = "id *)0)";
      uVar2 = 0x174;
      while( true ) {
        (*(code *)&SUB_40094c54)("/newlib/locks.c",uVar2,"e_mutex",pcVar4);
LAB_4011fbb8:
        iVar3 = (*(code *)&SUB_4008fc58)(4,0x3ffc6b60);
        if (iVar3 == 0x3ffc6b60) break;
        pcVar4 = "n_mutex";
        uVar2 = 0x176;
      }
      _DAT_3ffae0ac = iVar3;
      _DAT_3ffae0a8 = iVar3;
      _DAT_3ffae0b8 = iVar3;
      _DAT_3ffae080 = iVar1;
      memw();
      return iVar1;
    }
  }
  else if (_DAT_3ffbe0e8 != 0) {
    uVar2 = (*(code *)&SUB_40094b80)();
    (*(code *)&SUB_40007d54)("er_impl",uVar2,"PER_US\"",iVar1);
  }
  return iVar1;
}

