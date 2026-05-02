// Function : FUN_40169c58
// Address  : 0x40169c58
// Size     : 550 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_40169c58(char param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined1 param_6)

{
  ushort uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if (param_1 == '\0') {
    _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
    _DAT_3ff460a0 = _DAT_3ff460a0 | 0x4000;
    memw();
    _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
    _DAT_3ff460a0 = _DAT_3ff460a0 | 0x8000;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xc0))();
    (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
    if ((_DAT_3ffca4c8 & 0x400) == 0) {
      FUN_401691b0(0,0x80,0x3ffca500,0);
      _DAT_3ffca4c8 = _DAT_3ffca4c8 | 0x400;
    }
    _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
    _DAT_3ff450dc = _DAT_3ff450dc & 0xf7ffffff;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
    FUN_401696b4(0,0,3,param_3,&DAT_3ffca440,&DAT_3ffca430,0x3ffca490,param_6,4,0xe);
    _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
    _DAT_3ff460a0 = _DAT_3ff460a0 & 0xffff7fff;
    memw();
    (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
    (**(code **)(_DAT_3ffc7e64 + 0xc4))();
    return;
  }
  uVar2 = (**(code **)(_DAT_3ffc7e64 + 0xa4))(0x67,1,0xf,2,0);
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,0xf,2,0);
  _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
  _DAT_3ff460a0 = _DAT_3ff460a0 | 0x4000;
  memw();
  _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
  _DAT_3ff460a0 = _DAT_3ff460a0 | 0x8000;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0xc0))();
  (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
  pcVar3 = *(code **)(_DAT_3ffc7e64 + 0xb8);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
  (*pcVar3)(1,1,uVar1 | 2);
  _DAT_3ff450dc = (*(code *)&SUB_40084594)(&DAT_3ff450dc);
  _DAT_3ff450dc = _DAT_3ff450dc & 0xf7ffffff;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
  pcVar3 = *(code **)(_DAT_3ffc7e64 + 0xb8);
  uVar1 = (**(code **)(_DAT_3ffc7e64 + 0xbc))(1);
  (*pcVar3)(1,1,uVar1 | 2);
  FUN_401696b4(1,0,1,param_3,&DAT_3ffca440,&DAT_3ffca430,0x3ffca490,param_6,0,0);
  _DAT_3ff460a0 = (*(code *)&SUB_40084594)(&DAT_3ff460a0);
  _DAT_3ff460a0 = _DAT_3ff460a0 & 0xffff7fff;
  memw();
  (**(code **)(_DAT_3ffc7e64 + 0xd0))(0);
  (**(code **)(_DAT_3ffc7e64 + 0xc4))();
  (**(code **)(_DAT_3ffc7e64 + 0xa8))(0x67,1,0xf,2,0,uVar2);
  return;
}

