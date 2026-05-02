// Function : FUN_4015c3d8
// Address  : 0x4015c3d8
// Size     : 173 bytes


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_4015c3d8(undefined4 *param_1,undefined4 param_2)

{
  if (param_1 == (undefined4 *)0x0) {
    FUN_40147fe4(1,4,1,"");
    return;
  }
  (*(code *)&SUB_4008b530)(param_1,0,0x3a8);
  *param_1 = param_2;
  *(undefined2 *)((int)param_1 + 0xae) = 0;
  *(undefined2 *)((int)param_1 + 0xd2) = 0xfff0;
  *(undefined1 *)((int)param_1 + 0xf6) = 1;
  memw();
  if (_DAT_3ffc7aee == 0) {
    memw();
    _DAT_3ffc7aee = (**(code **)(_DAT_3ffc1a34 + 0x14c))();
    _DAT_3ffc7aee = _DAT_3ffc7aee & 0xfff;
    *(ushort *)((int)param_1 + 0xce) = _DAT_3ffc7aee;
    memw();
    memw();
  }
  else {
    *(ushort *)((int)param_1 + 0xce) = _DAT_3ffc7aee + 0x800 & 0xfff;
    _DAT_3ffc7aee = 0;
    memw();
  }
  *(undefined1 *)(param_1 + 0xd0) = *(undefined1 *)(_DAT_3ffbfc54 + 0x49a);
  memw();
  memw();
  FUN_40147fe4(1,4,5,0x3f4362d6);
  return;
}

