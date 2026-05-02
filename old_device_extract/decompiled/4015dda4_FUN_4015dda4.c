// Function : FUN_4015dda4
// Address  : 0x4015dda4
// Size     : 633 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015dda4(int param_1,int param_2)

{
  int iVar1;
  
  if (*(short *)(param_2 + 0x26) != 0) {
    FUN_4015dcd0(0,param_2);
    FUN_4015d8cc(0,param_2);
  }
  FUN_40147fe4(1,4,4,0x3f4344e7);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffc7af4);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(0x3ffc7af4);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(0x3ffc7a74);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(0x3ffc7a74);
  DAT_3ffc89d7 = 0;
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x2c);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(param_1 + 0x2c);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x40);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(param_1 + 0x40);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(param_2 + 0x2cc);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(param_2 + 0x2cc);
  (**(code **)(_DAT_3ffc1a34 + 0xec))(param_1 + 0x54);
  (**(code **)(_DAT_3ffc1a34 + 0xf0))(param_1 + 0x54);
  if ((DAT_3ffc89ed < 0xe) && ((1 << (DAT_3ffc89ed & 0x1f) & 0x2410U) != 0)) {
    if ((_DAT_3ffc89a8 != 0) && (*(code **)(_DAT_3ffc89a8 + 0x10) != (code *)0x0)) {
      (**(code **)(_DAT_3ffc89a8 + 0x10))();
    }
    _DAT_3ffc8a30 = 0;
  }
  if ((_DAT_3ffc8a64 != 0) && (*(code **)(_DAT_3ffc8a64 + 0x10) != (code *)0x0)) {
    memw();
    (**(code **)(_DAT_3ffc8a64 + 0x10))(&DAT_3f4239bb);
  }
  FUN_4014b430(param_2);
  if ((*(char *)(_DAT_3ffc8800 + 0x154) != '\x06') || (_DAT_3ffc89f4 == 0)) {
    FUN_4015fde8(0,_DAT_3ffc89b8);
    (**(code **)(_DAT_3ffc1a34 + 0xb0))
              (*(undefined4 *)(&DAT_3ffc8930 + (uint)*(byte *)(param_2 + 0x134) * 4));
    *(undefined4 *)(&DAT_3ffc87f0 + (*(byte *)(param_2 + 0x134) + 0x50) * 4) = 0;
    if (_DAT_3ffc8930 != 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      _DAT_3ffc8930 = 0;
    }
    if (_DAT_3ffc8934 != 0) {
      memw();
      (**(code **)(_DAT_3ffc1a34 + 0xb0))();
      _DAT_3ffc8934 = 0;
    }
  }
  _DAT_3ffc91f8 = 2;
  if ((*(byte *)(param_2 + 10) & 2) != 0) {
    *(byte *)(param_2 + 10) = *(byte *)(param_2 + 10) & 0xfd;
    memw();
    memw();
    FUN_4015d4e8(param_2,0xfffffff9,1);
    _DAT_3ffca0bc = param_2;
  }
  DAT_3ffc7ae9 = 0;
  memw();
  if ((((_DAT_3ffc8864 != 0) && (memw(), DAT_3ffc1a3c == '\0')) && (memw(), DAT_3ffbfc50 != '\0'))
     && (*(char *)(_DAT_3ffbfc54 + 0x92) != '\0')) {
    memw();
    iVar1 = (*(code *)&SUB_4008b33c)(_DAT_3ffbfc54 + 0x93,param_2 + 4,6);
    if (iVar1 == 0) goto LAB_4015dfbd;
  }
  FUN_40147fe4(1,4,5,0x3f4362ba,*(undefined1 *)(param_2 + 0x340));
  if (*(char *)(param_2 + 0x340) == '\0') {
    FUN_4015cd08(param_2);
  }
  else {
    *(char *)(param_2 + 0x340) = *(char *)(param_2 + 0x340) + -1;
    memw();
    memw();
    FUN_4015c4bc(param_2 + 4);
  }
  _DAT_3ffca0b8 = 0;
LAB_4015dfbd:
  *(uint *)(param_2 + 0xc) = *(uint *)(param_2 + 0xc) & 0xfffffffe;
  DAT_3ffc1a45 = 0;
  memw();
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x54))(_DAT_3ffc799c);
  *(undefined4 *)(param_1 + 0xe4) = 0;
  memw();
  (**(code **)(_DAT_3ffc1a34 + 0x58))(_DAT_3ffc799c);
  FUN_40154e0c();
  FUN_4014b690(0);
  DAT_3ffc7aea = 0;
  memw();
  memw();
  FUN_40147fe4(1,0xc,4,0x3f4344ce,8);
  FUN_4015a448(8);
  return;
}

