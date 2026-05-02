// Function : FUN_4015b6ac
// Address  : 0x4015b6ac
// Size     : 557 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015b6ac(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_30;
  
  uStack_40 = 0;
  uStack_3c = 0;
  memw();
  FUN_4015b0e0();
  memw();
  FUN_40147fe4(1,4,4,0x3f4346fc,param_2,DAT_3ffc89ed,DAT_3ffc89ee);
  if (param_2 != 0) {
    return;
  }
  FUN_4015fdf8(0);
  FUN_4015fdf8(1);
  FUN_4015fdf8(4);
  FUN_4015fdf8(5);
  if (*(int *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) != 0) {
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
    *(undefined4 *)(&DAT_3ffc8930 + (uint)*(byte *)(param_1 + 0x134) * 4) = 0;
  }
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
  if (_DAT_3ffc8944 != 0) {
    memw();
    (**(code **)(_DAT_3ffc1a34 + 0xb0))();
    _DAT_3ffc8944 = 0;
  }
  DAT_3ffc89f7 = 0;
  memw();
  DAT_3ffc89ed = *(char *)(param_1 + 0x29d);
  memw();
  DAT_3ffc89ec = *(undefined1 *)(param_1 + 0x29c);
  memw();
  DAT_3ffc89ee = *(char *)(param_1 + 0x29e);
  memw();
  DAT_3ffc89f0 = *(undefined1 *)(param_1 + 0x2a0);
  memw();
  _DAT_3ffc89f4 = *(undefined2 *)(param_1 + 0x2a4);
  DAT_3ffc89f6 = *(undefined1 *)(param_1 + 0x2a6);
  memw();
  DAT_3ffc8a69 = *(undefined1 *)(param_1 + 0x382);
  memw();
  memw();
  if ((_DAT_3ffc89a4 != 0) && (iVar1 = (**(code **)(_DAT_3ffc89a4 + 8))(param_1 + 4), iVar1 < 0)) {
    return;
  }
  if (DAT_3ffc89ed == '\x01') {
    memw();
    if (DAT_3ffc89ee == '\a') {
      memw();
      FUN_4015a720(1,param_1 + 4,0,1,&uStack_40,8,0x3ffc89dc,5,4);
      memw();
      FUN_4015a720(1,param_1 + 4,1,1,&uStack_40,8,0x3ffc89dc,5,5);
      *(undefined1 *)(param_1 + 0x135) = 4;
      memw();
      memw();
    }
    else if (DAT_3ffc89ee == '\b') {
      uStack_30 = 0xd;
      memw();
      FUN_4015a720(5,param_1 + 4,0,1,&uStack_40,8,0x3ffc89dc,0xd,4);
      memw();
      FUN_4015a720(5,param_1 + 4,1,1,&uStack_40,8,0x3ffc89dc,uStack_30,5);
      *(undefined1 *)(param_1 + 0x135) = 4;
      memw();
    }
  }
  else {
    FUN_40147fe4(1,4,4,0x3f4346e6);
    if ((_DAT_3ffc8a64 != 0) && (*(code **)(_DAT_3ffc8a64 + 0x10) != (code *)0x0)) {
      (**(code **)(_DAT_3ffc8a64 + 0x10))(param_1 + 4);
    }
    *(undefined1 *)(param_1 + 0x135) = 0xff;
    *(undefined1 *)(param_1 + 0x137) = 0xff;
    *(undefined1 *)(param_1 + 0x138) = 0xff;
    *(undefined1 *)(param_1 + 0x139) = 0xff;
    *(undefined1 *)(param_1 + 0x13a) = 0xff;
    memw();
    memw();
  }
  memw();
  FUN_40155a3c();
  uVar2 = 0;
  if ((_DAT_3ffca0bc == 0) ||
     (((*(int *)(_DAT_3ffca0bc + 4) == 0 && (uVar2 = 0, *(short *)(_DAT_3ffca0bc + 8) == 0)) ||
      (uVar2 = 1, DAT_3ffca0c8 == '\0')))) {
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  FUN_40154c6c(param_1,uVar2,uVar3);
  return;
}

